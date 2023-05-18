#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  cin >> tc;
  cin.ignore();
  cin.ignore();
  
  double total;
  string tree;
  map<string, double> maps;
  
  while(tc--){
    maps.clear();
    total=0;
    
    while(getline(cin, tree)){
      if(tree == "") break;
      maps[tree]++;
      total++;
    }
    
    map<string,double>::iterator it;
    for(it=maps.begin(); it!=maps.end();it++){
      cout << it->first << " " << fixed << setprecision(4) << it->second*100.0/total << endl;
    }
    if(tc) cout << endl; //blankspace between testcases
  }
}
