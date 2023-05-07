#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

bool comparator(vector<string> a, vector<string> b){
  return a[2] < b[2];
}

int main() 
{
  int t;
  cin >> t;
  cin.ignore();
  vector<vector<string>> v;
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
      vv.pb(department);
      v.pb(vv);
      vv.clear();
    }
  }
  
  sort(v.begin(), v.end(), comparator);
  
  int len = v.size();
  
  for(int i=0;i<len;i++){
    cout << "----------------------------------------\n";
    title = v[i][0];
    fname = v[i][1];
    lname = v[i][2];
    addr = v[i][3];
    homPh = v[i][4];
    wrkPh = v[i][5];
    mlBx = v[i][6];
    department = v[i][7];
    cout << title << " " << fname << " " << lname << endl;
    cout << addr << endl;
    cout << "Department: " << department << endl;
    cout << "Home Phone: " << homPh << endl;
    cout << "Work Phone: " << wrkPh << endl;
    cout << "Campus Box: " << mlBx << endl;
  }
}
