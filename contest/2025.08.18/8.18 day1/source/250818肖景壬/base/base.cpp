#include<bits/stdc++.h>
using namespace std;
int n,f[100005][10],a[100005],b[100005],ans;
//我不想写了 
int main() 
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	memset(f,-0x3f,sizeof(f));
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i]; 
	}
	for(int i = 1; i <= n; i++)
	{
		cin>>b[i]; 
	}
	for(int i = 1; i <= n; i++)
	{
		f[i][1]=max(0,f[i-1][1])+a[i]+b[i];
		f[i][2]=max(f[i-1][1],f[i-1][2])+b[i];
		f[i][3]=max(f[i-1][3],f[i-1][2])+a[i]+b[i];
		ans=max(ans,f[i][3]);
		//cout<<f[i][1]<<" "<<f[i][2]<<" "<<f[i][3]<<endl; 
	}
	cout<<ans<<endl;
}
