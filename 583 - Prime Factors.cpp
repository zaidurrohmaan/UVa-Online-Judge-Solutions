#include <bits/stdc++.h>
using namespace std;

long long _sieve_size;
vector<long long> primes;
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

vector<long long> primeFactors(long long N){
  vector<long long> factors;
  
  for(long long i = 0; (i < primes.size()) && (primes[i] * primes[i] <= N); i++){
    while(N%primes[i] == 0){
      N /= primes[i];
      factors.push_back(primes[i]);
    }
  }
  
  if(N != 1) factors.push_back(N);
  return factors;
}

int numPF(long long N){
  int ans = 0;
  for(int i = 0; (i < primes.size()) && primes[i]*primes[i] <= N; i++){
    while(N % primes[i] == 0){
      N /= primes[i];
      ++ans;
    }
  }
  if(N != 1) ans++;
  return ans;
}

int numDiv(long long N){
  int ans = 1;
  for(int i=0; (i<primes.size()) && primes[i]*primes[i] <= N; i++){
    int power = 0;
    while(N % primes[i] == 0){
      N /= primes[i];
      power++;
    }
    ans *= power+1;
  }
  
  if(N != 1) ans *= 2;
  
  return ans;
}

long long eulerPhi(long long N){
  long long ans = N;
  
  for(int i=0; (i<primes.size()) && primes[i]*primes[i] <= N; i++){
    if(N % primes[i] == 0) ans -= ans/primes[i];
    while(N % primes[i] == 0) N /= primes[i];
  }
  
  if(N != 1) ans -= ans/N;
  
  return ans;
}

int numDiffPF(long long N){
  int ans = 0;
  for(int i=0; (i<primes.size()) && primes[i]*primes[i] <= N; i++){
    if(N % primes[i] == 0) ans++;
    while(N % primes[i] == 0) N /= primes[i];
  }
  if(N != 1) ans++;
  
  return ans;
}

long long sumPF(long long N){
  long long ans = 0;
  for(int i=0; (i<primes.size()) && primes[i]*primes[i] <= N; i++){
    if(N % primes[i] == 0) ans += primes[i];
    while(N % primes[i] == 0) N /= primes[i];
  }
  if(N != 1) ans += N;
  
  return ans;
}

int main(){
  sieve(10000000);
  long long n;
  
  while(cin >> n, n){
    
    cout << n << " = ";
    if(n<0) cout << "-1 x ";
    
    vector<long long> r;
    r = primeFactors(abs(n));
    for(int i=0; i<r.size(); i++){
      if(i != 0) cout << " x ";
      cout << r[i];
    }
    cout << endl;
    r.clear();
  }
}
