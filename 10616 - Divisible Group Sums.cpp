#include <bits/stdc++.h>
using namespace std;

long long A[205], memo[205][10][25];
int N, Q, D, M;

int negativeModSum(long long X, long long Y) {
    return (X + (Y % D) + D) % D;
}

long long query(int idxN, int remM, int mod) {
    if (remM == 0) return mod == 0;
    if (idxN == N) return 0;
    if (memo[idxN][remM][mod] != -1) return memo[idxN][remM][mod];

    long long take = query(idxN+1, remM-1, negativeModSum(mod, A[idxN]));
    long long ignore = query(idxN+1, remM, mod);

    return memo[idxN][remM][mod] = take + ignore;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int set = 1;
    while(cin >> N >> Q) {
        if (N == 0 && Q == 0) break;
        cout << "SET " << set++ << ":\n";
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 1; i <= Q; i++) {
            memset(memo, -1, sizeof memo);
            cin >> D >> M;
            cout << "QUERY " << i << ": ";
            cout << query(0, M, 0) << '\n';
        }
    }
    return 0;
}
