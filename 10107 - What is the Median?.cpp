#include <bits/stdc++.h>
using namespace std;

int main() 
{
  vector<long long> v;
  long long n, it=0;
  
  while(cin >> n){
    v.push_back(n);
    it++;
    if(it%2==1){
      nth_element(v.begin(), v.begin() + v.size()/2, v.end());
      cout << v[v.size()/2] << endl;
    }
    else{
      nth_element(v.begin(), v.begin() + v.size()/2, v.end());
      nth_element(v.begin(), v.begin() + v.size()/2 - 1, v.end());
      cout << (v[v.size()/2]+v[v.size()/2-1])/2 << endl;
    }
    
  }
  
}
