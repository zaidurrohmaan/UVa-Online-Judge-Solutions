#include<bits/stdc++.h>
using namespace std;

long long _sieve_size;
bitset<10000010> bs;
vector<long long> p;

void sieve(long long upperbound){
    _sieve_size = upperbound + 1;
    bs.set();

    bs[0] = bs[1] = 0;

    for(long long i=2; i<_sieve_size; i++){
        if(bs[i]){
            for(long long j=i*i; j< _sieve_size; j+=i) bs[j] = 0;
            p.push_back(i);
        }
    }
}

int numDiv(long long N){
    int ans = 1;
    for(int i=0; i<=p.size() && p[i]*p[i] <= N; i++){
        int power = 0;
        while(N % p[i] == 0){
            power++;
            N /= p[i];
        }
        ans *= power+1;
    }
    if(N != 1) ans *= 2;
    return ans;
}

long long sumDiv(long long N){
    long long ans = 1;

    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i){
        long long multiplier = p[i], total = 1;

        while(N % p[i] == 0){
            N /= p[i];
            total += multiplier;
            multiplier *= p[i];
        } 
        ans *= total;
    }
    if(N != 1) ans *= N+1;
    return ans;
}

int main(){
  sieve(100001);
  int t,a,b,k,start;
  cin >> t;
  
  while(t--){
    cin >> a >> b >> k;
    
    start = a;
    
    while(true){
      if(start%k == 0) break;
      else start++;
    }

    //d(i)
    long long ans = 0;
    for(int i=start; i<=b; i+=k){
      ans += numDiv(i);
    }
    cout << ans << " ";

    //sigma(i)
    ans = 0;
    for(int i=start; i<=b; i+=k){
      ans += sumDiv(i);
    }
    cout << ans << endl;
  }
  
}
