#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

bool cmp(ll a, ll b){
  return a > b;
}

int main() 
{
 ll t;
 vector<ll> v;
 cin >> t;
 while(t--){
   ll L, total;
   while(cin>>L){
     if(L==0){
       sort(v.begin(), v.end(), cmp);
       total = 0;
       
       for(ll i=0;i<v.size();i++){
         total += 2*pow(v[i],i+1);
       }
       
       if(total <= 5000000) cout << total << endl;
       else cout << "Too expensive" << endl;
       v.clear();
       break;
     }
     v.pb(L);
   }
 }
 
 return 0;
}
