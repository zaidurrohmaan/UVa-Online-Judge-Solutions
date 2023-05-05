#include <bits/stdc++.h>
using namespace std;

int main() 
{
  string s;
  while(cin >> s, s != "#"){
    if(next_permutation(s.begin(), s.end())){
      cout << s;
    }
    else cout << "No Successor";
    
    cout << endl;
  }
}
