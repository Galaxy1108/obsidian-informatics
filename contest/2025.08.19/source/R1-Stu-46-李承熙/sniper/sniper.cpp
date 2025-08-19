#include<bits/stdc++.h>
using namespace std;
const int maxn=8010;
inline int qread()
{
	int a=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=(a<<1)+(a<<3)+(ch^48);ch=getchar();}
	return a*f;
}
int n,w[maxn],u[maxn],t[maxn],f[25010][30],que[maxn],head=1,en,mt,mu,headz=1,ans;
int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	n=qread();
	for(int i=1;i<=n;i++)
	{
		w[i]=qread();
		u[i]=qread();
		t[i]=qread();
		if(w[i]==1)w[i]=100;
		if(w[i]==2)w[i]=100;
		if(w[i]==3)w[i]=97;
		if(w[i]==4)w[i]=96;
		if(w[i]==5)w[i]=95;
		if(w[i]==6)w[i]=90;
		if(w[i]==7)w[i]=85;
		if(w[i]==8)w[i]=80;
		if(w[i]==9)w[i]=82;
		if(w[i]==10)w[i]=78;
		if(w[i]==11)w[i]=75;
		if(w[i]==12)w[i]=70;
		if(w[i]==13)w[i]=65;
		if(w[i]==14)w[i]=55;
		if(w[i]==15)
		{
			w[i]=50;
			que[++en]=i;
		}
		if(w[i]==16)w[i]=15;
		if(w[i]==17)w[i]=12;
		if(w[i]==18)w[i]=10;
		if(w[i]==19)w[i]=8;
		if(w[i]==20)w[i]=5;
		if(w[i]==21)w[i]=2;
		mt=max(mt,t[i]);
		mu=max(mu,u[i]);
	}
	for(int i=1;i<=mt;i++)
	{
		while(i>t[headz])headz++;
		if(i==t[que[head]])
		{
			f[i][u[que[head]]]+=w[que[head]];
			f[i+2][u[que[head]]]=max(f[i+2][u[que[head]]],f[i][u[que[head]]]);
			f[i+2][u[que[head]]-1]=max(f[i+2][u[que[head]]-1],f[i][u[que[head]]]);
			f[i+2][max(0,u[que[head]]-2)]=max(f[i+2][max(0,u[que[head]]-2)],f[i][u[que[head]]]);
			f[i+2][u[que[head]]+1]=max(f[i+2][u[que[head]]+1],f[i][u[que[head]]]);
			f[i+2][u[que[head]]+2]=max(f[i+2][u[que[head]]+2],f[i][u[que[head]]]);
			head++;
			continue;
		}
		if(i==t[que[head]]-1)
		{
			f[i+1][u[que[head]]]=max(f[i+1][u[que[head]]],f[i][u[que[head]]]);
			f[i+1][u[que[head]]]=max(f[i+1][u[que[head]]],f[i][u[que[head]]-1]);
			f[i+1][u[que[head]]]=max(f[i+1][u[que[head]]],f[i][u[que[head]]-2]);
			f[i+1][u[que[head]]]=max(f[i+1][u[que[head]]],f[i][u[que[head]]+1]);
			f[i+1][u[que[head]]]=max(f[i+1][u[que[head]]],f[i][u[que[head]]+2]);
			continue;
		}
		for(int j=1;j<=mu;j++)
		{
			f[i+1][j]=max(f[i+1][j],f[i][j]);
			f[i+1][j-1]=max(f[i+1][j-1],f[i][j]);
			f[i+1][max(0,j-2)]=max(f[i+1][max(0,j-2)],f[i][j]);
			f[i+1][j+1]=max(f[i+1][j+1],f[i][j]);
			f[i+1][j+2]=max(f[i+1][j+2],f[i][j]);
			if(i==t[headz])
			{
				for(int k=headz;t[k]==t[headz];k++)
				{
					if(j==u[k])
					{
						f[i][j]+=w[k];
						f[i+2][j]=max(f[i+2][j],f[i][j]);
						f[i+2][j-1]=max(f[i+2][j-1],f[i][j]);
						f[i+2][max(0,j-2)]=max(f[i+2][max(0,j-2)],f[i][j]);
						f[i+2][j+1]=max(f[i+2][j+1],f[i][j]);
						f[i+2][j+2]=max(f[i+2][j+2],f[i][j]);
						f[i][j]-=w[k];
					}
				}	
			}
		}
	}
	for(int i=1;i<=mu;i++)ans=max(ans,max(max(f[mt][i],f[mt+1][i]),f[mt+2][i]));
	cout<<ans;
	return 0;
}
