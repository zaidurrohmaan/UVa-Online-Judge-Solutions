#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
map<string, bool> ignored;
vector<string> title;
vector<pair<pair<string, int>, pair<int, int>>> kwic;{kwic word, title number, first index of kwic word, last index of kwic word};

bool comparator(pair<pair<string, int>, pair<int, int>> a, pair<pair<string, int>, pair<int, int>> b){
  if(a.first.first == b.first.first){
    if(a.first.second == b.first.second) return a.second.first < b.second.first;
    else return a.first.second < b.first.second;
  }
  else return a.first.first < b.first.first;
  // sort priority: kwic word; if tie then title number; if tie then first index of kwic word.
}

string toLower(string s) {
	for (int i = 0; i < s.length(); i++)if (s[i] >= 'A'&&s[i] <= 'Z'){
	  s[i] += 'a' - 'A';
	}
	return s;
}

int main() 
{
  string s, word, ss, outp;
  while(getline(cin, s) && s!="::") ignored[toLower(s)] = true;
  
  int n=-1;
  while(getline(cin, s) && s != "::"){
    n++;
    s = toLower(s);
    title.pb(s);
    word = "";
    for(int i=0;i<=s.length();i++){
      if(i == s.length() || s[i] == ' '){
        if(!ignored[word]){
          kwic.pb(mp(mp(word, n), mp(i-word.size(),i-1)));
        } 
        word = "";
      }
      else word += s[i];
    }
  }
  
  sort(kwic.begin(), kwic.end(), comparator);
  
  int len = kwic.size();
  for(int i=0; i<len; i++){
    outp = "";
    ss = title[kwic[i].first.second];
    for(int j=0;j<ss.length();j++){
      if(j>=kwic[i].second.first && j<=kwic[i].second.second){
        outp += ss[j] + 'A' - 'a';
      }
      else outp += ss[j];
    }
    
    cout << outp << endl;
  }
  
}
