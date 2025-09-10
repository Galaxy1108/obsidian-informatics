#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int n,zsh,i,j,k,l,r,x,y,las;
int len,s[4],sr[4],tur[4],maxn,minn;
int f[2010][10][10][10][10],ans;
int sit(int l,int r,int pos)
{
	if(pos==0) return 1;
	if(l>r){int temp=l;l=r;r=temp;}
	if(l<=pos&&pos<=r) return 1;
	if(pos<l) return 2;
	if(pos>r) return 3;
}
void get_min(int &a,int b)
{
	if(a>b) a=b;
	return;
}
void get_max(int &a,int b)
{
	if(a<b) a=b;
	return;
}
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	n=Qread();
	memset(f,10,sizeof(f));
	ans=1145141919;
	f[0][0][0][0][0]=0;
	las=1;
	for(zsh=1;zsh<=n;zsh++)
	{
		x=Qread();
		y=Qread();
		for(s[0]=0;s[0]<=9;s[0]++)
		for(s[1]=s[0];s[1]<=9;s[1]++)
		for(s[2]=s[1];s[2]<=9;s[2]++)
		for(s[3]=s[2];s[3]<=9;s[3]++)
		{
			if(f[zsh-1][s[0]][s[1]][s[2]][s[3]]==168430090) continue;
			if(las>x) maxn=las,minn=x;
			else maxn=x,minn=las;
			for(l=1;l<=minn;l++)
			for(r=9;r>=maxn;r--)
			{
				len=0;
				tur[0]=tur[1]=tur[2]=tur[3]=0;
				for(j=0;j<=3;j++)
					if(s[j]!=0&&(s[j]<l||s[j]>r))
						tur[len++]=s[j];
				if(len>3) continue;
				tur[len++]=y;
				sort(tur,tur+4);
				if(las>x) get_min(f[zsh][tur[0]][tur[1]][tur[2]][tur[3]],f[zsh-1][s[0]][s[1]][s[2]][s[3]]+r-las+r-l+x-l);
				else get_min(f[zsh][tur[0]][tur[1]][tur[2]][tur[3]],f[zsh-1][s[0]][s[1]][s[2]][s[3]]+r-x+r-l+las-l);
//				printf("%d %d|%d %d %d %d %d\n",l,r,tur[0],tur[1],tur[2],tur[3],f[zsh][tur[0]][tur[1]][tur[2]][tur[3]]);
			}
		}
		las=x;
	}
	for(s[0]=0;s[0]<=9;s[0]++)
	for(s[1]=s[0];s[1]<=9;s[1]++)
	for(s[2]=s[1];s[2]<=9;s[2]++)
	for(s[3]=s[2];s[3]<=9;s[3]++)
	{
		maxn=x,minn=x;
		for(j=0;j<=3;j++) if(s[j]) get_max(maxn,s[j]),get_min(minn,s[j]);
		get_min(ans,f[n][s[0]][s[1]][s[2]][s[3]]+min(maxn-x,x-minn)+maxn-minn);
	}
	printf("%d",ans+2*n);
	return 0;
}
