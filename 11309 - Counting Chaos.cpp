#include <bits/stdc++.h>
//#include <string>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
  
bool isPalindrome(int num){
  string sNum = to_string(num);
  int len = sNum.length();
  
  if(len == 1) return true;
  
  for(int i=0;i<len/2;i++){
    if(sNum[i] != sNum[len-i-1]){
      return false;
    }
  }
  
  return true;
}

int main() 
{
    int n;
    cin >> n;
    
    string s;
    
    for(int tc = 1; tc <= n; tc++){
      
      cin >> s;
      
      int hh, mm;
      
      //parsing hours and minutes
      hh = int(s[0] - '0') * 10 + int(s[1] - '0');
      mm = int(s[3] - '0') * 10 + int(s[4] - '0');
      
      bool stop = false;
      int hour, minute;
      
      for(int i = hh; i<= 24; i++){
        for(int j = mm + 1; j<=60; j++){
          
          //converting time to one integer
          int time = i * 100 + j;
          
          if(isPalindrome(time)){
            hour = i;
            minute = j;
            stop = true;
            break;
          }
          
          if(j == 59 || j == 60){
            if(i == 23) i=0;
            else i++;
            j = -1;
          } 
          
        }
        
        if(stop) break;
        if(i == 23 || i == 24) i = -1;
        
      }
      
      //printing hour and minute in 2 digits representation
      printf("%02d:%02d\n", hour, minute);
    }
}
