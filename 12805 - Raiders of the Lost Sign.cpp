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

int primeSign(long long N){
    if(N == 2) return 1;
    if((N-1) % 4 == 0) return -1;
    else if((N+1) % 4 == 0) return 1;
}

int primeFactors(long long N){
    int ans = 1;
    for(long long i=0; i<p.size() && p[i]*p[i] <= N; i++){
        while(N % p[i] == 0) {
          ans *= primeSign(p[i]);
          N /= p[i];
        }
    }

    if(N != 1) ans *= primeSign(N);

    return ans;
}

int main(){
    sieve(1000000);
    long long t, n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 2) cout << "+\n";
        else if(isPrime(n)){
            if(primeSign(n) == -1) cout << "-\n";
            else if(primeSign(n) == 1) cout << "+\n";
        }
        else{
            if(primeFactors(n) == 1) cout << "+\n";
            else if(primeFactors(n) == -1) cout << "-\n";
        }
    }
}
