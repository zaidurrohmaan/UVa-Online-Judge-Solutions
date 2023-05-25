#include <bits/stdc++.h>
using namespace std;

int main() 
{
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  string n = "12312312312312312341231234";
  map<char,int> m;
  for(int i=0;i<26;i++){
    m[alphabet[i]] = n[i]-'0';
  }
  m[' '] = 1;
  
  int tc;
  cin >> tc;
  cin.ignore();
  for(int t=1;t<=tc;t++){
    cout << "Case #" << t << ": ";
    
    string msg;
    getline(cin,msg);
    int ans=0;
    for(int i=0;i<msg.length();i++){
      ans += m[msg[i]];
    }
    cout << ans << endl;
  }
}
