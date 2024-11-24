#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int M, T, Q, mx = 1048576;
string S;
vi A(mx), st(4*mx), lazy(4*mx);

int l(int p) { return p<<1; }
int r(int p) { return (p<<1) + 1; }

void build(int p, int L, int R) {
    lazy[p] = 0;
    if (L == R) st[p] = A[L];
    else {
        int mid = (L+R)/2;
        build(l(p), L, mid);
        build(r(p), mid+1, R);
        st[p] = st[l(p)] + st[r(p)];
    }
}

int inverseFlag(int flag) {
    switch(flag) {
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 0;
        default:
            return 3;
    }
}

void propagate(int p, int L, int R) {
    if (lazy[p]) {
        switch(lazy[p]) {
            case 1: 
                st[p] = R-L+1; // A[L..R] = {1}
                break;
            case 2: 
                st[p] = 0; // A[L..R] = {0}
                break;
            default:
                st[p] = R-L+1-st[p]; // inverse A[L..R]
        }

        if (L != R) {
            if (lazy[p] <= 2) {
                lazy[l(p)] = lazy[p];
                lazy[r(p)] = lazy[p];
            } else {
                lazy[l(p)] = inverseFlag(lazy[l(p)]);
                lazy[r(p)] = inverseFlag(lazy[r(p)]);
            }
        }
        lazy[p] = 0;
    }
}

void toBucanner(int p, int L, int R, int i, int j) {
    propagate(p, L, R);
    if (i > R || j < L) return;
    if (i <= L && R <= j) {
        st[p] = R-L+1;
        lazy[l(p)] = 1;
        lazy[r(p)] = 1;
        return;
    }

    int mid = (L+R)/2;
    toBucanner(l(p), L, mid, i, j);
    toBucanner(r(p), mid+1, R, i, j);

    st[p] = st[l(p)] + st[r(p)];
}

void toBarbary(int p, int L, int R, int i, int j) {
    propagate(p, L, R);
    if (i > R || j < L) return;
    if (i <= L && R <= j) {
        st[p] = 0;
        lazy[l(p)] = 2;
        lazy[r(p)] = 2;
        return;
    }

    int mid = (L+R)/2;
    toBarbary(l(p), L, mid, i, j);
    toBarbary(r(p), mid+1, R, i, j);

    st[p] = st[l(p)] + st[r(p)];
}

void inverse(int p, int L, int R, int i, int j) {
    propagate(p, L, R);
    if (i > R || j < L) return;
    if (i <= L && R <= j) {
        st[p] = R-L+1-st[p];
        lazy[l(p)] = inverseFlag(lazy[l(p)]);
        lazy[r(p)] = inverseFlag(lazy[r(p)]);
        return;
    }

    int mid = (L+R)/2;
    inverse(l(p), L, mid, i, j);
    inverse(r(p), mid+1, R, i, j);

    st[p] = st[l(p)] + st[r(p)];
}

int RSQ(int p, int L, int R, int i, int j) {
    propagate(p, L, R);
    if (i > R || j < L) return 0;
    if (i <= L && R <= j) return st[p];

    int mid = (L+R)/2;
    return RSQ(l(p), L, mid, i, j) + RSQ(r(p), mid+1, R, i, j);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        printf("Case %d:\n", tt);
        cin >> M;
        int N = 0;
        for (int i = 0; i < M; i++) {
            cin >> T >> S;
            while(T--) for (char c : S) A[N++] = (c - '0');
        }
        build(1, 0, N-1);
        
        cin >> Q;
        int qq = 1;
        while(Q--) {
            int a, b;
            char action;
            cin >> action >> a >> b;
            
            if (action == 'F') toBucanner(1, 0, N-1, a, b);
            else if (action == 'E') toBarbary(1, 0, N-1, a, b);
            else if (action == 'I') inverse(1, 0, N-1, a, b);
            else printf("Q%d: %d\n", qq++, RSQ(1, 0, N-1, a, b));
        }
    }
}
