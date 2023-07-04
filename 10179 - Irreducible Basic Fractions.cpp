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

//num of integers <N that relatively prime to N
long long eulerPhi(long long N){
    long long ans = N;

    for(int i=0; i<p.size() && p[i]*p[i] <= N; i++){
        if(N % p[i] == 0) ans -= ans/p[i];
        while(N % p[i] == 0) N /= p[i];
    }

    if(N != 1) ans -= ans/N;

    return ans;
}

int main(){
    sieve(1000000);
    long long n;
    while(cin >> n, n){
        cout << eulerPhi(n) << endl;
    }
}
