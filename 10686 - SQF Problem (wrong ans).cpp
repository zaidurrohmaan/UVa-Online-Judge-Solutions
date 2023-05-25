#include <bits/stdc++.h>
using namespace std;

string tokenize(string s){
  string ret = "";
  int len = s.length();
  for(int i=0;i<len;i++){
    if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')){
      ret += s[i];
    }
  }
  
  return ret;
}

int main() 
{
  int n;
  cin >> n;
  while(n--){
    int c;
    cin >> c;
    map<string,string> inCat;
    map<string,int> catCount, minim;
    vector<string> vcat;
    map<string, vector<string>> mvs; //keyword, category
    map<string, vector<string>>::iterator it;
    
    while(c--){
      string s;
      int w, p;
      cin >> s >> w >> p;
      vcat.push_back(s);
      minim[s] = p;
      catCount[s] = 0;
      while(w--){
        string kw;
        cin >> kw;
        mvs[kw].push_back(s);
      }
    }
    cin.ignore();
    
    string problem;
    while(getline(cin, problem)){
      if(problem.length() == 0)break;
      
      stringstream ss(problem);
      string wordCheck;
      while(ss >> wordCheck){
        for(it=mvs.begin();it!=mvs.end();it++){
          if(wordCheck.find(it->first) != wordCheck.length()){
            if(mvs[it->first].size() > 0){
              for(int i=0;i<mvs[it->first].size();i++){
                catCount[mvs[it->first][i]]++;
              }
            }
          }
        }
      }
    }
    
    vector<string> finalCat;
    bool sqf = true;
    for(int i=0;i<vcat.size();i++){
      if(catCount[vcat[i]] >= minim[vcat[i]]){
        finalCat.push_back(vcat[i]);
        sqf = false;
      }
    }
    
    if(sqf) cout << "SQF Problem." << endl;
    else{
      for(int i=0;i<finalCat.size();i++){
        if(i) cout << ",";
        cout << finalCat[i];
      }
    }
    
    cout << endl;
    finalCat.clear();
    vcat.clear();
    inCat.clear();
    catCount.clear();
    minim.clear();
    mvs.clear();
  }
}
