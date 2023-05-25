#include <bits/stdc++.h>
using namespace std;

int main() 
{
  map<string,string> dict;
  
  string inp, a, b;
  
  while(getline(cin, inp)){
    if(inp.size() == 0) break;
    stringstream ss(inp);
    
    ss >> a >> b;
    dict[b] = a;
  }
  
  string ask;
  while(cin >> ask){
    if(dict[ask]=="") cout << "eh" << endl;
    else cout << dict[ask] << endl;
  }
}
