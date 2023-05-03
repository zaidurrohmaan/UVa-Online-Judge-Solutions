#include <bits/stdc++.h>
using namespace std;

int matrix[15][15];
int temp[15]; // temporary row/column for interchange 2 rows/columns
int tempMatrix[15][15]; //temporary matrix for transpose

int main() 
{
  int t, n, m, a, b, c=1;
  string op;
  cin >> t;
  while(t--){
    cin >> n;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        scanf("%1d", &matrix[i][j]);
      }
    }
     
    cin >> m;
    while(m--){
      cin >> op;
      if(op == "row"){
        cin >> a >> b;
        for(int i=1;i<=n;i++){
          temp[i] = matrix[a][i];
          matrix[a][i] = matrix[b][i];
          matrix[b][i] = temp[i];
        }
      }
      else if(op == "col"){
        cin >> a >> b;
        for(int i=1;i<=n;i++){
          temp[i] = matrix[i][a];
          matrix[i][a] = matrix[i][b];
          matrix[i][b] = temp[i];
        }
      }
      else if(op == "inc"){
        for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
            matrix[i][j]++;
            if(matrix[i][j] == 10) matrix[i][j] = 0;
          }
        }
      }
      else if(op == "dec"){
        for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
            matrix[i][j]--;
            if(matrix[i][j] == -1) matrix[i][j] = 9;
          }
        }
      }
      else{
        for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
            tempMatrix[i][j] = matrix[j][i];
          }
        }
          
        for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
            matrix[i][j] = tempMatrix[i][j];
          }
        }
      }
    }
     
    cout << "Case #" << c++ << endl;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cout << matrix[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
}
