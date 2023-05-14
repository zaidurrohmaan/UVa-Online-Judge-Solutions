#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

int main() 
{
  int c, currentTime, pos, earliestCar, left=1, right=0; 
  cin >> c;
  
  while(c--){
    int capacity, t, m, arrival;
    string bank;
    cin >> capacity >> t >> m;
    
    vector<queue<pair<int,int>>> v(2); //{arrival time, cars index}
    vector<int> releaseTime(m);
    
    for(int i=0;i<m;i++){
      cin >> arrival >> bank;
      if(bank == "left"){
        v[left].push(mp(arrival,i));
      }
      else v[right].push(mp(arrival,i));
    }
    
    currentTime = 0;
    pos = 1; // start from left bank
    while(! (v[left].empty() && v[right].empty())){
      
      earliestCar = 1e7;
      if(!v[left].empty()){
        earliestCar = v[left].front().first;
      }
      
      if(!v[right].empty()){
        earliestCar = min(earliestCar, v[right].front().first);
      }
      
      currentTime = max(currentTime, earliestCar);
      
      int carcount = 0;
      while(!v[pos].empty() && v[pos].front().first <= currentTime && carcount < capacity){
        releaseTime[v[pos].front().second] = currentTime + t;
        v[pos].pop();
        carcount++;
      }
      
      //go to other side
      currentTime += t;
      pos ^= 1;
      
    }
    
    for(int i=0;i<m;i++){
      cout << releaseTime[i] << endl;
    }
    if(c) cout << endl;
  }
}
