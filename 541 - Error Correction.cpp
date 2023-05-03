#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n;
  int arr[101][101], row[101]={0}, col[101]={0}, rCount, cCount, r, c;
  while(cin >> n, n){
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    rCount = 0;
    cCount = 0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cin >> arr[i][j];
        row[i] += arr[i][j];
        col[j] += arr[i][j];
      }
    }
    
    for(int i=1;i<=n;i++){
      if(row[i]%2 != 0){
        rCount++;
        r = i;
      }
        
      if(col[i]%2 != 0){
        cCount++;
        c = i;
      }
    }
  
    if(rCount==0 && cCount==0){
      cout << "OK";
    }
    else if(rCount==1 && cCount==1){
      cout << "Change bit (" << r << "," << c << ")"; 
    }
    else cout << "Corrupt";
      
    cout << endl;
  }  
      
}
