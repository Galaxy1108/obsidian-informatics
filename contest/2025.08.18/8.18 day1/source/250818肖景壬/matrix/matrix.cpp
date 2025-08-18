#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[105][15][15],n,m,k,a[100005],b[100005];
//f{i,j,k} = 第i个位置，j个矩阵，i位置状态为k{0=0,1=上,2=下,3=上下,4=全} 
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		if(m==2) cin>>b[i]; 
	} 
	memset(f,-0x3f,sizeof(f));
	f[0][0][0]=0;
	int ans=0;
	if(m==1)
	{
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= k; j++)
			{
				int gmax=max(max(f[i][j][0],f[i][j][1]),max(max(f[i][j][2],f[i][j][3]),f[i][j][4]));
				f[i+1][j][0]=max(f[i+1][j][0],gmax);
				f[i+1][j+1][1]=max(f[i+1][j+1][1],gmax+a[i+1]);
				f[i+1][j][1]=max(f[i+1][j][1],f[i][j][1]+a[i+1]);
				//cout<<f[i][j][0]<<" "<<f[i][j][1]<<" "<<i<<" "<<j<<endl;
				//ans=max(ans,gmax);
			}
		}
		cout<<f[n+1][k][0]<<endl;
	}
	else
	{
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= k; j++)
			{
				int gmax=max(max(f[i][j][0],f[i][j][1]),max(max(f[i][j][2],f[i][j][3]),f[i][j][4]));
				f[i+1][j][0]=max(f[i+1][j][0],gmax);
				f[i+1][j+1][1]=max(f[i+1][j+1][1],gmax+a[i+1]);
				f[i+1][j][1]=max(f[i+1][j][1],max(f[i][j][1],f[i][j][3])+a[i+1]);
				f[i+1][j+1][2]=max(f[i+1][j+1][2],gmax+b[i+1]);
				f[i+1][j][2]=max(f[i+1][j][2],max(f[i][j][2],f[i][j][3])+b[i+1]);
				f[i+1][j+2][3]=max(f[i+1][j+2][3],gmax+a[i+1]+b[i+1]);
				f[i+1][j+1][3]=max(f[i+1][j+1][3],f[i][j][1]+a[i+1]+b[i+1]);//new a
				f[i+1][j+1][3]=max(f[i+1][j+1][3],f[i][j][2]+a[i+1]+b[i+1]);//new b
				f[i+1][j][3]=max(f[i+1][j][3],f[i][j][3]+a[i+1]+b[i+1]);
				f[i+1][j+1][4]=max(f[i+1][j+1][4],gmax+a[i+1]+b[i+1]);
				f[i+1][j][4]=max(f[i+1][j][4],f[i][j][4]+a[i+1]+b[i+1]);
				//cout<<f[i][j][0]<<" "<<f[i][j][1]<<" "<<f[i][j][2]<<" "<<f[i][j][3]<<" "<<f[i][j][4]<<" "<<i<<" "<<j<<endl;
				//ans=max(ans,gmax);
			}
		}
		cout<<f[n+1][k][0]<<endl;
	}
}
