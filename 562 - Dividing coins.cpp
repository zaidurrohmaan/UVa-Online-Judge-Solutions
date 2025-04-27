#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    while(N--) {
        int M, total = 0;
        cin >> M;
        vector<int> coins(M);
        for (int i = 0; i < M; i++) {
            cin >> coins[i];
            total += coins[i];
        }

        vector<bool> dp(total+1, false);
        dp[0] = true;
        for (int c : coins) {
            for (int s = total; s >= c; s--) {
                dp[s] = dp[s] || dp[s - c];
            }
        }

        int best = 0;
        for (int s = total/2; s >= 0; s--) {
            if (dp[s]) {
                best = s;
                break;
            }
        }

        cout << total - 2 * best << '\n';
    }
    return 0;
}
