#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

int minDiff(string s){
  int len = s.length(), ret = 10000;
  for(int i=1; i<len;i++){
    ret = min(ret, abs(s[i] - s[i-1]));
  }
  
  return ret;
}

bool comparator(pair<string, int> a, pair<string, int> b){
  if(a.se == b.se) return a.fi < b.fi;
  else return a.se > b.se;
}

int main() 
{
  string s, tempOut;
  
  vector<pair<string, int>> v;
  
  while(getline(cin, s)){
    
    v.pb(mp(s, minDiff(s)));
    
    int len = s.length();
    char uname[len], uname2[len];
    
    for(int i=0; i<len; i++){
      uname[i] = s[i];
      uname2[i] = s[i];
    }

    int it;
    
    it=11;
    do{
      tempOut = "";
      for(int i=0;i<len;i++){
        tempOut += uname2[i];
      }
      v.pb(mp(tempOut, minDiff(tempOut)));
      it--;
    }while(prev_permutation(uname2, uname2+len) && it>=1);
    
    it=11;
    do{
      tempOut = "";
      for(int i=0;i<len;i++){
        tempOut += uname[i];
      }
      v.pb(mp(tempOut, minDiff(tempOut)));
      it++;
    }while(next_permutation(uname, uname+len) && it<=21);
    
    sort(v.begin(), v.end(), comparator);
    
    cout << v[0].fi << v[0].se << endl;
    v.clear();
  }
}
