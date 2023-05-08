#include <bits/stdc++.h>
using namespace std;

#define pb push_back

bool comparator(string a, string b){
  return a+b > b+a;
}

int main() 
{
    int n;
    vector<string> v;
    string inp;
    while(cin >> n, n){
      while(n--){
        cin >> inp;
        v.pb(inp);
      }
      
      sort(v.begin(), v.end(), comparator);
      
      for(int i=0;i<v.size();i++){
        cout << v[i];
      }
      
      cout << endl;
      v.clear();
    }
}
