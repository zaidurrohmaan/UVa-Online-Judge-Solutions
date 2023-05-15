#include <bits/stdc++.h>
using namespace std;

string word, anagram;

void dfs(string a, string b, string stack, string path, int n){
  if(n == word.length()*2){
    if(b == anagram){
      cout << path << endl;
    }
    return;
  }
  
  //push
  if(a.length() > 0){
    dfs(a.substr(1, a.length()-1), b, stack + a[0], path + (n==0? "i" : " i"), n+1);
  }
  
  //pop
  if(stack.length() > 0 && stack[stack.length()-1] == anagram[b.length()]){
    dfs(a, b + stack[stack.length()-1], stack.substr(0, stack.length()-1), path + " o", n+1);
  }
}

int main() 
{
  while(cin >> word >> anagram){
    cout << "[\n";
    if(word.length() == anagram.length()){
      dfs(word, "", "", "", 0);
    }
    cout << "]\n";
  }
}
