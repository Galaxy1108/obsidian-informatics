#include <bits/stdc++.h>
#define fa (nw>>1)
#define lson (nw<<1)
#define rson ((nw<<1)+1)
using namespace std;
long long Qread()
{
	long long x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
const long long Mod=1e9+7;
int da[10][4],a[20],prime[4]={2,3,5,7};
long long N,K,len,i,j,k,l,m,n;
long long f[2][10][37][25][13][13];
long long g[2][10][37][25][13][13];
long long s[150010],ans,mem;
bool cmp(int a,int b)
{
	return a>b;
}
struct POI{
	int id1,id2;
}emp,sta;
bool operator>(POI x,POI y)
{
	return s[x.id1]*s[x.id2]>=s[y.id1]*s[y.id2];
}
void swap(POI &x,POI &y)
{
	POI temp=x;
	x=y;
	y=temp;
	return;
}
struct Dui{
	POI f[200010];
	int top;
	void put_in(POI a)
	{
		f[++top]=a;
		int nw=top;
		while(fa&&(f[nw]>f[fa]))
			swap(f[nw],f[fa]),nw=fa;
		return;
	}
	POI get_big()
	{
		POI ret=f[1];
		f[1]=f[top];
		f[top--]=emp;
		int nw=1;
		while(lson<=top&&(f[lson]>f[nw]||(rson<=top&&f[rson]>f[nw])))
		{
			if(rson<=top&&f[rson]>f[nw])
			{
				if(f[rson]>f[lson]) swap(f[nw],f[rson]),nw=rson;
				else swap(f[nw],f[lson]),nw=lson;
			}
			else swap(f[nw],f[lson]),nw=lson;
		}
		return ret;
	}
}Q;
int main()
{
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);

	for(i=1;i<=9;i++)
	for(j=0,k=i;j<=3;j++)
		while(k%prime[j]==0)
			da[i][j]++,k/=prime[j];
	N=Qread();K=Qread();
	if(N==1e12) N--;
	f[0][1][0][0][0][0]=g[0][1][0][0][0][0]=1;a[0]=1;
	while(N)
	{
		len++;
		memset(g[len&1],0,sizeof(g[len&1]));
		memset(f[len&1],0,sizeof(f[len&1]));
		for(i=1;i<=9;i++)
		for(n=1;n<=9;n++)
		for(j=da[i][0];j<=3*len;j++)
		for(k=da[i][1];k<=2*len;k++)
		for(l=da[i][2];l<=len;l++)
		for(m=da[i][3];m<=len;m++)
			g[len&1][i][j][k][l][m]+=g[(len-1)&1][n][j-da[i][0]][k-da[i][1]][l-da[i][2]][m-da[i][3]];
		i=N%10;	
		for(j=da[i][0];j<=3*len;j++)
		for(k=da[i][1];k<=2*len;k++)
		for(l=da[i][2];l<=len;l++)
		for(m=da[i][3];m<=len;m++)
		{
			for(n=1;n<a[len-1];n++)
				f[len&1][i][j][k][l][m]+=g[(len-1)&1][n][j-da[i][0]][k-da[i][1]][l-da[i][2]][m-da[i][3]];
			if(a[len-1])f[len&1][i][j][k][l][m]+=f[(len-1)&1][a[len-1]][j-da[i][0]][k-da[i][1]][l-da[i][2]][m-da[i][3]];
		}
		if(N/10)
		for(n=1;n<=9;n++)
		for(j=0;j<=3*len;j++)
		for(k=0;k<=2*len;k++)
		for(l=0;l<=1*len;l++)
		for(m=0;m<=1*len;m++)
			s[j*25*13*13+k*13*13+l*13+m]+=g[len&1][n][j][k][l][m];
		a[len]=N%10;
		N/=10;
	}
	for(n=1;n<a[len];n++)
	for(j=0;j<=3*len;j++)
	for(k=0;k<=2*len;k++)
	for(l=0;l<=1*len;l++)
	for(m=0;m<=1*len;m++)
		s[j*25*13*13+k*13*13+l*13+m]+=g[len&1][n][j][k][l][m];
	for(j=0;j<=3*len;j++)
	for(k=0;k<=2*len;k++)
	for(l=0;l<=1*len;l++)
	for(m=0;m<=1*len;m++)
		s[j*25*13*13+k*13*13+l*13+m]+=f[len&1][a[len]][j][k][l][m];
	sort(s,s+150000,cmp);
	sta.id1=0;sta.id2=0;
	Q.put_in(sta);
	for(i=1;i<=K;i++)
	{
		sta=Q.get_big();
		(ans+=s[sta.id1]*s[sta.id2]%Mod)%=Mod;
		if(sta.id1==0)
		{
			sta.id2++;
			Q.put_in(sta);
			sta.id2--;
		}
		sta.id1++;
		Q.put_in(sta);
	}
	printf("%lld",ans);
	return 0;
}
