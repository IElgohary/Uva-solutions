/*input
5
1 2 3 4 5
5 4 1 2 3
1 4 3 2 5
3 4 2 5 1
3 4 2 1 5
4 3 5 2 1
0
3
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
0
4
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
0
10
5 7 10 9 8 6 4 3 2 1
5 6 4 8 7 3 2 9 1 10
0
0
*/


#include <stdio.h>
#include <cmath>
#include <set> 
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;


#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = 0 ; j < b ; j++)
#define INF 1000000000

typedef long long ll;
typedef std::pair<int,int> ii;

int n;
stack<int> station;
int arr[1005];

int main()
{
	cin >> n;
	while ( n != 0)
	{
		cin >> arr[0];

		while (arr[0] != 0)
		{
			while(!station.empty())
			station.pop();

			FOR(1 , n)
				cin >> arr[i];


			int j = 1;
			int i = 0;
			while ( j <= n && i < n)
			{
				station.push(j);
				while(!station.empty() && station.top() == arr[i])
				{
					station.pop();
					i++;
				}
				j++;

			}	

			for(;i < n; i++)
			{
				if(arr[i] == station.top())
					station.pop();
			}

			if (!station.empty())
			{
				cout << "No"<< endl;
			}
			else
			{
				cout << "Yes" << endl;
			}

			cin >> arr[0];
			
		}

		cout << endl;
		cin >> n;
	}
}