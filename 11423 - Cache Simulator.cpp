#include <bits/stdc++.h>
using namespace std;
const int MX = 16777217; // 2^24 + 1

int N, X, cache_size[30], miss[30], pos[MX], FT[MX], back = 1, b, y, n; // FT[]: Fenwick Tree
string S;

int LSOne(int x) { return x&-x; }

void update(int x, const int& val) {
    while(x <= MX) {
        FT[x] += val;
        x += LSOne(x);
    }
}

int rsq(int x) { // Range Sum Query
    int res = 0;
    while(x) {
        res += FT[x];
        x -= LSOne(x);
    }
    return res;
}

int rsq(int i, int j) {
    return rsq(j) - (i > 1 ? rsq(i-1): 0);
}

void addr(int& x) {
    if (pos[x] == 0) {
        for (int i = 0; i < N; i++) miss[i]++;
        update(back, 1);
        pos[x] = back++;
    } else {
        int order = rsq(pos[x], back);
        for (int i = 0; i < N; i++) if (cache_size[i] < order) miss[i]++;
        update(pos[x], -1);
        update(back, 1);
        pos[x] = back++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
    cin >> N;
    for (int i = 0; i < N; i++) cin >> cache_size[i];
  
    while(1) {
        cin >> S;
        if (S[0] == 'E') break; // END
        
        if (S[0] == 'R') { // RANGE
            cin >> b >> y >> n;
            for (int k = 0; k < n; k++) {
                X = b + y * k;
                addr(X);
            }
        } else if (S[0] == 'A') { // ADDR
            cin >> X;
            addr(X);
        } else { // STAT
            for (int i = 0; i < N; i++) cout << miss[i] << " \n"[i==N-1];
            memset(miss, 0, sizeof(miss));
        }
    }
}
