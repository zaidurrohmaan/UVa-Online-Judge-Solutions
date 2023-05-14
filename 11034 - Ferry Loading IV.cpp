#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int c;
  cin >> c;
  
  while(c--){
    double l, carLength;
    int m, pos;
    string bank;
    
    vector<queue<double>> v(2); //v[0] to store right bank queue; v[1] to store left bank queue
    cin >> l >> m;
    
    for(int i=0;i<m;i++){
      cin >> carLength >> bank;
      
      if(bank == "left"){
        v[1].push(carLength/100.0);// convert from cm to m
      }
      else v[0].push(carLength/100.0);
    }
    
    int crossing = 0;
    pos = 1; // ferry start from left bank (pos=1 for left, pos=0 for right)
    double lengthLoaded;
    while(! (v[0].empty() && v[1].empty()) ){
      
      lengthLoaded = 0;
      while(!v[pos].empty() && (v[pos].front() + lengthLoaded) <= l){
        lengthLoaded += v[pos].front();
        v[pos].pop();
      }
      
      crossing += 1;
      pos ^= 1;
      
    }
    
    cout << crossing << endl;
  }
  
}
