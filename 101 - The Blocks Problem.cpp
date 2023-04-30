#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vec;
map<int,int> mymap; //[blockNumbers][position]

int main(){
  int n, a, b;
  string firstComm, secComm;
  vector<int> tempVec;
  cin >> n;
  for(int i=0;i<n;i++){
    mymap[i] = i;
    tempVec.push_back(i);
    vec.push_back(tempVec);
    tempVec.pop_back();
  }

  while(cin >> firstComm, firstComm != "quit"){
    cin >> a >> secComm >> b;
    int aPos = mymap[a];
    int bPos = mymap[b];
    
    if((a != b) && (aPos != bPos)){
      if(firstComm == "move" && secComm == "onto"){
      
        while(vec[aPos].back() != a){
          vec[vec[aPos].back()].push_back(vec[aPos].back()); // move blocks above block a to its initial position
          mymap[vec[aPos].back()] = vec[aPos].back(); //change the position value on the mymap
          vec[aPos].pop_back(); // remove the moved block from previous position
        }
        
        while(vec[bPos].back() != b){
          vec[vec[bPos].back()].push_back(vec[bPos].back()); // move blocks above block b to its initial position
          mymap[vec[bPos].back()] = vec[bPos].back(); //change the position value on the mymap
          vec[bPos].pop_back(); // remove the moved block from previous position
        }
        
        vec[bPos].push_back(a); //move block a to above block b
        mymap[a] = bPos; //change the position value on the mymap
        vec[aPos].pop_back(); // remove block a from previous position
      }
      
      else if(firstComm == "move" && secComm == "over"){
        while(vec[aPos].back() != a){
          vec[vec[aPos].back()].push_back(vec[aPos].back()); // move blocks above block a to its initial position
          mymap[vec[aPos].back()] = vec[aPos].back(); //change the position value on the mymap
          vec[aPos].pop_back(); // remove the moved block from previous position
        }
        
        vec[bPos].push_back(a);
        mymap[a] = bPos; //change the position value on the mymap
        vec[aPos].pop_back();
      }
      
      else if(firstComm == "pile" && secComm == "onto"){
        while(vec[bPos].back() != b){
          vec[vec[bPos].back()].push_back(vec[bPos].back()); // move blocks above block b to its initial position
          mymap[vec[bPos].back()] = vec[bPos].back(); //change the position value on the mymap
          vec[bPos].pop_back(); // remove the moved block from previous position
        }
        
        while(vec[aPos].back() != a){
          tempVec.push_back(vec[aPos].back());
          vec[aPos].pop_back();
        }
        
        vec[bPos].push_back(a);
        mymap[a] = bPos; //change the position value on the mymap
        vec[aPos].pop_back();
        
        int sz = tempVec.size();
        
        while(sz--){
          vec[bPos].push_back(tempVec.back());
          mymap[tempVec.back()] = bPos; //change the position value on the mymap
          tempVec.pop_back();
        }
      }
      
      else if(firstComm == "pile" && secComm == "over"){
        while(vec[aPos].back() != a){
          tempVec.push_back(vec[aPos].back());
          vec[aPos].pop_back();
        }
        
        tempVec.push_back(a);
        vec[aPos].pop_back();
        
        int sz = tempVec.size();
        
        while(sz--){
          vec[bPos].push_back(tempVec.back());
          mymap[tempVec.back()] = bPos; //change the position value on the mymap
          tempVec.pop_back();
        }
      }
    }
  }
  for(int i=0; i<n; i++){
    cout << i << ":";
    if(vec[i].size()!=0){
      for (auto it = vec[i].begin();it != vec[i].end(); it++){
        cout << " " << *it;
      }
    }
    cout << endl;
  }
}
