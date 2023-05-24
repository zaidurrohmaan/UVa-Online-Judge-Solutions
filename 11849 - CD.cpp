#include <bits/stdc++.h>
using namespace std;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n,m,sell;
  map<int,int> map;
  
  while(cin >> n >> m, (n||m)){
    int cd;
    while(n--){
      cin >> cd;
      map[cd]=1;
    }
    sell=0;
    while(m--){
      cin >> cd;
      if(map[cd]==1) sell++;
      else map[cd]=1;
    }
    cout << sell << endl;
    map.clear();
  }
}
