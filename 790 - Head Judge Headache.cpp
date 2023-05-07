// I think the problem description isn't clear enough. The input format in problem description different with input format in uDebug.
// So, unfortunately I can't solve this problem.

// The solution below have been satisfy all the rules and requirements in problem description, I think. But again, because the input format is different,
// this solution didn't get accepted :( However, I will still upload this solution in my github repo. Thank you.

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

int penalty[26][8];
int solving[26][8];
int madeSubmission[26];

bool comparator(pair<pair<int, int> ,int> a, pair<pair<int, int> ,int> b){
  if(a.fi.se == b.fi.se){
    if(a.se == b.se) return a.fi.fi < b.fi.fi;
    else return a.se < b.se;
  }
  else return a.fi.se > b.fi.se;
}

int main() 
{
  
  
  int t;
  cin >> t;
  cin.ignore();
  cin.ignore();
  while(t--){
    memset(madeSubmission, 0, sizeof(madeSubmission));
    memset(penalty, 0, sizeof(penalty));
    memset(solving, 0, sizeof(solving));
    
    string s;
    vector<pair<pair<int, int> ,int>> v;// {team, #of problem solved, total time}
    
    while(getline(cin, s) && s.length() != 0){
      int team, problem, time;
      char prob, result;
      string t;
      istringstream in(s);
      
      in >> team >> prob >> t >> result;
      madeSubmission[team] = 1;
      problem = prob - 'A' + 1;
      if(result == 'N' && solving[team][problem] != 1){
        penalty[team][problem] += 20;
      }
      else{
        if(solving[team][problem] != 1){
          time = 60*(t[0]-'0') + 10*(t[2]-'0') + (t[3]-'0');
          penalty[team][problem] += time;
          solving[team][problem] = 1;
        }
      }
    }
    
    for(int i=1; i<=26; i++){
        int pr=0, tm=0;
        for(int j=1; j<=8; j++){
          if(solving[i][j]){
            pr++;
            tm += penalty[i][j];
          }
        }
        
        if(madeSubmission[i] == 1){
          v.pb(mp(mp(i,pr),tm));
        }
      }
      
      sort(v.begin(), v.end(), comparator);
      
      int len = v.size(), rank = 1, minus=0;
      cout << "RANK TEAM PRO/SOLVED TIME\n";
      cout  << right << setw(4) << rank 
            << right << setw(5) << v[0].fi.fi;
      if(v[0].fi.se > 0){
          cout  << right << setw(5) << v[0].fi.se
                << right << setw(11) << v[0].se;
        }
            
      cout << endl;
        
      for(int i=1;i<len;i++){
        rank++;
        if(v[i].fi.se == v[i-1].fi.se && v[i].se == v[i-1].se) minus++;
        else minus = 0;
        cout  << right << setw(4) << rank-minus
              << right << setw(5) << v[i].fi.fi;
              
        if(v[i].fi.se > 0){
          cout  << right << setw(5) << v[i].fi.se
                << right << setw(11) << v[i].se;
          
        }
        cout << endl;
      }
      
      v.clear();
      if(t) cout << endl;
    }
  
}
