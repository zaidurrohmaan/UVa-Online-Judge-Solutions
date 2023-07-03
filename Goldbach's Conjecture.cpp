#include <bits/stdc++.h>
using namespace std;

#define vii vector<int>

vii primes;
bitset<10000010> bs;
long long _sieve_size;

void sieve(long long upperbound){
  _sieve_size = upperbound + 1;
  bs.set();

  bs[0] = bs[1] = 0;

  for(long long i=2;i<=_sieve_size;i++){
    if(bs[i]){
      primes.push_back((int)i);
      for(long long j=i*i; j<=_sieve_size; j+=i){
        bs[j] = 0;
      }
    }
  }
}

bool isPrime(long long N){
  if(N <= _sieve_size) return bs[N];

  for(int i=0; i<(int)primes.size(); i++){
    if(N % primes[i] == 0) return false;
  }
  return true;
}

int main(){
  sieve(1000000);
  long long n;
  while(cin >> n, n){
    bool valid = false;
    for(long long i=3; i<n; i+=2){
      if(bs[i] && bs[n-i]){
        cout << n << " = " << i << " + " << n-i << endl;
        valid = true;
        break;
      }
    }
    if(!valid) cout << "Goldbach's conjecture is wrong.\n";
  }
}
