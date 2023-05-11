#include <bits/stdc++.h>
using namespace std;

int main() {
  
  bitset<1000001> slot;
  bool conflict;
  int n, m, start, end, interval, i;
  
  while(cin >> n >> m, (n||m)){
    slot.reset();
    conflict = false;
    
    while(n--){
      cin >> start >> end;
      
      if(!conflict){
        for(i=start+1; i<=end; i++){
          if(slot[i] == 1) conflict = true;
          else{
            slot.set(i, true);
          }
        }
      }
      
    }
    
    while(m--){
      cin >> start >> end >> interval;
      
      if(!conflict){
        i=start+1;
        int rep = end - start;
        while(i<=1000000 && !conflict){
          for(i=start+1;(i<=start+rep) && (i<=1000000);i++){
            if(slot[i] == 1) conflict=true;
            else{
              slot.set(i,true);
            }
          }
          start += interval;
        }
      }
      
    }
    
    cout << (conflict ? "CONFLICT\n" : "NO CONFLICT\n");
  }
}
