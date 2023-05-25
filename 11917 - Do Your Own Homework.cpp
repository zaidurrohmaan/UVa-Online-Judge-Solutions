#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int tc;
  cin >> tc;
  int c=1;
  
  while(tc--){
    cout << "Case " << c++ << ": ";
    
    int n;
    cin >> n;
    map<string,int> sparrow;
    
    for(int i=0;i<n;i++){
      string subject;
      int time;
      cin >> subject >> time;
      sparrow[subject] = time;
    }
    
    int d;
    cin >> d;
    
    string soha;
    cin >> soha;
    
    if(sparrow[soha]<=d && sparrow[soha]!=0){
      cout << "Yesss" << endl;
    }
    else if(sparrow[soha] > d && sparrow[soha]<=d+5){
      cout << "Late" << endl;
    }
    else{
      cout << "Do your own homework!" << endl;
    }
    
    sparrow.clear();
  }
  
}
