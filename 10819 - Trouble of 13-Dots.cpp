#include <bits/stdc++.h>
using namespace std;

int memo[10205][105], P[105], F[105];
int M, N, budget;

int query(int id, int spent) {
    if (spent > budget) return -1000000000;
    if (id == N) {
        if (spent <= M || spent > 2000) return 0;
        else return -1000000000;
    }
    if (memo[spent][id] != -1) return memo[spent][id];

    int take = F[id] + query(id+1, spent + P[id]);
    int ignore = query(id+1, spent);

    return memo[spent][id] = max(take, ignore);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(scanf("%d %d", &M, &N) != EOF) {
        budget = M + 200;
        memset(memo, -1, sizeof memo);
        for (int i = 0; i < N; i++) scanf("%d %d", &P[i], &F[i]);
        cout << query(0, 0) << '\n';
    }
    return 0;
}
