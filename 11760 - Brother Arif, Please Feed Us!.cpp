#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c, n, a, b, cs=1;
  bool left, right, above, below, current;// can escape to ...
  bitset<10001> row, col;
  while(cin >> r >> c >> n, (r||c||n)){
    row.reset();
    col.reset();
    
    for(int i=0;i<n;i++){
      cin >> a >> b;
      row.set(a,true);
      col.set(b,true);
    }
    
    left = right = above = below = current = true;
    
    cin >> a >> b;
    
    if(a-1 >= 0){
      if(row[a-1]) above = false;
    }
    else above = false;
    
    if(a+1 < r){
      if(row[a+1]) below = false;
    }
    else below = false;
    
    if(b-1 >= 0){
      if(col[b-1]) left = false;
    }
    else left = false;
    
    if(b+1 < c){
      if(col[b+1]) right = false;
    }
    else right = false;
    
    if(row[a]){
      current = false;
      left = false;
      right = false;
    } 
    
    if(col[b]){
      current = false;
      above = false;
      below = false;
    }
    
    cout << "Case " << cs++ << ": ";
    if(current||above||below||left||right) cout << "Escaped again! More 2D grid problems!\n";
    else cout << "Party time! Let's find a restaurant!\n"; 
  }
}
