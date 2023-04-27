#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define vi vector<int>

int kiri[100005] = {0};
int kanan[100005] = {0};


int main() 
{
  int s, b, l, r, i;
  
  while(scanf("%d %d", &s, &b), (s||b)){
    
    for(i=1; i<=s; i++){
      kiri[i] = i-1;
      kanan[i] = i+1;
    } 
    
    while(b--){
      cin >> l >> r;
      
      kanan[kiri[l]] = kanan[r];
      kiri[kanan[r]] = kiri[l];
      
      if(kiri[l] < 1) cout << '*';
      else cout << kiri[l];
      cout << " ";
      
      if(kanan[r] > s) cout << '*';
      else cout << kanan[r];
      cout << endl;
    }
    
    cout << "-" << endl;
  }
    
}
