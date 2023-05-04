#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int t, k, minim, maks;
  int front[8], side[8];
  cin >> t;
  while(t--){
    cin >> k;
    
    for(int i=0;i<k;i++){
      cin >> front[i];
    }
    for(int i=0;i<k;i++){
      cin >> side[i];
    }
    
    maks = 0, minim = 0;
    
    for(int i=0;i<k;i++){
      for(int j=0;j<k;j++){
        maks += min(front[i], side[j]);
      }
    }
    
    bitset<8> frontNoAvailable;
    bitset<8> sideNoAvailable;
    for(int i=0; i<k; i++){
      for(int j=0;j<k;j++){
        if(front[i] == side[j] && !frontNoAvailable[i] && !sideNoAvailable[j]){
          minim += front[i];
          frontNoAvailable[i] = 1;
          sideNoAvailable[j] = 1;
        }
      }
    }
    
    for(int i=0;i<k;i++){
      if(!frontNoAvailable[i]) minim += front[i];
      if(!sideNoAvailable[i]) minim += side[i];
    }
    cout << "Matty needs at least " << minim <<  " blocks, and can add at most " << maks-minim << " extra blocks." << endl;
  }
}
