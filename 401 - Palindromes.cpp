#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

static map<char, char> mirror; 

bool isPalindrome(string s){
    int size = s.size();
    
    for(int i=0;i<size/2;i++){
      if(s[i] != s[size-i-1])
        return false;
    }
      
    return true;
}

bool isMirrored(string s){
  int size = s.size();
    
    for(int i=0;i<(size+1)/2;i++){
      if(mirror[s[i]] != s[size-i-1])
        return false;
    }
      
  return true;
}

int main() 
{
    
    char from[] = {'A', 'E', 'H', 'I', 'J', 'L',
                   'M', 'O', 'S', 'T', 'U', 'V',
                   'W', 'X', 'Y', 'Z', '1', '2',
                   '3', '5', '8'};
    char to[]   = {'A', '3', 'H', 'I', 'L', 'J',
                   'M', 'O', '2', 'T', 'U', 'V',
                   'W', 'X', 'Y', '5', '1', 'S', 
                   'E', 'Z', '8'};

    for (size_t i = 0; i < sizeof(from) / sizeof(char); ++i)
        mirror[from[i]] = to[i];
    
    string s;

    while(getline(cin, s)){
      
      bool pal = isPalindrome(s);
      bool mir = isMirrored(s);
      
      cout << s << " -- is ";
      if(!pal && !mir)
        cout << "not a palindrome.";
      else if(pal && !mir)
        cout << "a regular palindrome.";
      else if(!pal && mir)
        cout << "a mirrored string.";
      else if(pal && mir)
        cout << "a mirrored palindrome.";
      
      cout << endl;
      cout << endl;

    }
}
