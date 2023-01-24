// NOT ACCEPTED YET

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() 
{
    bool flag[11] = {true};
    int guess;
    string response;
    
    while(cin >> guess, guess){
      cin >> response;
      
      if(response == "too high"){
        for(int i=guess;i<=10;i++){
          flag[i] = false;
        }
      }
      else if(response == "too low"){
        for(int i=guess;i>=1;i--){
          flag[i] == false;
        }
      }
      else{
        if(flag[guess] == false) cout << "Stan is dishonest" << endl;
        else if(flag[guess] == true) cout << "Stan may be honest" << endl;
        
        for(int i=0;i<11;i++){
          flag[i] = true;
        }
      }
    }
}
