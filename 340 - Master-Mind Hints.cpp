#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() 
{
    int n, game = 1;
    
    while(cin >> n, n){
      
      vector<int> code(n);
      for(int i=0;i<n;i++){
        cin >> code[i];
      }
      
      cout << "Game " << game++ << ":\n";
      
      while(true){
        vector<int> guess(n);
      
      for(int i=0;i<n;i++){
        cin >> guess[i];
      }
      
      if(count(guess.begin(), guess.end(), 0) == n){
        break;
      }
      
      int i = 0, j = 0;
      
      vector<bool> marks(n, false);
      
      for(int p=0;p<n;p++){
        if(code[p] == guess[p]){
          i++;
          guess[p] = -1;
          marks[p] = true;
        }
      }
      
      for(int p=0;p<n;p++){
        
        if(!marks[p]){
          
          vector<int>::iterator iter = find(guess.begin(), guess.end(), code[p]);
          if(iter != guess.end()){
            ++j;
            *iter = -1;
            marks[p] = true;
          }
        }
      }
      
      
      printf("      (%d,%d)\n", i, j);
      }
      
    }
    return 0;
}
