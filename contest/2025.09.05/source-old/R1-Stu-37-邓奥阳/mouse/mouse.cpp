#include<bits/stdc++.h>
using namespace std;
double f[1001][1001][2];
double dp(int w,int b,bool g)
{
	if(w<0||b<0)return 0;
	if(f[w][b][g])return f[w][b][g];
	if(w==0)return 0;
	if(g==1)return f[w][b][1]=w*1.0/(w+b)+b*1.0/(w+b)*dp(w,b-1,0);
	return f[w][b][0]=(b*1.0/(w+b))*(dp(w-1,b-1,1)*w*1.0/(w+b-1)+dp(w,b-2,1)*(b-1)*1.0/(w+b-1));
}
int w,b;
int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	scanf("%d%d",&w,&b);
	printf("%.9lf",dp(w,b,1));
}
