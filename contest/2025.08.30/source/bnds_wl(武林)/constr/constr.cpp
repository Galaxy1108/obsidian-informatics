#include <cstdio>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int a[15];
int num[14005][15];

int main()
{
	freopen("constr.out", "w", stdout);
	srand(1926080);
	int i, j, k, g = 0;
	bool f;
	for(i = 1; i <= 10; i++)
		a[i] = i; 
	for(i = 1; i <= 14000; i++)
	{
		f = 1;
		random_shuffle(a + 1, a + 11);
		for(j = 1; j <= g; j++)
		{
			for(k = 1; k <= 10; k++)
				if(abs(a[k] - num[j][k]) > 1)
					break;
			if(k > 10)
			{
				f = 0;
				break;
			}
		}
		if(f)
		{
			g++;
			for(k = 1; k <= 10; k++)
				num[g][k] = a[k];
		}
	}
	printf("%d\n", g);
	for(j = 1; j <= g; j++)
		for(k = 1; k <= 10; k++)
			printf("%d%c", num[j][k], " \n"[k == 10]);
	return 0;
}