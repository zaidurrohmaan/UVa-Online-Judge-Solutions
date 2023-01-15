#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;


string queenMove(int a, int b, int c){
  
  if(a == b)
    return "Illegal state";
  
  vector<int> qmove, kmove;
  
  // King's Move
  if(a-8 >= 0) kmove.pb(a-8);
  if((a+1)%8 != 0) kmove.pb(a+1);
  if(a%8 != 0) kmove.pb(a-1);
  if(a+8 <= 63) kmove.pb(a+8);
  
  //Queen's Move
  int ver, hor;
  
  ver = b;
  while(ver >= 0){
    ver -= 8;
    if(ver >= 0 && ver != a) qmove.pb(ver);
    if(ver == a) break;
  }
  
  ver = b;
  while(ver <= 63){
    ver += 8;
    if(ver <= 63 && ver != a) qmove.pb(ver);
    if(ver == a) break;
  }
  
  hor = b;
  while(true){
    hor--;
    if((hor+1) % 8 == 0 || hor == a) break;
    qmove.pb(hor);
  }
  
  hor = b;
  while(true){
    hor++;
    if(hor % 8 == 0  || hor == a) break;
    qmove.pb(hor);
  }
  
  
  bool move = false;

  for(int i=0;i<qmove.size();i++){
    if(c == qmove[i]){
      move = true;
      break;
    }
  }
  
  if(!move) return "Illegal move";
  
  for(int i=0;i<kmove.size();i++){
    if(c == kmove[i])
      return "Move not allowed";
  }
  
  qmove.clear();
  
  ver = c;
  while(ver >= 0){
    ver -= 8;
    if(ver >= 0 && ver != a) qmove.pb(ver);
    if(ver == a) break;
  }
  
  ver = c;
  while(ver <= 63){
    ver += 8;
    if(ver <= 63 && ver != a) qmove.pb(ver);
    if(ver == a) break;
  }
  
  hor = c;
  while(true){
    hor--;
    if((hor+1) % 8 == 0 || hor == a) break;
    qmove.pb(hor);
  }
  
  hor = c;
  while(true){
    hor++;
    if(hor % 8 == 0  || hor == a) break;
    qmove.pb(hor);
  }
  
  int ruanggerakking = kmove.size();
  for(int i=0;i<kmove.size();i++){
    for(int j=0;j<qmove.size();j++){
      if(kmove[i] == qmove[j])
        ruanggerakking--;
    }
  }
  
  if(ruanggerakking > 0) return "Continue";
  else return "Stop";
  
  kmove.clear();
  qmove.clear();
}

int main() 
{
    int a,b,c;
    
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
      cout << queenMove(a,b,c) << endl;
    }
}
