#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,i,c;
  while(cin >> n){
    c = 0;
    for(i=0;i<4;i++){
      c = (c<<8)|((n>>(8*i))&255);
    }
    cout << n << " converts to " << c << endl;
  }
}
