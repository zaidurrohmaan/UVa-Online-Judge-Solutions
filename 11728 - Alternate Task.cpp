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

bool isPrime(long long N){
    if(N < _sieve_size) return bs[N];
    for(int i=0;i<p.size() && p[i]*p[i]<=N;i++){
        if(N%p[i]==0) return false;
    }
    return true;
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
  
    sieve(1000000);
    
    long long n;
    int c=1;
    bool exist;
    while(cin >> n, n){
        cout << "Case " << c++ << ": ";
        exist = false;
        for(long long i=n; i>0; i--){
            if(sumDiv(i) == n) {cout << i << endl; exist = true; break;}
        }
        if(!exist) cout << "-1\n";
    }
}
