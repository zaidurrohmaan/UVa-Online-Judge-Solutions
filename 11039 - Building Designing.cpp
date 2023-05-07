#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

bool comparator(pair<int,int> a, pair<int,int> b){
  return a.se > b.se;
}

int main() 
{
  int t;
  cin >> t;
  vector<pair<int,int>> v;
  
  while(t--){
    int n, s, floor;
    cin >> n;
    if(n==0) floor=0;
    else floor = 1;
    while(n--){
      cin >> s;
      v.pb(mp(s, abs(s)));
    }
    
    sort(v.begin(),v.end(),comparator);
    
    for(int i=1;i<v.size();i++){
      if((v[i].fi>0 && v[i-1].fi<0) || (v[i].fi<0 && v[i-1].fi>0)) floor++;
    }
    cout << floor << endl;
    v.clear();
  }
  
}
