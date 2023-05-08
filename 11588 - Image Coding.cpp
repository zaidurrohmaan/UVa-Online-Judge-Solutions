#include <bits/stdc++.h>
using namespace std;

int main() 
{
 int x, cs=1;
 cin >> x;
 while(x--){
   int r,c,m,n, arr[26], maks, out=0;
   memset(arr, 0, sizeof(arr));
   char ch;
   cin >> r >> c >> m >> n;
   for(int i=0;i<r;i++){
     for(int j=0;j<c;j++){
       cin >> ch;
       arr[ch-'A']++;
     }
   }
   
   sort(arr, arr+26, greater<int>());
   maks = arr[0];
   
   for(int i=0;i<26;i++){
     if(arr[i] == maks) out += arr[i]*m;
     else out += arr[i]*n;
   }
   
   cout << "Case " << cs++ << ": " << out << endl;
 }
 return 0;
}
