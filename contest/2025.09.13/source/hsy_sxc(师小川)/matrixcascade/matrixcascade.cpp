#include<bits/stdc++.h>
#define rr register
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}

int T,n,cnt,x,y;

int main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read(),x=read(),y=read();
		cnt=0;
		printf("YES\n");
		for(rr int i=1;i<=n;++i)
		{
			for(rr int i=1;i<=n;++i)
				printf("%d ",++cnt);
			printf("\n");
		}
	}
	return 0;
} 