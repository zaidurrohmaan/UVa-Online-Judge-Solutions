#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string S;
    int cs = 1;
    cin >> S;
  
    while(S != "end") {
        vector<stack<char>> vs;
        for (int i = 0; i < (int) S.size(); i++) {
            if (vs.empty()) {
                stack<char> sc;
                sc.push(S[i]);
                vs.push_back(sc);
                continue;
            }

            bool flag = 0;
            int nearest = -1;
            for (int j = 0; j < (int) vs.size(); j++) {
                if (S[i] <= vs[j].top()) {
                    if (!flag) {
                        flag = 1;
                        nearest = j;
                    } else {
                        if (vs[nearest].top() > vs[j].top()) nearest = j; 
                    }
                }
            }

            if (!flag) {
                stack<char> sc;
                sc.push(S[i]);
                vs.push_back(sc);
                continue;
            }

            vs[nearest].push(S[i]);
        }
        cout << "Case " << cs++ << ": " << (int) vs.size() << '\n';
        cin >> S;
    }
}
