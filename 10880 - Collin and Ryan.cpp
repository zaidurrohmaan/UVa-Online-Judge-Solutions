#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long

int main() 
{
  ll n, c, r, eaten, up, cs=1;;
  cin >> n;
  while(n--){
    cout << "Case #" << cs++ << ":";
    
    cin >> c >> r;
    vector<ll> v;
    if(c==r){
      cout << " 0";
    }
    else{
      eaten = c-r;
      up = sqrt(eaten);
   
      for(int i = 1; i<=up;i++){
        if(eaten%i==0){
          v.pb(i);
          if(eaten/i != i) v.pb(eaten/i); // to avoid duplicate (6*6=36)
        }
      }
      
      sort(v.begin(), v.end());
    }
    
    ll len = v.size();
    for(int i=0;i<len;i++){
      if(v[i] > r){
        if(i != len) cout << " ";
        cout << v[i];
      } 
    }
    cout << endl;
    v.clear();
  }
}
