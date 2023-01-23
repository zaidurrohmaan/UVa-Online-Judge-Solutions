#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() 
{
    
    int n,m,fieldNum=1;
    
    while(cin >> n >> m, n || m){
      
      if(fieldNum > 1) cout << endl;
      printf("Field #%d:\n", fieldNum++);
      
      char field[n+2][m+2];
      
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          cin >> field[i][j];
        }
      }
      
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          if(field[i][j] == '*') cout << "*";
         
          else{
            int mines = 0;
           
            for(int r=i-1;r<=i+1;++r){
              for(int c=j-1;c<=j+1;++c){
                if(field[r][c] == '*') ++mines;
              }
            } 
            cout << mines;
          }
        }
        cout << endl;
      }   
    }  
}
