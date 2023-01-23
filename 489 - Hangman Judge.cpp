#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() 
{
    int n;
    
    while(cin >> n, n!= -1){
      
      string word, guess, result;
      bool foundMatch, winOrLose = false;
      int correct = 0, wrong = 0, wordSize = word.length(), guessSize = guess.length();
      
      cin >> word >> guess;
      
      vector<bool> solved(wordSize, false);
      
      for(int i=0; i<guessSize; i++){
        
        foundMatch = false;
        
        for(int j=0;j<wordSize;j++){
          if(guess[i] == word[j]){
            if(!solved[j])
              correct++;
              solved[j] = true;
            
            foundMatch = true;
          }
        }
        
        if(!foundMatch)
          wrong++;
        
        
        if(wrong == 7){
          result = "You lose.";
          winOrLose = true;
          break;
        }
        else if(correct == wordSize){
          result = "You win.";
          winOrLose = true;
          break;
        }
      }
      
      if(!winOrLose)
        result = "You chickened out.";
      
      printf("Round %d\n", n);
      cout << result << endl;
    }
    
    return 0;
}
