/*input
29
3 1 3
3 3 3
1 8 21
17 108 121
10 0 100
47 240 1637
18 0 162
23 385 195
37 1664 489
17 0 145
44 544 1224
42 0 1394
24 0 386
12 24 74
8 0 40
55 629 1659
60 1410 2318
34 836 498
46 980 1290
19 56 213
11 48 41
57 3468 1481
52 2210 1350
8 0 130
0 30 38
0 30 38
1 4 9
5 0 13
3 0 5
*/

#include<bits/stdc++.h>

using namespace std;

int TC;
int A , B , C;
bool solved;

int main()
{
	cin >> TC;
	while(TC--)
	{
		cin >> A>>B>>C;
		solved = false;
		for(int x = -22 ; x <= 22 && !solved ;x++)
			for(int y = -100 ; y <= 100 && !solved;y++)
				for(int z = -100 ; z <= 100 && !solved; z++)
					if(x != y && x != z && y != z  && x + y + z == A && x*y*z == B && x*x + y*y + z*z ==C)
					{
						printf("%d %d %d\n",x , y , z );
						solved = true;
					}

		if(!solved)
			printf("%s\n","No solution." );
	}
} 