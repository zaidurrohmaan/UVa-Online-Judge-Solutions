#include<bits/stdc++.h>
using namespace std;

int EulerPhi[2000010] = {0};
int dp[2000010] = {0};

int depthPhi(int n, int ans){
    if(EulerPhi[n] == 1) return ans;
    ans++;
    return depthPhi(EulerPhi[n], ans);
}

int main(){
    for(int i=0;i<2000010;i++){
        EulerPhi[i] = i;
    }

    for(int i=2; i<2000010; i++){
        if(EulerPhi[i] == i){
            for(int j=i; j<2000010; j+=i){
                EulerPhi[j] = (EulerPhi[j]/i) * (i-1);
            }
        }
    }
    
    int t, m, n, sum, depth;
    cin >> t;
    while(t--){
        cin >> m >> n;
        sum = 0;
        for(int i=m; i<=n; i++){
          if(dp[i] == 0) depth = depthPhi(i, 1);
          else depth = dp[i];
    
          sum += depth;
          dp[i] = depth;
        }
        cout << sum << endl;
    }


}
