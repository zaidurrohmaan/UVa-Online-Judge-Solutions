#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n;
  while(cin >> n){
    string s;
    set<string> file;
    int width = 0;
    for(int i=1;i<=n;i++){
      cin >> s;
      file.insert(s);
      if(s.length() > width) width = s.length();
    }
    
    
    cout << "------------------------------------------------------------" << endl;
    width = min(60, width+2);
    int idx = 0, m = 60/width;
    string f[n];
    for(set<string>::iterator i = file.begin(); i!=file.end(); i++){
      f[idx++] = *i;
    }
    
    int l = n/m + (n%m != 0);
    for(int i=0; i<l; i++){
      for(int j=0; i+j<n; j+=l){
        cout << left << setw(width) << f[i+j];
      }
      cout << endl;
    }
  }
}
