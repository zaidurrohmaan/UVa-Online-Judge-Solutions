#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

int memo[205][1105][25], P[205], V[205];
int N, X, T, K, v, charge, budget, tea;

bool validSpent(int X) {
    X += tea;
    X += (X+9)/10;
    return X <= budget;
}

int query(int id, int spent, int ordered) {
    if (spent > budget) return -INF;
    if (ordered > 2*(N+1)) return -INF;
    if (id == 2*K) {
        if (validSpent(spent)) return 0;
        return -INF;
    }
    int &ans = memo[id][spent][ordered];
    if(ans != -1) return ans;

    int take = V[id] + query(id+1, spent + P[id], ordered+1);
    int ignore = query(id+1, spent, ordered);

    return ans = max(take, ignore);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(cin >> N >> X >> T >> K) {
        if (N + X + T + K == 0) break;
        for (int i = 0; i < 2*K; i+=2) {
            cin >> P[i];
            cin >> V[i];
            for (int j = 0; j < N; j++) {
                cin >> v;
                V[i] += v;
            }
            P[i+1] = P[i];
            V[i+1] = V[i];
        }

        tea = T * (N+1);
        budget = X * (N+1);

        memset(memo, -1, sizeof memo);

        cout << fixed << setprecision(2) << (double) query(0, 0, 0)/(N+1) << '\n';
    }
    return 0;
}
