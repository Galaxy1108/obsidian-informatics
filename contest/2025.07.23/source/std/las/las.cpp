#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int n;
int c[1000010];
int f[1000010][2][2];
bool chk(int i,int x,int y,int z)
{
	if(y) return c[i]/(x+1)<=c[i+1]/(2-z);
	return c[i]/(x+1)>=c[i+1]/(2-z);
}
int tr[1000010];
void get_ans(int n,int x,int y)
{
	tr[n]=y;
	if(n==1) return;
	if(f[n-1][0][x]&f[n][x][y]) get_ans(n-1,0,x);
	else get_ans(n-1,1,x);
}
int main()
{
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);

	n=Qread();
	for(int i=1;i<=n;i++)
		c[i]=Qread()*2;
	c[n+1]=c[1];
	for(int o=0;o<=1;o++)
	{
		memset(f,0,sizeof(f));
		f[1][o][0]=1,f[1][o][1]=2;
		for(int i=1;i<n;i++)
		{
			for(int x=0;x<=1;x++)
			for(int y=0;y<=1;y++)
			if(f[i][x][y])
			{
				for(int z=0;z<=1;z++)
					if(chk(i,x,y,z))
						f[i+1][y][z]|=f[i][x][y];
			}
		}
		
		for(int x=0;x<=1;x++)
		if(f[n][x][o])
		for(int y=0;y<=1;y++)
			if((f[n][x][o]&(1<<y))&&chk(n,x,o,y))
			{
				get_ans(n,x,o);
				for(int i=1;i<=n;i++)
					printf("%d ",tr[i]?(i%n+1):i);
				printf("\n");
				return 0;

			}
	}
	printf("NIE\n");
	return 0;
}