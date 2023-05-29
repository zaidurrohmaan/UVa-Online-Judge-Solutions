#include <bits/stdc++.h>
using namespace std;

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n,m;
  while(cin >> n >> m){
    vector<vector<int>> vi;
    vi.assign(1000000, vector<int>());
    for(int i=1;i<=n;i++){
      int a;
      cin >> a;
      vi[a].push_back(i);
    }
    
    while(m--){
      int k,v;
      cin >> k >> v;
      if(vi[v].size() >= k){
        cout << vi[v][k-1];
      }
      else cout << "0";
      
      cout << endl;
    }
  }
}
