#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;
const int n=300;
int main( )
{
	srand(time(NULL));
	freopen("disease.in","w",stdout);
	int i,j=1;
	printf("%d %d\n",n,n-1);
	for(i=2;i<=n;i++)
		{
			printf("%d %d\n",j,i);
			if(rand()%3==0) j++;
		}
	return 0;
}
