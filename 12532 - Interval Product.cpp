#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

const int MX = 100000;
int N, K;
char c;
vi A(MX), st(4*MX);

int l(int p) { return p<<1; }
int r(int p) { return (p<<1)+1; }

void build(int p, int L, int R) {
    if (L == R) st[p] = A[L];
    else {
        int mid = (L+R)/2;
        build(l(p), L, mid);
        build(r(p), mid+1, R);
        st[p] = st[l(p)]*st[r(p)];
    }
}

int RPQ(int p, int L, int R, int i, int j) {
    if (i > R || j < L) return 1;
    if (i <= L && R <= j) return st[p];

    int mid = (L+R)/2;
    return RPQ(l(p), L, mid, i, j) * RPQ(r(p), mid+1, R, i, j);
}

void update(int p, int L, int R, int idx, int val) {
    if (idx < L || idx > R) return;
    if (L == R) st[p] = val;
    else {
        int mid = (L+R)/2;
        update(l(p), L, mid, idx, val);
        update(r(p), mid+1, R, idx, val);
        st[p] = st[l(p)]*st[r(p)];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (scanf("%d %d", &N, &K) != EOF) {

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            if (A[i]) A[i] /= abs(A[i]);
        }
        build(1, 0, N-1);

        while(K--) {
            int a, b;
            scanf(" %c %d %d", &c, &a, &b); // add space befor %c to ignore whitespace
            if (c == 'C') {
                if (b) b /= abs(b);
                update(1, 0, N-1, a-1, b);
            } else {
                int res = RPQ(1, 0, N-1, a-1, b-1);
                if (res > 0) printf("+");
                else if (res < 0) printf("-");
                else printf("0");
            }
        }
        printf("\n");
    }
}
