#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mx=4100;
int a[mx],b[mx],ans[mx][mx];
int H,W;
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') w=ch=='-'?-1:1;
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
}
int sum=0;
bool check(int s,int x,int y)
{
	if(s<0||x>H||y>W) return 0;
	if(x==H&&y==W) return 1;
	return check(s-b[y],x+1,y)||check(s-a[x],x,y+1);
}
signed main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	H=fread(),W=fread();
	for(int i=1;i<=H;i++) a[i]=fread();
	for(int i=1;i<=W;i++) b[i]=fread();
	if(H<=4e3&&W<=4e3)
	{
		for(int i=0;i<=H+1;i++)
		ans[i][0]=ans[i][H+1]=2e18;
		for(int i=0;i<=W+1;i++)
		ans[0][i]=ans[W+1][i]=2e18;
		for(int i=1;i<=H;i++)
		{
			for(int j=1;j<=W;j++)
			{
				if(i==1&&j==1) ans[i][j]=0;
				else ans[i][j]=min(ans[i-1][j]+b[j],ans[i][j-1]+a[i]);
			}
		}
//		for(int i=0;i<=H+1;i++)
//		{
//			for(int j=0;j<=W+1;j++)
//			cout<<setw(12)<<ans[i][j];
//			cout<<endl;
//		}
		cout<<ans[H][W];
	}
	else
	{
		int l=1,r=0;
		r=(H-1)*b[1]+(W-1)*a[H];
		while(l<=r)
		{
			int mid=(l+r)/2;
//			cout<<l<<' '<<r<<' '<<mid<<endl;
			if(check(mid,1,1)) r=mid-1;
			else l=mid+1;
		}
		cout<<l;
	}
	return 0;
 } 
