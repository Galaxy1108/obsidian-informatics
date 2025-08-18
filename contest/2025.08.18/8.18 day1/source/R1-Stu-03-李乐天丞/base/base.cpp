#include <bits/stdc++.h>
using namespace std;
int w[1010][2];
int s[1010][2];
int f[1010][1010];
int n,ans=-2e9;
inline int Qread()
{
	int sum=0,flag=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') flag=-1;c=getchar();}
	while(c>='0'&&c<='9') sum=(sum<<3)+(sum<<1)+(c^48),c=getchar();
	return sum*flag;
}
int main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	n=Qread();
	for(int i=1;i<=n;i++) w[i][0]=Qread(),s[i][0]=s[i-1][0]+w[i][0];
	for(int i=1;i<=n;i++) w[i][1]=Qread(),s[i][1]=s[i-1][1]+w[i][1];
	for(int l=1;l+2<=n;l++)
	{
		f[l][l+2]=w[l+1][0];
		for(int r=l+3;r<=n;r++) {f[l][r]=min(w[r-1][0],w[r-1][0]+f[l][r-1]);}
		int minn=f[l][l+2];
		for(int r=l+2;r<=n;r++)
		{
			if(f[l][r]<minn) minn=f[l][r];
			ans=max(ans,s[r][1]-s[l-1][1]+s[r][0]-s[l-1][0]-minn);
		}
	}
	cout<<ans;
	return 0;
}
/*
4
1 3 -4 5
-2 6 -1 7

6
21 9 -99 87 -100 1
2 9 6 8 3 2
*/
