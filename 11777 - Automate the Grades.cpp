#include <bits/stdc++.h>
using namespace std;

int main() 
{
 int t, cs=1;
 cin >> t;
 while(t--){
   int a,b,c,d,e,f,g,res;
   char grd;
   cin >> a >> b >> c >> d >> e >> f >> g;
   res = a+b+c+d+ ((e+f+g)-min(min(e,f),g))/2;
   if(res >= 90) grd = 'A';
   else if(res >= 80) grd = 'B';
   else if(res >= 70) grd = 'C';
   else if(res >= 60) grd = 'D';
   else grd = 'F';
   
   cout << "Case " << cs++ << ": " << grd << endl;
 }
 return 0;
}
