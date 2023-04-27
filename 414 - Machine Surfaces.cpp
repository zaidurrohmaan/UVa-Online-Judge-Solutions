#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define vi vector<int>

int main() 
{
  int n, x, maks, voids, len;
  char c;
  string inp;
  int numOfX[15] = {};
  
  while(cin >> n, n){
    voids = 0;
    maks = -1;
    cin.ignore();
    for(int j=1;j<=n;j++){
      x = 0;
      inp = "";
      getline(cin, inp);
      len = inp.size();
      for(int i=0; i<len; i++){
        if(inp[i] == 'X') x++;
      }
      maks = max(maks, x);
      numOfX[j] = x;
    }
    for(int i=1;i<=n;i++){
      voids += maks - numOfX[i];
    }
    
    cout << voids << endl;
    
  }
}
