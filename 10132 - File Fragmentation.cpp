#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int tc;
  cin >> tc;
  cin.ignore();
  cin.ignore();
  
  string fr;
  vector<pair<string,int>> vpp;
  map<string,int> file;
  
  while(tc--){
    
    int n=0; //number of fragments
    int totalBits=0;
    
    while(getline(cin, fr)){
      if(fr=="") break;
      totalBits += fr.size();
      n++;
      
      vpp.push_back(make_pair(fr, fr.size()));
    }
    
    int B = totalBits*2/n; // length of file = B = totalBits / (n/2)
    
    int maks=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i != j){
          if(vpp[i].second+vpp[j].second == B){
            string merge = "";
            merge += vpp[i].first;
            merge += vpp[j].first;
            file[merge]++;
   
            maks = max(maks, file[merge]);
          }
        }
      }
    }
    
    map<string,int>::iterator it;
    string ans;
    for(it=file.begin();it!=file.end();it++){
      if(it->second == maks) ans = it->first;
    }
    cout << ans << endl;
    file.clear();
    vpp.clear();
    
    if(tc) cout << endl; //blankline between testcase output
  }
}
