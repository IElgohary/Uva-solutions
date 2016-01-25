/*input
3
1 2 3
4
1 2 3 4
0
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

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = a ; j < b ; j++ )
#define sz()  size()
#define printArr(array,n) for(int i = 0 ; i < n ; i++) cout << array[i]<<" ";

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	int sum[5000];
	priority_queue<int,vector<int>,greater<int> > que;
	while(n != 0)
	{

		FOR(0,n)
		{
			int tmp;
			cin >> tmp;
			que.push(tmp);
		}

		int i = 0;
		while (que.size() > 1)
		{
			int a , b;
			a = que.top();
			que.pop();
			b = que.top();
			que.pop();
			que.push(a + b);
			sum[i++]= a+b;
			//cout << "nums: "<< a << ' '<< b << " sum: "<< a+b <<endl;
		}

		int res = 0;
		FOR2(0, i)
			res += sum[j];
		
		cout << res << endl;
		que.pop();
		cin >> n;
	}	
	
}