#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() 
{
    int guess, low = 1, up = 10;
    string response;
    
    while(cin >> guess, guess){
      
      cin.ignore();
      getline(cin, response);
      
      if(response == "too high"){
        up = min(up, guess - 1);
      }
      else if(response == "too low"){
        low = max(low, guess + 1);
      }
      else if(response == "right on"){
        if(guess <= up && guess >= low) cout << "Stan may be honest";
        else cout << "Stan is dishonest";
        
        cout << endl;
        
        low = 1;
        up = 10;
      }
    }
}
