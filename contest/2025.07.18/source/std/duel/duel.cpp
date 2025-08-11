#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int n,Q,op,l,r,k,x;
int p[200010];
int f[10][200010];
int val[200010],top,siz[200010],ns,nv;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=Qread(),Q=Qread();
	for(int i=1;i<=n;i++) f[0][i]=p[i]=Qread();
	for(int i=1;i<10;i++) for(int j=1;j+(1<<i)-1<=n;j++)
		f[i][j]=abs(f[i-1][j]-f[i-1][j+(1<<i-1)]);
	for(int t=1;t<=Q;t++)
	{
		op=Qread();
		if(op==1)
		{
			x=Qread();
			f[0][x]=Qread();
			for(int i=1;i<10;i++)
			{
				l=max(1,x-(1<<i)+1),r=min(x,n-(1<<i)+1);
				for(int j=l;j<=r;j++)
					f[i][j]=abs(f[i-1][j]-f[i-1][j+(1<<i-1)]);
			}
		}
		else
		{
			l=Qread(),k=Qread();
			if(k<10) printf("%d\n",f[k][l]);
			else
			{
				r=l+(1<<k)-1;top=0;
				for(int i=l;i<=r;i+=512)
				{
					ns=1,nv=f[9][i];
					while(top&&siz[top]==ns)
						ns++,nv=abs(val[top]-nv),top--;
					siz[++top]=ns,val[top]=nv;
				}
				printf("%d\n",val[1]);
			}
		}
	}
	return 0;
}