#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, Q;
char c;
int A[500], stMin[500][2000], stMax[500][2000], X1, Y1, X2, Y2, v;

int l(int p) { return p<<1; }
int r(int p) { return (p<<1)+1; }

void buildMin(int p, int L, int R, int row) {
    if (L == R) stMin[row][p] = A[L];
    else {
        int mid = (L+R)/2;
        buildMin(l(p), L, mid, row);
        buildMin(r(p), mid+1, R, row);
        stMin[row][p] = min(stMin[row][l(p)], stMin[row][r(p)]);
    }
}

void buildMax(int p, int L, int R, int row) {
    if (L == R) stMax[row][p] = A[L];
    else {
        int mid = (L+R)/2;
        buildMax(l(p), L, mid, row);
        buildMax(r(p), mid+1, R, row);
        stMax[row][p] = max(stMax[row][l(p)], stMax[row][r(p)]);
    }
}

void updateMin(int p, int L, int R, int idx, int val, int row) {
    if (idx < L | idx > R) return;
    if (L == R) stMin[row][p] = val;
    else {
        int mid = (L+R)/2;
        updateMin(l(p), L, mid, idx, val, row);
        updateMin(r(p), mid+1, R, idx, val, row);
        stMin[row][p] = min(stMin[row][l(p)], stMin[row][r(p)]);
    }
}

void updateMax(int p, int L, int R, int idx, int val, int row) {
    if (idx < L | idx > R) return;
    if (L == R) stMax[row][p] = val;
    else {
        int mid = (L+R)/2;
        updateMax(l(p), L, mid, idx, val, row);
        updateMax(r(p), mid+1, R, idx, val, row);
        stMax[row][p] = max(stMax[row][l(p)], stMax[row][r(p)]);
    }
}

int RMnQ(int p, int L, int R, int i, int j, int row) { // Range Minimum Query
    if (i > R || j < L) return INF;
    if (i <= L && R <= j) return stMin[row][p];

    int mid = (L+R)/2;
    return min(RMnQ(l(p), L, mid, i, j, row), (RMnQ(r(p), mid+1, R, i, j, row)));
}

int RMxQ(int p, int L, int R, int i, int j, int row) { // Range Maximum Query
    if (i > R || j < L) return -1;
    if (i <= L && R <= j) return stMax[row][p];

    int mid = (L+R)/2;
    return max(RMxQ(l(p), L, mid, i, j, row), (RMxQ(r(p), mid+1, R, i, j, row)));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
    scanf("%d", &N);
  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[j]);
        }
        buildMin(1, 0, N-1, i);
        buildMax(1, 0, N-1, i);
    }
  
    scanf("%d", &Q);
    while(Q--) {
        scanf(" %c", &c);
        if (c == 'q') {
            scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
            X1--; Y1--; // 0 indexed
            X2--; Y2--;
            int mi = INF, ma = 0;
            for (int i = X1; i <= X2; i++) {
                mi = min(mi, RMnQ(1, 0, N-1, Y1, Y2, i));
                ma = max(ma, RMxQ(1, 0, N-1, Y1, Y2, i));
            }
            printf("%d %d\n", ma, mi);
        } else {
            scanf("%d %d %d", &X1, &Y1, &v);
            X1--; Y1--;
            updateMin(1, 0, N-1, Y1, v, X1);
            updateMax(1, 0, N-1, Y1, v, X1);
        }
    }
}
