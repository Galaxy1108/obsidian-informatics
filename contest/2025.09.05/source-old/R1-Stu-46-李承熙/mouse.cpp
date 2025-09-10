#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	register int a=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=(a<<1)+(a<<3)+(ch^48);ch=getchar();}
	return a*f;
}
int w,b;
long double dp[1010][1010][2];
int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	w=qread();
	b=qread();
	for(register int i=1;i<=w;++i)
	{
		for(register int j=0;j<=b;++j)
		{
			if(j>=3)dp[i][j][1]=dp[i][j-3][1]*(1.0*j/(i+j))*(1.0*(j-1)/(i+j-1))*(1.0*(j-2)/(i+j-2));
			if(i&&j>=2)dp[i][j][1]+=dp[i-1][j-2][1]*(1.0*j/(i+j))*(1.0*(j-1)/(i+j-1))*(1.0*i/(i+j-2));
			dp[i][j][1]+=(1.0*i/(i+j));
			if(j>=3)dp[i][j][0]=dp[i][j-3][0]*(1.0*j/(j+i))*(1.0*(j-2)/(i+j-2))/2;
			if(i&&j>=2)dp[i][j][0]+=dp[i-1][j-2][0]*(1.0*j/(j+i))*(1.0*(j-1)/(i+j-2))/2;
			dp[i][j][0]+=(1.0*i/(i+j));
		}
	}
	printf("%.9Lf",dp[w][b][1]);
	return 0;
}
