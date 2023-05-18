#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll tc;
  cin >> tc;
  
  while(tc--){
    ll n, length=0, maxUnique=0, repeatedPackage=0, snowf;
    map<ll,ll> snowflakes;
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
      cin >> snowf;
      if(snowflakes[snowf]){
        repeatedPackage = max(repeatedPackage, snowflakes[snowf]);
        length = i - repeatedPackage - 1;
      }
      length++;
      snowflakes[snowf] = i;
      maxUnique = max(maxUnique, length);
    }
    
    cout << maxUnique << endl;
  }
}
