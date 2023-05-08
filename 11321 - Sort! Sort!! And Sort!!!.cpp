#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int m;
bool comparator(int a, int b){
  
  if(a%m != b%m) return a%m < b%m;
  else{
    if(abs(a)%2 == 0 && abs(b)%2 == 0) return a<b;
      
    else if(abs(a)%2 != 0 && abs(b)%2 != 0) return a>b;
      
    else if(abs(a)%2 != 0) return true;
      
    else return false;
  }
}

int main() 
{
 int n, num;
 while(cin >> n >> m){
   cout << n << " " << m << endl;
   if(!n && !m) break;
   
   vector<int> v;
   for(int i=0;i<n;i++){
     cin >> num;
     v.pb(num);
   }
   
   sort(v.begin(), v.end(), comparator);
   
   for(int i=0;i<v.size();i++){
     cout << v[i] << endl;
   }
 }
 
 return 0;
}
