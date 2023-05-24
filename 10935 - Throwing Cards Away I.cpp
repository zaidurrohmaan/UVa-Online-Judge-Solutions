#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n;
  deque<int> deck;
  while(cin >> n, n){

    for(int i=1;i<=n;i++){
      deck.push_back(i);
    }
    
    cout << "Discarded cards:";

    while(deck.size() >= 2){
      cout << " " << deck.front();
      deck.pop_front();
      if(deck.size() > 1) cout << ",";
      else break;
      
      deck.push_back(deck.front());
      deck.pop_front();
      if(deck.size() == 1) break;
    }
    
    cout << "\nRemaining card: ";
    cout << deck.front() << endl;
    deck.pop_front();
  }
    
}
