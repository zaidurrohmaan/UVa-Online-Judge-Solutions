#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n, num;
  while(cin >> n, n){
    int arr[n];
    for(int i=0;i<n;i++){
      cin >> arr[i];
    }
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr+n); //min heap priority queue
    
    int cost = 0;
    while(pq.size() > 1){
      int a,b;
      a = pq.top();
      pq.pop();
      b=pq.top();
      pq.pop();
      
      cost += a+b;
      pq.push(a+b);
    }
    cout << cost << endl;
    pq.pop();
  }
    
}
