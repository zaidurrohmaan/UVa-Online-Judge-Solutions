#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, order[1001];
  
  while(cin >> n, n){
    
    while(true){
      cin >> order[0];
      if(order[0] == 0){
        cout << endl;
        break;
      }
      
      for(int i=1;i<n;i++){
        cin >> order[i];
      }
      
      stack<int> station;
      int currCoach=1, orderIdx=0;
      
      while(currCoach <= n){
        station.push(currCoach);
        
        while(!station.empty() && station.top() == order[orderIdx]){
          station.pop();
          orderIdx++;
          if(orderIdx>=n) break;
        }
        
        currCoach++;
      }
      
      cout << (station.empty() ? "Yes\n" : "No\n");
      
    }
  }
}
