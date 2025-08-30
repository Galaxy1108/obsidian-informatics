#include<bits/stdc++.h>
#define rr register
using namespace std;
inline int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x;
}
void write(int x) {if(x>9) write(x/10);putchar(x%10+'0');}
int a[113403][11],cnt=1,n;
inline bool judge(int x,int y)
{
	for(rr int i=1;i<=10;++i) if(abs(a[x][i]-a[y][i])>1) return false;
	return true;
}
inline void build(int x)
{
	for(rr int i=1;i<10;++i)
		for(rr int j=i+1;j<=10;++j)
		{
			if(abs(a[x][i]-a[x][j])>1)
			{
				bool ok=true;
				++cnt;
				for(rr int k=1;k<=10;++k) a[cnt][k]=a[x][k];
				swap(a[cnt][i],a[cnt][j]);
				for(rr int k=cnt-1;k>=1;--k)
					if(judge(k,cnt)) {ok=false;--cnt;break;}
				if(ok)
				{
					for(rr int k=1;k<=10;++k) write(a[cnt][k]),putchar(' '); 
					putchar('\n');
					if(cnt==7613) return;
				}
			}
		}
	return;
}
int main()
{
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	n=read();
	printf("7613\n");
	for(rr int i=1;i<=10;++i) a[1][i]=i,write(i),putchar(' ');
	putchar('\n');
	while(1)
	{
		for(rr int i=1;i<=cnt;++i) 
		{
			build(i);
			if(cnt==7613) return 0;
		}
	}
	return 0;
}