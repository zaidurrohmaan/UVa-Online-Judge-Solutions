#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

bool sort_vector(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
  if(a.fi.se == b.fi.se && a.se == b.se){
    return a.fi.fi < b.fi.fi;
  }
  else if(a.fi.se == b.fi.se){
    return a.se < b.se;
  }
  else{
    return a.fi.se > b.fi.se;
  }
}

int main() 
{
  int penalty[101][10]; // to store total penalty each contestant
  int problem[101][10]; // problem[m][n] = 1 if contestant m can solve the problem n, 0 otherwise
  int madeSubmission[101]; // 1 if contestant made a submission, 0 otherwise
  
  //{contestant, #of problem solved, penalty time}
  vector<pair<pair<int,int>,int>> v;
  
  int t;
  cin >> t;
  cin.ignore();
	cin.ignore();
	
  while(t--){
    memset(penalty, 0, sizeof(penalty));
    memset(problem, 0, sizeof(problem));
    memset(madeSubmission, 0, sizeof(madeSubmission));
    
    string inp;
    while(getline(cin, inp) && inp.length() != 0){
      int con, prob, time;
      char ch;
      istringstream in(inp);
      
      in >> con >> prob >> time >> ch;
      if(ch == 'I' && problem[con][prob] != 1){
        penalty[con][prob] += 20;
      }
      else if(ch == 'C' && problem[con][prob] != 1){
        penalty[con][prob] += time;
        problem[con][prob] = 1;
      }
      madeSubmission[con] = 1;
    }
    
    int pn, pr;
    for(int i=1; i<=100;i++){
      pn=0, pr=0;
      for(int j=1; j<=9; j++){
        if(problem[i][j] == 1 && penalty[i][j] > 0){
          pn += penalty[i][j];
          pr++;
        }
      }
      if(madeSubmission[i] > 0){
        v.pb(mp(mp(i, pr), pn));
      }
    }
    
    sort(v.begin(), v.end(), sort_vector);
    for(int i=0; i<v.size();i++){
      cout << v[i].fi.fi << " " << v[i].fi.se << " " << v[i].se << endl;
    }
    v.clear();
    if(t) cout << endl;
  }
}
