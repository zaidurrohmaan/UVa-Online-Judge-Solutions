#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int N, Q, mx = 100001;
string query;
vi A(mx), st(4*mx);

int l(int p) { return p<<1; }
int r(int p) { return (p<<1) + 1; }

void build(int p, int L, int R) {
    if (L == R) st[p] = A[L];
    else {
        int mid = (L+R)/2;
        build(l(p), L, mid);
        build(r(p), mid+1, R);
        st[p] = min(st[l(p)],st[r(p)]);
    }
}

int RMQ(int p, int L, int R, int i, int j) {
    if (i > R || j < L) return 100001;
    if (i <= L && R <= j) return st[p];
    int mid = (L+R)/2;
    return min(RMQ(l(p), L, mid, i, j), RMQ(r(p), mid+1, R, i, j));
}

void point_update(int p, int L, int R, int idx, int val) {
    if (idx < L || idx > R) return;
    if (L == R) st[p] = val;
    else {
        int mid = (L+R)/2;
        point_update(l(p), L, mid, idx, val);
        point_update(r(p), mid+1, R, idx, val);
        st[p] = min(st[l(p)], st[r(p)]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> A[i];
    build(1, 0, N-1);

    cin.ignore();
    while(Q--) {
        getline(cin, query);
        if (query[0] == 'q') {
            int i;
            for (i = 0; query[i] != '('; i++) {}
            i++;
            int a = 0;
            while(query[i] != ',') {
                a *= 10;
                a += query[i] - '0';
                i++;
            }
            i++;
            int b = 0;
            while(query[i] != ')') {
                b *= 10;
                b += query[i] - '0';
                i++;
            }
            printf("%d\n", RMQ(1, 0, N-1, a-1, b-1));
        } else {
            int i;
            for (i = 0; query[i] != '('; i++) {};
            i++;
            vector<int> V;
            int a = 0;
            while(1) {
                if (query[i] == ',') {
                    V.push_back(a-1); // 0-indexed
                    a = 0;
                } else if (query[i] == ')'){
                    V.push_back(a-1); // 0-indexed
                    break;
                } else {
                    a *= 10;
                    a += query[i] - '0';
                }
                i++;
            }
            
            int front = A[V[0]];
            for (i = 0; i < (int) V.size() - 1; i++) {
                point_update(1, 0, N-1, V[i], A[V[i+1]]);
                A[V[i]] = A[V[i+1]];
            }
            point_update(1, 0, N-1, V.back(), front);
            A[V.back()] = front;
        }
    }
}
