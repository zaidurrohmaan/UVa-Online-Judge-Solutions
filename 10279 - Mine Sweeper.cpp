#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() 
{
    int game;
    bool wrongTouch;
    cin >> game;
    
    while(game--){
      int n;
      cin >> n;
      
      char mine[n+2][n+2] = {'.'};
      char touched[n+2][n+2] = {'.'};
      
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          cin >> mine[i][j];
        }
      }
      
      wrongTouch = false;
      
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          cin >> touched[i][j];
          
          if(touched[i][j] == 'x' && mine[i][j] == '*'){
            wrongTouch = true;
          }
        }
      }
      
      
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          
          if(mine[i][j] == '*'){
            if(wrongTouch) cout << '*';
            else cout << '.';
          }
          else if(touched[i][j] == '.'){
             cout << '.';
          }
          else{
            int mines = 0;
            for(int r=i-1;r<=i+1;r++){
              for(int c=j-1;c<=j+1;c++){
                if(mine[r][c] == '*'){
                  mines++;
                }
              }
            }
            cout << mines;
          }
        }
        cout << endl;
      }
      
      //blank line between game
      if(game) cout << endl;
      
    }
    
}
