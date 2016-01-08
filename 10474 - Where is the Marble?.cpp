/*input
10 5 

1 
1 
3 
5 
7 
1 
3 
9 
120 
1 

1 
3 
120 
7 
1234 

10 12 

1111 
1111 
1111 
5 
5 
5 
10 
11 
12 
10 

1111 
5 
10 
11 
12 
1111 
134 
567 
246 
24 
12 
435 
0 0
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[10000];
int  m, q;
int c = 0;

int binarys(int n, int up , int low)
{

	int mid = (up + low)/2;
	while ( up >= low)
	{	
		if ( n == arr[mid])
		{
			while (mid >=0 && arr[mid-1] == arr[mid])
				mid--;
			return mid;
		}	
		else if ( n > arr[mid])
			low = mid + 1;
		else
			up = mid - 1;
		mid = (low + up)/2;
	}

	return -1;
}

int main()
{
	while ( true)
	{
		scanf("%d %d", &m , &q);
		if ( m == 0 && q == 0) break;
		printf("CASE# %d:\n", ++c);

		for ( int i = 0 ; i < m ; i++)
			scanf("%d", &arr[i]);
		sort( arr , arr+m);

		for ( int i = 0 ; i < q ; i++)
		{
			int n;
			scanf("%d" , &n);
			int tmp = binarys(n , m, 0);
			if ( tmp == -1)
				printf("%d not found\n", n);
			else
				printf("%d found at %d\n", n , tmp+1);

		}

	}
}