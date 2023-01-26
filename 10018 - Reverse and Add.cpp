#include <bits/stdc++.h>
//#include <string>
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

bool isPalindrome(ll num){
  string sNum = to_string(num);
  ll len = sNum.length();
  
  for(ll i=0;i<len/2;i++){
    if(sNum[i] != sNum[len-i-1]){
      return false;
    }
  }
  
  return true;
}

int main() 
{
    ll n, num, it, tmp;
    cin >> n;
    
    while(n--){
      
      cin >> num;
      
      ll reverseNumber = reverseNum(num);
      
      it = 0;
      
      while(true){
        
        it++;
        num += reverseNumber;
        reverseNumber = reverseNum(num);
        
        if(reverseNumber == num) break;
        
      }
      
      cout << it << " " << num << endl;
    }
}
