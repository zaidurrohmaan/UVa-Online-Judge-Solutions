//Note: This solution is inefficient but still got Accepted.

#include <bits/stdc++.h>
using namespace std;

bool identic(char a[][10], char b[][10], int n){
  for(int i=0; i<n;i++){
    for(int j=0; j<n; j++){
      if(a[i][j] != b[i][j]) return false;
    }
  }
  return true;
}
void rotate90(char a[][10], int n){
  
  char temp[n][n];
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      temp[i][j] = a[n-1-j][i];
    }
  }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      a[i][j] = temp[i][j];
    }
  }
}

void rotate180(char a[][10], int n){
  
  char temp[n][n];
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      temp[i][j] = a[n-1-i][n-1-j];
    }
  }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      a[i][j] = temp[i][j];
    }
  }
}

void rotate270(char a[][10], int n){
  
  char temp[n][n];
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      temp[i][j] = a[n-1-j][n-1-i];
    }
  }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      a[i][j] = temp[i][j];
    }
  }
}

void reflection(char a[][10], int n){
  char temp[n][n];
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      temp[i][j] = a[n-1-i][j];
    }
  }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      a[i][j] = temp[i][j];
    }
  }
}

int main() 
{
  int n, c=1;
  string ans;
  char original[10][10], transformed[10][10], copy[10][10];
  while(scanf("%d", &n) > 0){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin >> original[i][j];
        copy[i][j] = original[i][j];
      }
      for(int j=0;j<n;j++){
        cin >> transformed[i][j];
      }
    }
    
    if(identic(original, transformed, n)) ans = "was preserved.";
    else{
      rotate90(original, n);
      if(identic(original, transformed, n)) ans = "was rotated 90 degrees."; 
      else{
        rotate90(original, n);
        if(identic(original, transformed, n)) ans = "was rotated 180 degrees.";
        else{
          rotate90(original, n);
          if(identic(original, transformed, n)) ans = "was rotated 270 degrees.";
          else{
            reflection(copy, n);
            if(identic(copy, transformed, n)) ans = "was reflected vertically.";
            else{
              rotate90(copy, n);
              if(identic(copy, transformed, n)) ans = "was reflected vertically and rotated 90 degrees.";
              else{
                rotate90(copy, n);
                if(identic(copy, transformed, n)) ans = "was reflected vertically and rotated 180 degrees.";
                else{
                  rotate90(copy, n);
                  if(identic(copy, transformed, n)) ans = "was reflected vertically and rotated 270 degrees.";
                  else{
                    ans = "was improperly transformed.";
                  }
                }
              }
            }
          }
        }
      }
    }
    cout << "Pattern " << c++ << " " << ans << endl;
  }
}
