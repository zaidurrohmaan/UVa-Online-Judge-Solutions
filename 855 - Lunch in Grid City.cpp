#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int t, s, a, f, x, y, ss, aa;
  cin >> t;
  while(t--){
    cin >> s >> a >> f;
    int street[f], avenue[f];
    for(int i=0;i<f;i++){
      cin >> street[i] >> avenue[i];
    }
    
    sort(street, street+f);
    sort(avenue, avenue+f);
    
    if(f%2 == 0){
      ss = street[f/2-1];
      aa = avenue[f/2-1];
    }
    else{
      ss = street[f/2];
      aa = avenue[f/2];
    }
    
    cout << "(Street: " << ss << ", Avenue: " << aa << ")\n";
  }
}
