#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int num, a, b, add;
  bool addtoA;
  while(cin >> num, num){
    a = b = 0;
    add = 1;
    addtoA = true;
    
    while(num){
      if(num & 1){ // if the last bit of num is 1
        if(addtoA) a += add;
        else b += add;
        
        addtoA = !addtoA;
      }
      
      add <<= 1; // add *= 2
      num >>= 1; // num /=2 
    }
    
    cout << a << " " << b << endl;
  }
}
