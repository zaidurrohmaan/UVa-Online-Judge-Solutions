#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int s, created[12], required[12], t=1, sum;
  
  while(cin >> s, s>=0){
    cout << "Case " << t++ << ":\n";
    sum = s;
    for(int i=0;i<12;i++){
      cin >> created[i];
    }
    for(int i=0;i<12;i++){
      cin >> required[i];
    }
    for(int i=0;i<12;i++){
      if(sum >= required[i]){
        cout << "No problem! :D\n";
        sum -= required[i];
      }
      else{
        cout << "No problem. :(\n";
      }
      sum += created[i];
    }
  }
    
}
