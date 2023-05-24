#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int tc;
  cin >> tc;
  deque<int> deq;
  priority_queue<int> pq; //for saving the biggest priority in the queue
  
  while(tc--){
    int n, m, p;
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
      cin >> p;
      deq.push_back(p);
      pq.push(p);
    }
    
    int time = 0, pos=m;
    while(true){
      if(deq.front()==pq.top() && pos==0){ //if our document's time to print
        time++;
        break;
      }
      else if(deq.front()==pq.top()){
        time++;
        deq.pop_front();
        pq.pop();
        n--; //decrease the size of queue
      }
      else{
        deq.push_back(deq.front());
        deq.pop_front();
      }
      pos--;
      pos = (pos+n)%n; //maintain our document's position (index)
    }
    
    cout << time << endl;
    deq.clear();
    while(!pq.empty()){
      pq.pop();
    }
  }
    
}
