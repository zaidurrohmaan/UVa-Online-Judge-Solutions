#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int t, n, m, size, wo, player;
  bitset<1024> contestant;
  cin >> t;
  while(t--){
    
    cin >> n >> m;
    size = 1 << n; // size = 2^n
    
    for(int i=0;i<size;i++){
      contestant.set(i,true);
    }
    
    for(int i=0; i<m; i++){
      cin >> player;
      contestant.set(player-1, false);
    }
    
    wo = 0;
    
    while(size > 1){
      for(int i=0; i<size; i+=2){
        if(contestant[i]){
          if(!contestant[i+1]){
            wo++;
          }
          contestant.set(i>>1, true); // i>>1 is equal to i divided by 2
          
        }
        else{
          if(contestant[i+1]){
            wo++;
            contestant.set(i>>1, true);
          }
          else{
            contestant.set(i>>1, false);
          }
        }
      }
      
      size >>= 1; // is equal to size = size/2
    }
    
    cout << wo << endl;
    
  }
}
