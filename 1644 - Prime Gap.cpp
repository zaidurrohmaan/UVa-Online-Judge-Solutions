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
  sieve(1299709);
  long long n;
  
  while(cin >> n, n){
    if(isPrime(n)) cout << "0\n";
    else{
      for(long long i=0;i<primes.size(); i++){
        if(primes[i] < n && primes[i+1] > n) cout << primes[i+1] - primes[i] << endl;
      }
    }
  }
}
