#include <bits/stdc++.h>
using namespace std;

int main() 
{
  string queries;
  int qnum, period;
  map<int,int> qmap;
  priority_queue<pair<int,int>> pqp;
  
  while(cin >> queries, queries!="#"){
    cin >> qnum >> period;
    qmap[qnum] = period;
  }
  
  int k;
  cin >> k;
  
  for(int i=1;i<=k;i++){
    for(map<int,int>::iterator it=qmap.begin(); it!=qmap.end();it++){
      pqp.push(make_pair(-(it->second * i), -(it->first)));
    }
  }
  
  for(int i=1;i<=k;i++){
    cout << -(pqp.top().second) << endl;
    pqp.pop();
  }
}
