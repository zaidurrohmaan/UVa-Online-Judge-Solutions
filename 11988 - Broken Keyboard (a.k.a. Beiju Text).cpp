#include <bits/stdc++.h>
using namespace std;

int main()
{  
    string line;
    while (getline(cin, line))
    {
        list<char> beiju;
        list<char>::iterator iter(beiju.begin());
        for (size_t i = 0; i < line.size(); ++i)
        {
            if (line[i] == '[')
                iter = beiju.begin();
            else if (line[i] == ']')
                iter = beiju.end();
            else
                beiju.insert(iter, line[i]);                
        }
        copy(beiju.begin(), beiju.end(), ostream_iterator<char>(cout, ""));
        cout << endl;
    }
    return 0;
}
