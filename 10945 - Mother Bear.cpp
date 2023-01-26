#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

ll reverseNum(ll num){
  ll res = 0;
  while(num > 0){
    res *= 10;
    res += num%10;
    num /= 10;
  }
  
  return res;
}

bool isPalindrome(string s){

  ll len = s.length();
  
  for(ll i=0;i<len/2;i++){
    if(s[i] != s[len-i-1]){
      return false;
    }
  }
  
  return true;
}

int main() 
{
    string s;
    
    while(getline(cin, s)){
      
      if(s == "DONE") break;
      
      string ss = "";
      int len = s.length();
      
      for(int i=0;i<len;i++){
        if((s[i]>=65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)){
          ss += tolower(s[i]);
        }
      }
      
      if(isPalindrome(ss)) cout << "You won't be eaten!" << endl;
      else cout << "Uh oh.." << endl;
    }
}
