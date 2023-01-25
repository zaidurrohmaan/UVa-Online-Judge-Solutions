#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

bool isPalindrome(string s){
    int size = s.size();
    
    for(int i=0;i<size/2;i++){
      if(s[i] != s[size-i-1])
        return false;
    }
      
    return true;
}
    
int main() 
{
    string s;
    int len;
    set<string> palindrome;
    
    while(getline(cin, s)){

      int len = s.size();
      string tmp;
      
      int count = 0;
      for(int i=0;i<len;i++){
        
        tmp = "";
        
        for(int j=i;j<len;j++){
          
          tmp += s[j];
          
          if(isPalindrome(tmp) && palindrome.find(tmp) == palindrome.end()){
              count++;
              palindrome.insert(tmp);
          }
          
        }
        
      }
      
      cout << "The string '" << s << "' contains " << count << " palindromes.\n";
      
      palindrome.clear();
    }
}
