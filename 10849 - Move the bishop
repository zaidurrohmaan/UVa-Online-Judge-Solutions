#include <bits/stdc++.h>
#define ll long long
using namespace std;

string color(ll r, ll c){
  if(r%2==0){
    if(c%2==0){
      return "white";
    }
    else{
      return "black";
    }
  }
  else{
    if(c%2==0){
      return "black";
    }
    else{
      return "white";
    }
  }
}

int main() {
	ll tc;
	cin >> tc;
	
	while(tc--){
	  
	  ll t, n, r, c, R, C;

	  cin >> t >> n;
	  while(t--){
	    
	    cin >> r >> c >> R >> C;
	    if(color(r,c) != color(R,C))
	      cout << "no move" << endl;
	      
	    else{
	       if(r==R && c==C)
	        cout << 0 << endl;
	       else if(abs(r-R) == abs(c-C))
	        cout << 1 << endl;
	       else
	        cout << 2 << endl;
	    }
	      
	  }
	  
	  
	}
	return 0;
}
