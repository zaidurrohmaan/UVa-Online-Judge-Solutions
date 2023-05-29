#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  vector<vii> adjList, newAdjList;
  int m,n;
  
  while(cin >> m >> n){
    cout << n << " " << m << endl;
  
    adjList.assign(m,vii());
    
    for(int mm=0;mm<m;mm++){
      int r;
      cin >> r;
      if(r){
        for(int rr=0;rr<r;rr++){
          int col;
          cin >> col;
          adjList[mm].push_back(ii(col, 0));
        }
        for(int rr=0;rr<r;rr++){
          int weight;
          cin >> weight;
          adjList[mm][rr].second = weight;
        }
      }
    }
    
    newAdjList.assign(n, vii());
    for(int mm=0;mm<m;mm++){
      for(int r=0;r<adjList[mm].size();r++){
        newAdjList[(adjList[mm][r].first) - 1].push_back(ii(mm+1, adjList[mm][r].second));
      }
    }
    
    
    for(int nn=0;nn<n;nn++){
      cout << newAdjList[nn].size();
      for(int r=0;r<newAdjList[nn].size();r++){
        cout << " " << newAdjList[nn][r].first;
      }
      cout << endl;
      
      for(int r=0;r<newAdjList[nn].size();r++){
        if(r) cout << " ";
        cout << newAdjList[nn][r].second;
      }
      cout << endl;
    }
  }
  
  /*
  Print adjacency list
  for(int mm=0;mm<m;mm++){
    cout << mm+1 << ":";
    for(int r=0;r<adjList[mm].size();r++){
      cout << " " << adjList[mm][r].first;
    }
    cout << endl;
  }
  */
  
}
