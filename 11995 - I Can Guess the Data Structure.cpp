#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n;
  while(scanf("%d", &n) != EOF){
    stack<int> st;
    queue<int> qu;
    priority_queue<int> pq;
    
    bool s,q,p;
    s=q=p=true;
    
    int operation, x;
    for(int i=0;i<n;i++){
      cin >> operation >> x;
      if(operation==1){
        st.push(x);
        qu.push(x);
        pq.push(x);
      }
      else{
        if(s && st.empty()){
          s = false;
        }
        else if(s && st.top() != x){
          s = false;
        }
        else if(s && st.top() == x){
          st.pop();
        }
        
        if(q && qu.empty()){
          q = false;
        }
        else if(q && qu.front() != x){
          q = false;
        }
        else if(q && qu.front() == x){
          qu.pop();
        }
        
        if(p && pq.empty()){
          p = false;
        }
        else if(p && pq.top() != x ){
          p = false;
        }
        else if(p && pq.top() == x){
          pq.pop();
        }
      }
    }
    
    int skor = 0;
    if(s) skor++;
    if(q) skor++;
    if(p) skor++;
    
    if(skor==0){
      cout << "impossible" << endl;
    }
    else if(skor==1){
      if(s) cout << "stack" << endl;
      else if(q) cout << "queue" << endl;
      else if(p) cout << "priority queue" << endl;
    }
    else{
      cout << "not sure" << endl;
    }
    
    
  }
}
