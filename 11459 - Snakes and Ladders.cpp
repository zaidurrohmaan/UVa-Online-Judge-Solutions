#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() 
{
    int testcase, numOfPlayers, numOfSnakeLadders, numOfDiceRolled, start, end, player;
    bool gameActive;
    map<int, int> map;
    vector<int> position;
  
    cin >> testcase;
    
    while(testcase--){
      
      gameActive = true;
      player = 0;
      
      cin >> numOfPlayers >> numOfSnakeLadders >> numOfDiceRolled;
      
      //initial position of all players
      for(int i=0;i<numOfPlayers;i++){
        position.pb(1);
      }
      
      //mapping snake and ladder position
      while(numOfSnakeLadders--){
        cin >> start >> end;
        
        map[start] = end;
      }
      
      for(int i = 1; i<=numOfDiceRolled; i++){
        int dice;
        cin >> dice;
        
        if(gameActive){
          position[player] += dice;
        
          if(map[position[player]] != 0){
            position[player] = map[position[player]];
          }
        }
        
        if(position[player] >= 100){
          gameActive = false;
          position[player] = 100;
        } 
        
        if(player == numOfPlayers-1) player = 0;
        else player++;
      }
      
      for(int i=0;i<numOfPlayers;i++){
        printf("Position of player %d is %d.", i+1, min(position[i], 100));
        cout << endl;
      }
      
      position.clear();
      map.clear();
    }
}
