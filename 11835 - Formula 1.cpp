#include <bits/stdc++.h>
using namespace std;

int order[105][105];
int score[105];

int main() 
{
 int G, P, S, K, position, sc;
 
 while(cin >> G >> P, (G||P)){
   memset(order, 0, sizeof(order));
   memset(score, 0, sizeof(score));
   for(int i=0;i<G;i++){
     for(int j=1;j<=P;j++){
       cin >> position;
       order[i][position-1] = j;
     }
   }
   
   cin >> S;
   while(S--){
     cin >> K;
     memset(score, 0, sizeof(score));
     for(int i=0;i<K;i++){
       cin >> sc;
       for(int j=0;j<G;j++){
         score[order[j][i]] += sc;
       }
     }
     
     vector<int> champion;
     int max = -1;
     
     for(int i=1;i<=P;i++){
       if(score[i] > max){
         champion.clear();
         champion.push_back(i);
         max = score[i];
       }
       else if(score[i] == max){
         champion.push_back(i);
       }
     }
     
     cout << champion[0];
     
     for(int i=1;i<champion.size();i++){
       cout << " " << champion[i];
     }
     
     cout << endl;
   }
 }
}
