#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n;
  bool possib;
  
  while(cin >> n, n){
    
    vector<int> pos(n);
    
    for(int i=0;i<n;i++){
      cin >> pos[i];
    }
    
    sort(pos.begin(), pos.end());
    
    if(pos[0] <= 200){
      possib = true;
      for(int i=1;i<n;i++){
        if(pos[i] - pos[i-1] > 200){
          possib = false;
          break;
        }
      }
      
      if(possib && pos[n-1] >= 1322) cout << "POSSIBLE\n";
      else cout << "IMPOSSIBLE\n";
    }
    else cout << "IMPOSSIBLE\n";
  }
}
