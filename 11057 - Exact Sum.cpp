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
	
	int n;
	while(cin >> n){
	vector<int> price(n);
	for(int i=0;i<n;i++){
		cin >> price[i];
	}
  sort(price.begin(), price.end());
    
	int m;
	cin >> m;
	
	int p1, p2, low, high;
	low = price.front();
	high = price.back();

	for(int i=0;i<n;i++){
		p1 = price[i];
		p2 = m - p1;
		if(p1 > p2) break;

		if(binary_search(price.begin() + i + 1, price.end(), p2)){
			if(p2 - p1 < high - low){
				low = p1;
				high = p2;
			}
		}
	}
  
  cout << "Peter should buy books whose prices are " 
			 << low
			 << " and "
			 << high
			 <<".\n\n";
	}
	return 0;
}
