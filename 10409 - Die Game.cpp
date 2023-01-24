#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() 
{
    int n;
    string s;
    while(cin >> n, n){
      int tmp, dice[7] = {0,1,2,3,4,5,6};
      
      while(n--){
        cin >> s;
        
        //simulate dice's move
        if(s == "north"){
          tmp = dice[1];
          dice[1] = dice[5];
          dice[5] = dice[6];
          dice[6] = dice[2];
          dice[2] = tmp;
        }
        else if(s == "south"){
          tmp = dice[1];
          dice[1] = dice[2];
          dice[2] = dice[6];
          dice[6] = dice[5];
          dice[5] = tmp;
        }
        else if(s == "east"){
          tmp = dice[1];
          dice[1] = dice[3];
          dice[3] = dice[6];
          dice[6] = dice[4];
          dice[4] = tmp;
        }
        else{
          tmp = dice[1];
          dice[1] = dice[4];
          dice[4] = dice[6];
          dice[6] = dice[3];
          dice[3] = tmp;
        }
      }
      cout << dice[1] << endl;
    }
    
}
