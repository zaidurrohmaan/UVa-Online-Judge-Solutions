#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int t,sc=1;
  while(cin >> t, t){
    
    queue<int> team;
    map<int,int> belongTo, inQueue;
    map<int, queue<int>> mapp;
    
    cout << "Scenario #" << sc++ << "\n";
    
    for(int i=0;i<t;i++){
      inQueue[i] = 0; //initially all teams not in queue
      int memberNum;
      cin >> memberNum;
      while(memberNum--){
        int mem;
        cin >> mem;
        belongTo[mem] = i;
      }
    }
    
    string command;
    while(cin >> command, command!="STOP"){
      if(command == "ENQUEUE"){
        int m;
        cin >> m;
        if(inQueue[belongTo[m]] == 0){
          team.push(belongTo[m]);
          inQueue[belongTo[m]] = 1;
        }
        mapp[belongTo[m]].push(m);
      }
      else{
        if(!team.empty()){
          cout << mapp[team.front()].front() << endl;
          mapp[team.front()].pop();
          if(mapp[team.front()].empty()){
            inQueue[team.front()] = 0;
            team.pop();
          }
        }  
      }
    }
    cout << endl;
  }
}
