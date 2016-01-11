/*input
2 3
6 3 8
3 5
51 19 27 14 33
5 9
1 2 3 5 7 11 13 17 19
2 4
335 501 170 725
4 7
963 465 706 146 282 828 962
2 4
943 828 437 392
5 3
154 293 383
12 4
2 4 5 6
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <math.h>

//#include <bits/stdc++.h>

using namespace std;

int C , S; 
double imb, am;
double arr[15];
int sol[5][10];
double tot[5];
int num = 1;
int main()
{
	while(scanf("%d %d", &C , &S) != EOF)
	{
		am = 0;
		imb = 0;
		int i = 0;
		for ( ; i < S ; i++)
		{
			scanf("%lf", &arr[i]);
			am += arr[i];
		}

		am = am / C;

		for ( ; i < 2*C;i++)
			arr[i] = 0;

		sort(arr, arr+ (2*C));

		for ( int j = 0 ; j < C ; j++)
		{
			sol[j][0] = arr[j];
			sol[j][1] = arr[2*C-1 - j];
			tot[j]= arr[j] + arr[2*C-1 - j];

		}
		
		for ( int j = 0 ; j < C ; j++)
		{
			imb += fabs(tot[j] - am);
		}

		printf("Set #%d\n", num);
		for ( int j = 0 ; j < C ; j++)
		{	
			printf("%2d:", j);
			for( int k = 0 ; k < 2 ; k++)
			{	
				if (sol[j][k] != 0)
					printf(" %d", sol[j][k]);
			}
			printf("\n");		
		}
		printf("IMBALANCE = %0.5f\n\n", imb);
		num++;

	}
}