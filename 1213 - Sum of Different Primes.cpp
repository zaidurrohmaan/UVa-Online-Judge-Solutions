#include <bits/stdc++.h>
using namespace std;

int N, K, memo[190][1125][15], ans;
vector<int> primes;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int query(int idx, int remN, int remK) {
    if (remN == 0 && remK == 0) return 1;
    if (remN <= 0) return 0;
    if (remK <= 0) return 0;
    if (idx == 187) return 0;
    if (memo[idx][remN][remK] != -1) return memo[idx][remN][remK];

    return memo[idx][remN][remK] = query(idx+1, remN - primes[idx], remK-1) + query(idx+1, remN, remK); // take + ignore
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 2; i <= 1120; i++) if (isPrime(i)) primes.push_back(i); // primes.size = 187

    while(cin >> N >> K) {
        if (N == 0 && K == 0) break;
        memset(memo, -1, sizeof memo);
        cout << query(0, N, K) << '\n';
    }
    return 0;
}
