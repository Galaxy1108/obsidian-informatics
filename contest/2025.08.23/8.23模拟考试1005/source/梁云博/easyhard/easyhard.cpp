#include <bits/stdc++.h>
#define int long long
#define N 3005
using namespace std;
int n,m,p;
//int f[2*N][N];
void qp(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=(res*a)%p;
		a=(a*a)%p;
		b>>=1;
	}
	cout<<res;
}
signed main()
{
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	cin>>n>>m>>p;
//	for(int j=0;j<=n;j++)f[0][j]=1;
//	for(int i=1;i<=2*m;i++)//奇数是操作1，偶数是操作2 
//	{
//		if(i&1)//注意本次剩余应当少1 
//		{
//			//从盒内取一个//
//			for(int j=0;j<n;j++)
//			{
//				f[i][j]=(f[i-1][j+1]+f[i-1][j])%p;//由这次取黑或取白转移 
//			}
//		}
//		else
//		{
//			//这次会先取出再加入
//			f[i][0]=f[i-1][0];
//			for(int j=1;j<=n;j++)
//			{
//				//取盒内球，注意到上一个状态j上限为n-1 
//				f[i][j]=(f[i-1][j-1]+f[i-1][j])%p;//如果能够补球，则这次黑球数量要么不变要么增多 
////				//取盒外球
////				f[i][j]=f[i][j]+;//凭空加黑或白//如果拿的外面的黑就加一个白进盒子//反之//这次黑球数量依然不变或增多 （貌似不用管？） 
//			}
//		}
//	}
//	int ans=0;
//	for(int j=0;j<=n;j++)ans=(ans+f[2*m][j])%p;
//	cout<<ans;
	qp(2,min(m+n,2*m));
	return 0;
}
