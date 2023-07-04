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

bool isPrime(long long N){
  if(N <= _sieve_size) return bs[N];
  for(int i=0;i<primes.size();i++){
    if(N % primes[i] == 0) return false;
    return true;
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

int main(){
  sieve(1000000);
  
  long long afib[41], bfib[41], t, n, a, b;
  cin >> t;
  
  while(t--){
    cin >> n >> a >> b;

    
    //Little Rakin Fibonacci: a, b, a*b, a*b*b, a*b*b*a*b, a*b*b*a*b*a*b*b, ...
    //                        (a^1)(*b^0), (a^0)*(b^1), (a^1)*(b^2), (a^2)*(b^3), (a^3)*(b^5), ...
    afib[0] = 1;
    afib[1] = 0;
    
    bfib[0] = 0;
    bfib[1] = 1;
    
    for(int i=2;i<=41;i++){
      afib[i] = afib[i-1] + afib[i-2];
      bfib[i] = bfib[i-1] + bfib[i-2];
    }
    
    map<long long,long long> m;
    
    if(isPrime(a)) m[a] += afib[n];
    else{
      long long A = a;
      for(int i=0; i<primes.size() && primes[i]*primes[i]<=A; i++){
        long long power = 0;
        while(A % primes[i] == 0){
          A /= primes[i];
          power++;
        }
        
        power *= afib[n];
        m[primes[i]] += power;
      }
      if(A != 1) m[A] += afib[n];
    }
    
    if(isPrime(b)) m[b] += bfib[n];
    else{
      long long B = b;
      for(int i=0; i<primes.size() && primes[i]*primes[i]<=B; i++){
        long long power = 0;
        while(B % primes[i] == 0){
          B /= primes[i];
          power++;
        }
        
        power *= bfib[n];
        m[primes[i]] += power;
      }
      if(B != 1) m[B] += bfib[n];
    }
    
    map<long long, long long>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
      if(it->second != 0)
        cout << it->first << " " << it->second << endl;
    }
    m.clear();
    cout << endl;
  }
}
