#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() 
{
  int n;
  while(cin >> n, n){
    ll cost = 0;
    multiset<int> ms;
    multiset<int>::iterator it;
    while(n--){
      int k;
      cin >> k;
      while(k--){
        int a;
        cin >> a;
        ms.insert(a);
      }
      
      it=ms.end();
      it--;
      
      cost += *it -*(ms.begin());
      it = ms.begin();
      ms.erase(it);
      it = ms.end();
      it--;
      ms.erase(it);
    }
    
    cout << cost << endl;
    
  }
    
}
