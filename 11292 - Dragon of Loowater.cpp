/*input
2 3
5
4
7
8
4
2 1
5
5
10
0 0
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m, coins;
int dragons[20005];
int knights[20005];

int main()
{
	while(true)
	{
		coins = 0;
		scanf("%d %d", &n , &m);
		if ( n == m && n == 0)
			break;
		for (int i = 0 ; i < n ; i++)
			scanf("%d", &dragons[i]);
		for ( int i = 0 ; i < m ; i++)
			scanf("%d", &knights[i]);

		sort(dragons, dragons+n);
		sort(knights , knights + m);

		int k = 0, d= 0;
		while (d < n && k < m)
		{
			while (dragons[d] > knights[k] && k<m) k++;
			if (k == m) break;
			coins += knights[k];
			k++; d++;
		}
		if ( d == n) printf("%d\n", coins);
		else
			printf("Loowater is doomed!\n");

	}
}