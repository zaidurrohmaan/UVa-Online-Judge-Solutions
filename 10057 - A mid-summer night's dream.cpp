#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long

int main() 
{
  int n;
  while(cin >> n){
    int arr[n], median, val, count = 0, mid;
    memset(arr, 0, sizeof(arr));
    
    for(int i=0;i<n;i++){
      cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    if(n%2==1){
      mid = n/2;
      val = 1;
      for(int i=0; i<n; i++){
        if(arr[i] == arr[mid]) count++;
      }
    }
    else{
      mid = n/2-1;
      val = arr[mid+1] - arr[mid] + 1;
      for(int i=0; i<n;i++){
        if(arr[i] == arr[mid] || arr[i] == arr[mid+1]) count++;
      }
    }
    
    cout << arr[mid] << " " << count << " " << val << endl;
  }
}
