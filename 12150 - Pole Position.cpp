#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define vi vector<int>

int main() 
{
  
  ll n, c, p, i, temp;
  bool impossible;

  while(cin >> n, n){
    
    impossible = false;
    int rank[10005] = {};
    for(i=0; i<n; i++){
      
      cin >> c >> p;
      temp = i + p;
      if(temp < 0 || temp >= n) impossible = true;
      if(!impossible && rank[temp]) impossible = true;
      
      if(impossible) continue;
      
      rank[temp] = c;
    }
    
    if(impossible) cout << "-1";
    else{
      for(i=0; i<n; i++){
        if(i>0) cout << " ";
        cout << rank[i];
      }
    }
    cout << endl;
  }
}
