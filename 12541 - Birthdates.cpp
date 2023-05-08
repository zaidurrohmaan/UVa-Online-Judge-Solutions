#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

bool cmp(pair<string, vector<int>> a, pair<string, vector<int>> b){
  if(a.se[2] == b.se[2]){
    if(a.se[1] == b.se[1]){
      return a.se[0] > b.se[0];
    }
    return a.se[1] > b.se[1];
  }
  return a.se[2] > b.se[2];
}

int main() 
{
 vector<pair<string, vector<int>>> v;
 vector<int> vv;
 int n, d, m, y;
 string name;
 cin >> n;
 for(int i=0;i<n;i++){
   cin >> name >> d >> m >> y;
   vv.pb(d);
   vv.pb(m);
   vv.pb(y);
   v.pb(mp(name, vv));
   vv.clear();
 }
 sort(v.begin(), v.end(), cmp);
 
 cout << v[0].fi << endl << v.back().fi << endl;
 v.clear();
 
 return 0;
}
