#include <bits/stdc++.h>
using namespace std;

map<string,string> p1, p2, childof, gen; //p1: parent1; p2: parent2
map<string,int> satu;
vector<string> anak;

string getGen(string name){
  string genp1, genp2, ret;
  
  if(gen[p1[name]]==""){
    genp1 = getGen(p1[name]);
  }
  else{
    genp1 = gen[p1[name]];
  }
  
  if(gen[p2[name]]==""){
    genp2 = getGen(p2[name]);
  }
  else{
    genp2 = gen[p2[name]];
  }
  
  if( (genp1=="dominant" && genp2=="dominant") ||
      (genp1=="dominant" && genp2=="recessive") ||
      (genp1=="recessive" && genp2=="dominant")
    ){
      ret = "dominant";
    }
  else if(  (genp1=="dominant" || genp2=="dominant") ||
            (genp1=="recessive" && genp2=="recessive")
    ){
      ret = "recessive";
    }
  else{
    ret = "non-existent";
  }
  
  return ret;
}

int main() 
{
  int n;
  cin >> n;
  
  while(n--){
    string a,b;
    cin >> a >> b;
    if(b!="dominant" && b!="recessive" && b!="non-existent"){
      childof[a] = b;
      if(satu[b]==0){
        p1[b] = a;
        satu[b] = 1;
        anak.push_back(b);
      }
      else{
        p2[b] = a;
      }  
    }
    else{
      gen[a] = b;
    }
  }
  
  for(int i=0;i<anak.size();i++){
    gen[anak[i]] = getGen(anak[i]);
  }
  
  map<string,string>::iterator it;
  for(it=gen.begin();it!=gen.end();it++){
    cout << it->first << " " << it->second << endl;
  }
  
}
