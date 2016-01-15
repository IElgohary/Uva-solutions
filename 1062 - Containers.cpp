/*input
A
CBACBACBACBACBA
CCCCBBBBAAAA
ACMICPC
end
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
using namespace std;


#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = a ; j < b ; j++ )


typedef long long ll;
typedef std::pair<int,int> ii;

int main()
{
	stack<char> arr[1000];
	string in;
	
	ios::sync_with_stdio(false);
	cin >> in;
	int cas = 1;
	while (in.compare("end") != 0)
	{
		FOR(0 , 1000)
			arr[i].push('0');
	
		int count = 0, index;
		FOR(0 , in.size())
		{
			FOR2(0, 1000)
			{
				if(arr[j].top() == '0')
				{
					index = j;
					count++;
					break;
				}
				else if(arr[j].top() >= in[i])
				{
					index = j;
					break;
				}

			}

			arr[index].push(in[i]);
		}

		cout <<"Case "<< cas << ": " <<count << endl;
		cas++;
		cin >> in;
	}

}