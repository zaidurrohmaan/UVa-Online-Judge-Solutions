/*
Thanks to ajahuang (https://github.com/ajahuang/UVa/blob/master/UVa%20417%20-%20Word%20Index.cpp)
*/

#include <bits/stdc++.h>
using namespace std;

map<string,int> wordMap;
int skor;

void enumerateString(string s, int len){
  if(s.size() == len){
    wordMap[s] = skor++;
    return;
  }
  
  char lastLetter;
  if(s.empty()){
    lastLetter = 'a';
  }
  else{
    lastLetter = s[s.size()-1] + 1;
  }
  
  for(char c=lastLetter;c<='z';c++){
    enumerateString(s+c, len);
  }
}

int main() 
{
  skor=1;
  for(int len=1;len<=5;len++){
    enumerateString("",len);
  }
  string word;
  while(cin >> word){
    cout << wordMap[word] << endl;
  }
}
