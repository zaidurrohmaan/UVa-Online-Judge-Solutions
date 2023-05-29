#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

class UnionFind{
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N+1, 1);
    numSets = N;
    rank.assign(N+1, 0);
    p.assign(N+1, 0);
    for(int i=1;i<=N;i++){
      p[i] = i;
    }
  }
  
  int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
  
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
  
  void unionSet(int i, int j) {
    if(!isSameSet(i,j)){
      numSets--;
      int x = findSet(i), y = findSet(j);
      
      if(rank[x] > rank[y]) {
        p[y] = x; setSize[x] += setSize[y];
      }
      else{
        p[x] = y; setSize[y] += setSize[x];
        
        if(rank[x] == rank[y]) rank[y]++;
      }
    }
  }
  
  int numDisjointSet() {
    return numSets;
  }
  
  int sizeOfSet(int i) {
    return setSize[findSet(i)];
  }
};

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int tc;
  cin >> tc;
  
  while(tc--){
    int c, success=0, unsuccess=0;
    cin >> c;
    cin.ignore(); //blank line
    UnionFind UF(c);
    string pairs;
    string command;
    int a,b;
    
    while(getline(cin, pairs)){
      if(pairs.length() == 0) break; //if blank line
      stringstream ss(pairs);
      ss >> command >> a >> b;
      if(command == "c"){
        UF.unionSet(a,b);
      }
      else{
        UF.isSameSet(a,b) ? success++ : unsuccess++;
      }
    }
    
    cout << success << "," << unsuccess << endl;
    if(tc) cout << endl; //blankline between each testcase output
  }
}
