#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define vi vector<int>

int main() 
{
  map<char, double> table;
  map <char, double>::iterator it;
  
  int n, len, k, m;
  double val, pay;
  char c;
  string article;
  cin >> n;
  
  while(n--){
    
    pay = 0;
    
    cin >> k;
    
    while(k--){
      cin >> c;
      cin >> val;
      table[c] = val;
    }
    
    cin >> m;
    cin.ignore();
    
    while(m--){
      article = "";
      getline(cin, article);
      
      len = article.size();
      
      for(int i=0; i<len; i++){
        if(table[article[i]]) pay += table[article[i]];
      }
    }
    
    pay /= 100;
    printf("%0.2lf$\n", pay);
    table.clear();
  }
}
