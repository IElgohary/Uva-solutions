/*input
8
2
4
*/

#include <stdio.h>
#include <math.h>
using namespace std;

int arr[] ={10,100,1000,10000};
int n;
int a, order;

int len(int n)
{
	unsigned int number_of_digits = 0;

	do {
	     ++number_of_digits; 
	     n /= 10;
	} while (n);
	return number_of_digits;
}

int fun(int t1 , int t2)
{
	return (t1 + t2)*(t1 + t2);
}

int main()
{
	while(scanf("%d", &n)!= EOF)
	{
		switch(n)
		{
			case 2: order = 0; break;
			case 4: order = 1; break;
			case 6: order = 2; break;
			case 8: order = 3; break; 
		}

		int mod = pow(10,n);
		double limit = 99999999 % mod;
	//	printf("limit : %f\n", limit);
		for ( a = 0 ; a <= limit; a++)
		{
			int t1 = a%arr[order];
			int t2 = a/arr[order];
			if ( fun(t1,t2)  == a)
			{
				int ln = len(a);	
				for ( ;ln < n ; ln++)
				{
					printf("0");
				}
				printf("%d\n",a);
			}	

		}

	}
}



