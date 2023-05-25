#include <bits/stdc++.h>
using namespace std;

int main() 
{
  map<int,int> seq;
  map<int,int>::iterator it;
  vector<int> v;
  int n;
  
  while(cin >> n){
    if(seq[n]==0)v.push_back(n);
    seq[n]++;
  }
  
  for(int i=0;i<v.size();i++){
    cout << v[i] << " " << seq[v[i]] << endl;
  }
  
}
