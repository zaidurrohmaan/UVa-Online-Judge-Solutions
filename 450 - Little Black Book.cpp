#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

bool comparator(pair<pair<pair<string, string>,pair<string, string>>,pair<pair<string, string>,pair<string, string>>> a,
                pair<pair<pair<string, string>,pair<string, string>>,pair<pair<string, string>,pair<string, string>>> b){
                  return a.fi.se.se < b.fi.se.se;
                }

int main() 
{
  int t;
  cin >> t;
  cin.ignore();
  vector<pair<pair<pair<string, string>,pair<string, string>>,pair<pair<string, string>,pair<string, string>>>> v;
  vector<string> vv;
  string department, data, title, fname, lname, addr, homPh, wrkPh, mlBx;
  while(t--){
    getline(cin, department);
    while(getline(cin, data) && data.length() != 0){
      stringstream inp(data);
      while(inp.good()){
        string substr;
        getline(inp, substr, ',');
        vv.pb(substr);
      }
      title = vv[0];
      fname = vv[1];
      lname = vv[2];
      addr = vv[3];
      homPh = vv[4];
      wrkPh = vv[5];
      mlBx = vv[6];
      vv.clear();
      v.pb(mp(mp(mp(department, title),mp(fname, lname)),mp(mp(addr, homPh),mp(wrkPh, mlBx))));
    }
  }
  
  sort(v.begin(), v.end(), comparator);
  
  int len = v.size();
  
  for(int i=0;i<len;i++){
    cout << "----------------------------------------\n";
    department = v[i].fi.fi.fi;
    title = v[i].fi.fi.se;
    fname = v[i].fi.se.fi;
    lname = v[i].fi.se.se;
    addr = v[i].se.fi.fi;
    homPh = v[i].se.fi.se;
    wrkPh = v[i].se.se.fi;
    mlBx = v[i].se.se.se;
    cout << title << " " << fname << " " << lname << endl;
    cout << addr << endl;
    cout << "Department: " << department << endl;
    cout << "Home Phone: " << homPh << endl;
    cout << "Work Phone: " << wrkPh << endl;
    cout << "Campus Box: " << mlBx << endl;

  }
}
