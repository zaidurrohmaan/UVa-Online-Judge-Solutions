#include <bits/stdc++.h>
using namespace std;

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int tc;
  cin >> tc;
  cin.ignore();
  char a,b;
  vector<pair<char,char>> cc;
  
  while(tc--){
    int numEdges = 0;
    string edge;
    
    while(getline(cin,edge)){
      if(edge[0] == '*') break;
      a = edge[1];
      b = edge[3];
      cc.push_back(make_pair(a,b));
      numEdges++;
    }
    
    string vertices;
    getline(cin, vertices);
    map<char,int> ci;
    int numVertices = 0;
    for(int i=0;i<vertices.length();i++){
      if(vertices[i] != ','){
        ci[vertices[i]] = 0;
        numVertices++;
      }
    }
    
    int numConnectedComponents = numVertices - numEdges;
    for(int i=0;i<cc.size();i++){
      ci[cc[i].first] = 1;
      ci[cc[i].second] = 1;
    }
    
    int numAcorns = 0;
    for(map<char,int>::iterator it=ci.begin(); it!=ci.end(); it++){
      if(it->second == 0) numAcorns++;
    }
    
    cout << "There are " << numConnectedComponents - numAcorns << " tree(s) and " <<  numAcorns << " acorn(s)." << endl;
    
    cc.clear();
    ci.clear();
  }
}
