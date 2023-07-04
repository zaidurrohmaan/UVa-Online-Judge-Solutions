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

//num of divisors
long long numDiv(long long N){ 
    long long ans = 1;
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

int main(){
    sieve(1000000);

    long long t, l, u;
    cin >> t;
    while(t--){
        cin >> l >> u;
        long long maks = -1, num, divs;
        for(long long i = u; i >= l; i--){
            divs = numDiv(i);
            if(divs >= maks) {num = i; maks = divs;}
        }
        cout << "Between " << l << " and " << u << ", " << num << " has a maximum of " << maks << " divisors.\n"; 
    }
}
