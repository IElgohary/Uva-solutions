#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> arr[200];
int n;

bool bfs(int source )
{
	queue<int> q;
	q.push(source);
    int color[200];
    fill( color , color + n ,-1);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for ( int i = 0 ; i < arr[u].size() ; i++)
        {
            int v = arr[u][i];
            if ( color[v] == -1 )
            {

                color[v] = 1 - color[u];
                q.push(v);
            }

            if ( color [v] == color[u])
            	return false;
        }
    }

    return true;
}



int main()
{
    while ( true)
    {
        for ( int i = 0 ; i < 200 ; i++)
            arr[i].clear();

        cin >> n;

        if ( n == 0)
            break;

        int l;
        cin >> l;

        while (l--)
        {
            int a , b;
            cin >> a>> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        if ( bfs(0))
            cout << "BICOLORABLE."<<endl;
        else
            cout << "NOT BICOLORABLE."<<endl;
    }
    return 0;
}