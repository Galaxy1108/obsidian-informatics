#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x; 
}
int T,n,i,j,X,Y,lim;
int dif[10];
int a[20];
bool vis[20];
bool chk()
{
	int cntX=0,cntY=0;
	for(int i=1;i<=lim;i++)
	for(int j=i+1;j<=lim;j++)
		if(a[i]>a[j]) cntX++;
	for(int i=1;i<=lim;i++)
	for(int j=i+1;j<=lim;j++)
		if(a[dif[i]]>a[dif[j]]) cntY++;
	return (cntX==X&&cntY==Y);
}
bool solve(int num)
{
	if(num==lim+1) return chk();
	for(int i=1;i<=lim;i++)
	{
		if(vis[i]) continue;
		a[num]=i,vis[i]=true;
		if(solve(num+1)) return true;
		vis[i]=false;
	}
	return false;
}
int main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	T=Qread();
	while(T--)
	{
		n=Qread(),X=Qread(),Y=Qread();
		if(n<=3)
		{
			lim=n*n;
			if(n==1) dif[1]=1;
			else if(n==2) dif[1]=1,dif[2]=3,dif[3]=2,dif[4]=4;
			else if(n==3)   dif[1]=1,dif[2]=4,dif[3]=7,
							dif[4]=2,dif[5]=5,dif[6]=8,
							dif[7]=3,dif[8]=6,dif[9]=9;
			if(solve(1))
			{
				printf("YES\n");
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n;j++)
						printf("%d ",a[(i-1)*n+j]);
					printf("\n");
				}
			}
			else printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
					printf("%d ",(i-1)*n+j);
				printf("\n");
			}
		}
	}
	return 0;
}