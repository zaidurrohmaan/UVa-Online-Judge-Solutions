#include <bits/stdc++.h>
using namespace std;

long long _sieve_size;
vector<int> primes;
bitset<10000010> bs;

void sieve(long long upperbound){
  _sieve_size = upperbound + 1;
  bs.set();
  
  bs[0] = bs[1] = 0;
  
  for(long long i = 2; i <= _sieve_size; i++){
    if(bs[i]){
      primes.push_back(i);
      for(long long j = i * i; j <= _sieve_size; j += i){
        bs[j] = 0;
      }
    }
  }
}

int main(){
  sieve(32000);
  vector<vector<int>> deterPrime;
  vector<int> temp; //for storing temporary determinate prime
  int x, y;
  int gap, back;
  
  for(int i=0;i<primes.size();i++){
    if(temp.size() < 2) temp.push_back(primes[i]);
    else{
      gap = temp[1] - temp[0];
      if(primes[i] - temp.back() == gap) temp.push_back(primes[i]);
      else{
        if(temp.size() >= 3){
          deterPrime.push_back(temp); 
        }
        back = temp.back();
        temp.clear();
        temp.push_back(back);
        temp.push_back(primes[i]);
      }
      
      if(i == primes.size()-1 && temp.size()>=3){
        deterPrime.push_back(temp);
        temp.clear();
      }
    }
  }
  
  while(cin >> x >> y){
    if(x==0 && y==0) break;

    //in case x > y, swap(x, y)
    if(x > y){
      int xx = x;
      x = y;
      y = xx;
    }
    
    for(int i=0;i<deterPrime.size();i++){
      if(deterPrime[i][0] >= x && deterPrime[i][deterPrime[i].size()-1] <= y){
        for(int j=0;j<deterPrime[i].size(); j++){
          if(j!=0) cout << " ";
          cout << deterPrime[i][j];
        }
        cout << endl;
      }
    }
  }  
}
