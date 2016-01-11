/*input
2
10 3
2 6 7
214 7
11 12 7 13 176 23 191
*/

#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(a , b) for(int i = a ; i < b; i++ )

int arr[1000005]; 
int sdist[1000005];
int ldist[1000005];
int t , l , n;

int main()
{
	scanf("%d" , &t);
	while ( t--)
	{
		scanf("%d %d", &l , &n);
		FOR(0 , n)
		{
			scanf("%d", &arr[i]);
			if ( arr[i] >= (l/2))
			{
				sdist[i] = l - arr[i];
				ldist[i] = arr[i];
			} 
			else
			{
				sdist[i] = arr[i];
				ldist[i] = l - arr[i];
			}

		}	

		int less = sdist[0] , most = ldist[0];

			FOR(1 , n)
			{
				less = max(sdist[i] , less);
				most = max(ldist[i] , most);
			}

			printf("%d %d\n", less , most);

		
	}
}