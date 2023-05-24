#include <bits/stdc++.h>
using namespace std;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  while(n--){
    int b,sg,sb,power;
    cin >> b >> sg >> sb;
    multiset<int, greater<int>> green,blue;
    multiset<int, greater<int>>::iterator it;
    
    for(int i=0;i<sg;i++){
      cin >> power;
      green.insert(power);
    }
    for(int i=0;i<sb;i++){
      cin >> power;
      blue.insert(power);
    }
    
    vector<int> vg,vb;
    
    while(blue.size()!=0 && green.size()!=0){
      int bz = blue.size(), gz = green.size();
      int bound = min(b,min(bz,gz));
      for(int i=0;i<bound;i++){
        int pg,pb;
        it = green.begin();
        pg = *it;
        green.erase(it);
        it = blue.begin();
        pb = *it;
        blue.erase(it);
        
        vg.push_back(pg-min(pg,pb));
        vb.push_back(pb-min(pg,pb));
      }
      
      for(int i=0;i<vg.size();i++){
        if(vg[i]!=0)green.insert(vg[i]);
        if(vb[i]!=0)blue.insert(vb[i]);
      }
      vg.clear();
      vb.clear();
    }
    
    if(blue.size()==0 && green.size()==0){
      cout << "green and blue died\n";
      if(n)
        cout << "\n";
      continue;
    }
    
    if(blue.size()==0){
      cout << "green wins" << endl;
      for(it=green.begin();it!=green.end();it++){
        cout << *it << endl;
      }
      green.clear();
    }
    else if(green.size()==0){
      cout << "blue wins" << endl;
      for(it=blue.begin();it!=blue.end();it++){
        cout << *it << endl;
      }
      blue.clear();
    }
    
    if(n) cout << endl;
  }
}
