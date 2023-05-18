#include <bits/stdc++.h>
using namespace std;


int main() {
  int tc, n;
  vector<int> v(5);
  while(cin >> tc, tc){
    map<vector<int>, int> combination;
    int maks=0, total=0;
    for(int i=0;i<tc;i++){
      for(int j=0;j<5;j++){
        cin >> v[j];
      }
      sort(v.begin(), v.end());
      combination[v]++;
      maks = max(maks, combination[v]);
    }
    map<vector<int>,int>::iterator it;
    
    for(it=combination.begin(); it!=combination.end(); it++){
      if(it->second == maks) total += maks;
    }
    
    cout << total << endl;
    
  }
}
