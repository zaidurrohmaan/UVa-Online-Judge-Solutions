#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(int argc, char const *argv[])
{		
	fastio;
	
	int t, n, c=1;
	cin >> t;
	while(t--){
		cin >> n;
		int a[100005] = {};
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		int k = 0;

    //find the maximum rung range
		for(int i=1;i<=n;i++){
			if(a[i] - a[i-1] > k) k = a[i] - a[i-1];
		}
    
		int ans = k;
		for(int i=1;i<=n;i++){
			if(a[i] - a[i-1] == k) k--;
			else if(a[i] - a[i-1] > k){
        ans++;
        break;
      }
		}

		cout << "Case " << c++ << ": " << ans << endl;
	}
	return 0;
}
