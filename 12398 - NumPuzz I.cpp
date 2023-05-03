#include <bits/stdc++.h>
using namespace std;

int main() 
{
  string solution;
  int a[5][5] = {0}, len, r, c, cs=1;
  solution="";
  
  while(getline(cin, solution)){
    memset(a, 0, sizeof(a));
    len = solution.size();

    for(int i=len-1;i>=0;i--){
      if(solution[i] =='a'){
        r=0;
        c=0;
      }
      else if(solution[i] == 'b'){
        r=0;
        c=1;
      }
      else if(solution[i] == 'c'){
        r=0;
        c=2;
      }
      else if(solution[i] == 'd'){
        r=1;
        c=0;
      }
      else if(solution[i] == 'e'){
        r=1;
        c=1;
      }
      else if(solution[i] == 'f'){
        r=1;
        c=2;
      }
      else if(solution[i] == 'g'){
        r=2;
        c=0;
      }
      else if(solution[i] == 'h'){
        r=2;
        c=1;
      }
      else if(solution[i] == 'i'){
        r=2;
        c=2;
      }
      
      r++;
      c++;
      
      a[r][c]++;
      a[r][c] %= 10;
      a[r][c+1]++;
      a[r][c+1] %= 10;
      a[r][c-1]++;
      a[r][c-1] %= 10;
      a[r+1][c]++;
      a[r+1][c] %= 10;
      a[r-1][c]++;
      a[r-1][c] %= 10;   
    }
    
    cout << "Case #" << cs++ << ":" << endl;
    for(int i=1;i<=3;i++){
      for(int j=1;j<=3;j++){
        if(j>1) cout << " ";
        cout << a[i][j];
      }
      cout << endl;
    }
  }
}
