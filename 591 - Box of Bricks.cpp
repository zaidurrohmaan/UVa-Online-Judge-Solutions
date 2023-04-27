#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define vi vector<int>

int main() 
{
  int n, total, avg, moved, zero=0, t=1;
  int stacks[55];
  
   while(cin >> n, n){
     total = 0;
     for(int i=1; i<=n; i++){
       cin >> stacks[i];
       total += stacks[i];
     }
     avg = total/n;
     moved = 0;
     for(int i=1; i<=n; i++){
       moved += max(zero, stacks[i]-avg);
     }
     
     cout << "Set #" << t++ << endl;
     cout << "The minimum number of moves is " << moved << "." << endl << endl;
   }
}
