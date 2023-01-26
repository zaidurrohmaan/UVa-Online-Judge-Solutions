#include <bits/stdc++.h>
//#include <string>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
  
int main() 
{
    int n;
    string s;
    
    cin >> n;
    cin.ignore();
    
    for(int tc = 1; tc <= n; tc++){
      
      getline(cin, s);
      int len = s.length();
      
      string ss = "";
      
      for(int i=0;i<len;i++){
        if(((s[i] >= 97 && s[i] <= 122)){
          ss += s[i];
        }
      }
      
      cout << "Case #" << tc << ":" << endl;
      
      len = ss.length();
      int sq = sqrt(len);
      if(sq * sq != len) cout << "No magic :(" << endl;
      else{
        int c = 0;
        for(int i=0;i<len;i++){
          if(ss[i] == ss[len-i-1]) c++;
        }
        
        if(c == len) cout << sq << endl;
        else cout << "No magic :(" << endl;
      }
      
    
    }
}
