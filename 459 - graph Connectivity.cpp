#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

map < char, int > code;
map < int , char> rev;
vector<int> arr[26];
int visited [26] = {0};
int mx;

void dfs(int a )
{
    visited[a] = 1;

    for ( int i = 0 ; i < arr[a].size(); i++)
    {
        if ( visited[arr[a][i]]== 1) continue;
            dfs(arr[a][i]);
    }
}


int main()
{
     for(int i = 0; i < 26; ++i)
    {
        code['A'+ i] = i ;
        rev [i] = (char)'A' + i;
    }


    int tc;
    cin >> tc;
    cin.ignore(1000, '\n');

    while ( tc--)
    {
        for ( int i = 0 ; i < 26;i++)
            visited[i] = 0;

        for ( int i = 0 ; i < 26 ; i++)
            arr[i].clear();

        mx = 0;
        char last;
        cin >> last;
        string l;
        cin.ignore(1000, '\n');
        while ( getline(cin , l) && l.length() > 0)
        {
            char a , b;
            istringstream ss(l);
            ss >> a >> b;
            arr[code[a]].push_back(code[b]);
            arr[code[b]].push_back(code[a]);
        }

        for ( int i = 0 ; i <= code[last] ; i++)
        {

            if ( visited[i] == 0)
            {
                dfs (i);
                mx++;
            }

        }


        cout << mx <<endl;
        if ( tc)
            cout << endl;
    }


    return 0;
}


