#include<cstdio>
using namespace std;
int change(int id)
{
	if(id==1||id==2)return 100;
	if(id==3)return 97;
	if(id==4)return 96;
	if(id==5)return 95;
	if(id==6)return 90;
	if(id==7)return 85;
	if(id==8)return 80;
	if(id==9)return 82;
	if(id==10)return 78;
	if(id==11)return 75;
	if(id==12)return 70;
	if(id==13)return 65;
	if(id==14)return 55;
	if(id==15)return 50;
	if(id==16)return 15;
	if(id==17)return 12;
	if(id==18)return 10;
	if(id==19)return 8;
	if(id==20)return 5;
	if(id==21)return 2;
}
const int inf=1145141919;
int n,w[8010],u[8010],t[8010];
int mpl[25010],mpr[25010],mp1[25010];
int maxt;
int f[25010][22][2];
int max(int a,int b)
{
	return a>b?a:b;
}
int max5(int a,int b,int c,int d,int e)
{
	int Max=max(a,b);
	Max=max(Max,c);
	Max=max(Max,d);
	Max=max(Max,e);
	return Max;
}
int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&w[i],&u[i],&t[i]),w[i]=change(w[i]);
	
	for(int i=1;i<=n;++i)
	{
		if(t[i]!=t[i-1])mpl[t[i]]=i,mpr[t[i-1]]=i-1;
		if(w[i]==50)mp1[t[i]]=i;
	}
	maxt=t[n];
	mpr[maxt]=n;
	for(int i=1;i<=maxt;++i)
		for(int j=1;j<=20;++j)
		{
			for(int now=mpl[i];now<=mpr[i];++now)
			{
				f[i][j][0]=max(f[i][j][0],max(max5(f[i-1][j-2][0],f[i-1][j-1][0],f[i-1][j][0],f[i-1][j+1][0],f[i-1][j+2][0]),f[i-1][j][1]));
				if(mp1[i])f[i][j][0]=-inf;
				if(u[now]==j)
					f[i][j][1]=max(f[i][j][1],max5(f[i-1][j-2][0],f[i-1][j-1][0],f[i-1][j][0],f[i-1][j+1][0],f[i-1][j+2][0])+w[now]);
				else f[i][j][1]=max(f[i][j][1],-inf);
				if(mp1[i]&&j!=u[mp1[i]])f[i][j][1]=-inf;
			}
			
		}
	int ans=-inf;
	for(int j=1;j<=20;++j)
		ans=max(ans,max(f[maxt][j][0],f[maxt][j][1]));
	printf("%d",ans);
	return 0;
}
