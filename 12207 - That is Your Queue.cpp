#include <bits/stdc++.h>
using namespace std;

int main() 
{
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  
  int p,c,tc=1;
  while(cin >> p >> c, (p||c)){
    char command;
    int x;
    
    list<int> dq;
    for(int i=1;i<=min(p,c);i++){
      dq.push_back(i);
    }
    
    cout << "Case " << tc++ << ":" << endl;
    
    for(int i=0;i<c;i++){
      cin >> command;
      if(command == 'E'){
        cin >> x;
        dq.remove(x);
        dq.push_front(x);
        
      }
      else{
        cout << dq.front() << endl;
        dq.push_back(dq.front());
        dq.pop_front();
      }
    }
  }
}
