#include <bits/stdc++.h>

using namespace std;

int n , m;
int arr[10005];
int sol[10005];
int val[2000005] = {0};
int a , b;

int main()
{
	
	while(scanf("%d" , &n) != EOF)	
	{
		memset(val , 0 , sizeof(val)/sizeof(bool));
		for ( int i = 0 ; i < n ; i++)
		{
			scanf("%d", &arr[i]);
			val[arr[i]]++;
			//printf("%d ", arr[i]);
		}
		scanf("%d" , &m);
		sort( arr , arr+n);	
		int k;
		int b1;
		int mn = 10000000;
		for ( k = 0 ; k < n ; k++)
		{
			if ( arr[k] > m) break;

			val[arr[k]]--;
			int t = m - arr[k];
			if (val[t])
				sol[k] = abs(arr[k] - t);
			else	sol[k] = 10000000; //infinity

			if ( sol[k] < mn)
			{
				mn = sol[k];
				b1 = arr[k];
			}
		}
		int b2 = m - b1;
		printf("Peter should buy books whose prices are %d and %d.\n\n", b1 , b2);

		}
	

}