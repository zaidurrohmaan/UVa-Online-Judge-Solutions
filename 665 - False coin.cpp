#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define vi vector<int>

int main() 
{

  int m, n, k, p, i, j, countZero, indeks;
  char result;
  bool found, ada;
  cin >> m;
  
  while(m--){
    int coin[105] = {};
    int temp[105] = {};
    
    cin >> n >> k;
    while(k--){
      cin >> p;
      for(i=1; i<=2*p; i++){
        cin >> temp[i];
      }
      cin >> result;
      
      if(result == '='){
        for(i=1; i<=2*p; i++){
          coin[temp[i]] = 1;
        }
      }
      else{
        for(i = 1; i<=n; i++){
          found = false;
          if(coin[i] != 1){
            for(j=1; j<= 2*p; j++){
              if(i == temp[j]) found = true;
            }
            if(!found) coin[i] = 1;
          }
        }
      }
      
    }
    
    countZero = 0;
    
    for(i=1; i<=n; i++){
      if(coin[i] == 0){
        countZero++;
        indeks = i;
      } 
    }
    
    if(countZero == 1) cout << indeks;
    else cout << "0";
    cout << endl;
    if(m) cout << endl;
    
  }
}
