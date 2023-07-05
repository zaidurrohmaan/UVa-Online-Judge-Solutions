#include<bits/stdc++.h>
using namespace std;

int main(){
  int t, g, l;
  cin >> t;
  while(t--){
    cin >> g >> l;
    if(l%g) cout << "-1\n";
    else cout << g << " " << l << endl;
  }
}
