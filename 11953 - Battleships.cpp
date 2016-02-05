/*input
11
5
x....
x....
.....
.....
.....
6
....@.
.@...x
@.@@@.
@.....
@..@.@
.x.x..
8
@@@..@..
.....x..
..x..x.@
x..@x...
x.@..xx.
.......x
@@.....x
..x.@...
6
x@x...
......
......
......
......
......
8
.@x@@..@
@......x
@.x@..x.
x.....@.
.....@.x
x.x@@..x
.....x.@
x..x....
4
x.x.
x...
x...
..x@
8
...x.x..
.....@..
@x@@.@..
.....@..
.@..x.xx
.x......
..x.@x@@
@..x....
1
x
10
..@.@x..@.
..x.......
.@....@..x
..x.@.@..x
..x..x.@..
......x..@
...@.....@
@..@.....x
.@.x.....@
@.@.....x.
3
x..
...
@.@
5
...@.
..@..
.@...
.x.@.
.x...
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
#include <map>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <functional>

using namespace std;

#define r(input) freopen("input.txt","r",stdin)
#define w(output) freopen("output.txt","w",stdout)
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = a ; j < b ; j++ )
#define sz()  size()
#define printArr(array,n) for(int i = 0 ; i < n ; i++) cout << array[i]<<" ";
#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)
#define count(i) __builtin_popcount(i)
#define Sort(v) sort(v.begin(),v.end())
#define cover(a,d) memset(a,d,sizeof(a))


#define VISITED 1
#define UNVISITED 0

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;


char grid[100][100];
int n;
int dx[] = {0,1,0, -1};
int dy[] = {1,0,-1, 0}; 

bool valid(int x , int y)
{
	if(x >= n || x < 0 || y>=n || y<0 || grid[x][y] == '.' )
		return false;
	return true;
}

int floodfill(int x , int y)
{
	if(!valid(x,y))
		return 0;
	int ans = 0;
	if ( grid[x][y] == 'x')
		ans = 1;
	grid[x][y] = '.';
	FOR(0,4)
	{
		int nxt = floodfill(x + dx[i], y + dy[i]);
		ans = ans || nxt;
	}
	return ans;
}

int main()
{
	int tc;
	cin >> tc;

	for ( int test = 1 ; test <= tc ; test++)
	{
		cin >> n;
		FOR(0, n)
			FOR2(0,n)
				cin >> grid[i][j];
		int ships = 0;
		FOR(0,n)
			FOR2(0,n)
				if(grid[i][j] != '.')
					ships += floodfill(i,j);
			
		cout << "Case "<< test<<": "<< ships<< endl;

	}
	
}