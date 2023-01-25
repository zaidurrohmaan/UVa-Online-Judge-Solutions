#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() 
{
    int n,  b, tmp;
    set<int> absDifference;
    vector<int> ball;
  
    while(cin >> n >> b, (n || b)){
      
      for(int i=0;i<b;i++){
        cin >> tmp;
        ball.pb(tmp);
      }
      
      for(int i=0;i<b;i++){
        for(int j=i;j<b;j++){
          absDifference.insert(abs(ball[i] - ball[j]));
        }
      }
      
      if(absDifference.size() == n+1) cout << "Y" << endl;
      else cout << "N" << endl;
      
      ball.clear();
      absDifference.clear();
    }
}
