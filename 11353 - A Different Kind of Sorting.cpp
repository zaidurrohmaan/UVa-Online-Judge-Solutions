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

long long numPF(long long N){
    long long ans = 0;
    for(int i=0; i<p.size() && p[i]*p[i] <= N; i++){
        while(N % p[i] == 0){
            ans++;
            N /= p[i];
        }
    }

    if(N != 1) ans++;

    return ans;
}

bool cust_comparator(pair<long long, long long> a, pair<long long, long long> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
  
    sieve(1000000);
    vector<pair<long long, long long>> vll;
    for(long long i=1; i<=2000000; i++){
        vll.push_back(make_pair(i, numPF(i)));
    }

    sort(vll.begin(), vll.end(), cust_comparator);

    long long n, c=1;
    while(cin >> n, n){
        cout << "Case " << c++ << ": ";
        cout << vll[n-1].first << endl;
    }
}
