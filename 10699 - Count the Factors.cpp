#include<bits/stdc++.h>
using namespace std;

int main(){
    //Modified Sieve
    int numDiffPFarr[1000001] = {0};

    for(int i=2;i<=1000001;i++){
        if(numDiffPFarr[i] == 0){
            for(int j=i; j<=1000001; j += i){
                numDiffPFarr[j]++;
            }
        }
    }

    int n;
    while(cin >> n, n){
        cout << n << " : " << numDiffPFarr[n] << endl;
    }

}
