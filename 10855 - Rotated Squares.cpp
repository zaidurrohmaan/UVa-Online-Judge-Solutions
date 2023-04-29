#include <bits/stdc++.h>
using namespace std;

void rotate90degree(string arr[], int len){

  string tempArray[len];
  
  for(int i=0;i<len;i++){
    string temp = "";
    for(int j=0;j<len;j++){
      temp += arr[len-1-j][i];
    }
    tempArray[i] = temp;
  }
  
  for(int i=0; i<len; i++){
    arr[i] = tempArray[i];
  }
}

int numOfOccurences(string small[], string big[], int sLen, int bLen){
  int value = 0;

  for(int i=0;i<bLen;i++){
    for(int j=0; j<bLen;j++){
      if(i+sLen <= bLen && j+sLen <= bLen){
        int cnt = 0;
        for(int k=0; k<sLen; k++){
          for(int l=0; l<sLen; l++){
            if(big[i+k][j+l] == small[k][l]) cnt++;
          }
        }
        if(cnt == sLen * sLen) value++;
      }
    }
  }
  
  return value;
}

int main() 
{
  int N, n;
  while(cin >> N >> n, (N||n)){
    string bigSqr[N], smallSqr[n];
    for(int i=0;i<N;i++){
      cin >> bigSqr[i];
    }
    for(int i=0;i<n;i++){
      cin >> smallSqr[i];
    }
    for(int i=0; i<4; i++){
      if(i > 0) cout << ' ';
      cout << numOfOccurences(smallSqr, bigSqr, n, N);
      rotate90degree(smallSqr, n);
    }
    cout << endl;
  }
}
