/*input
*/


#include <stdio.h>
#include <cmath>
#include <set> 
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
using namespace std;


#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = a ; j < b ; j++ )


typedef long long ll;
typedef std::pair<int,int> ii;

int main()
{
	int t, cas = 1;
	ios::sync_with_stdio(false);
	cin >> t;

	while (t != 0)
	{
		cout << "Scenario #"<< cas <<endl;
		cas++;
		map<int , int> mp;
		for ( int i = 0 ; i < t ; i++)
		{	
			int n;
			cin >> n;
			for ( int j = 0 ; j < n; j++)
			{
				int tmp;
				cin >> tmp;
				mp[tmp] = i;
			}
		}

		queue<int> que[2000];
		string s;
		cin >> s;
		while(s.compare("STOP") != 0)
		{

			if ( s.compare("ENQUEUE") == 0)
			{
				int tmp;
				cin >> tmp;
				for ( int i = 0 ; i < 2000; i++)
				{
					if (!que[i].empty() && que[i].front() != -1)
					{
						if(mp[que[i].front()] == mp[tmp])
						{
							que[i].push(tmp);				
							break;
						}

					}
					else if ( que[i].front() != -1)
					{
						que[i].push(tmp);
						break;
					}

				}
			}
			else
			{
				for(int i = 0 ; i < 2000 ;i++)
				{
					if(!que[i].empty() && que[i].front() != -1)
					{
						cout << que[i].front() <<endl;
						que[i].pop();
						if(que[i].empty())
								que[i].push(-1);
						break;
					}
				}
			}

			cin >> s;
		}
		cout << endl;
		cin >> t;
	}
}