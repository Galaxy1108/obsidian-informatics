#include<bits/stdc++.h>
using namespace std; 
int n;
long long s1[2051],s2[2051],s3[2051],max1[2051],max2[2051],ans,a[2][2051];//s1:left s2:right 
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	cin>>n;
	memset(max1,0xc0,sizeof(max1));
	memset(max2,0xc0,sizeof(max2));
	for(int i=1;i<=n;i++)cin>>a[1][i];
	for(int i=1;i<=n;i++)cin>>a[2][i],s1[i]=s1[i-1]+a[1][i]+a[2][i],s3[i]=s3[i-1]+a[2][i];
	for(int i=n;i>=1;i--)s2[i]=s2[i+1]+a[1][i]+a[2][i];
	ans=max1[0];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)max1[i]=max(max1[i],s1[i]-s1[j-1]);
		for(int j=n;j>=i;j--)max2[i]=max(max2[i],s1[j]-s1[i-1]);
	}
	for(int i=1;i<n;i++){
		for(int j=i+2;j<=n;j++)
		{
			ans=max(ans,max1[i]+s3[j-1]-s3[i]+max2[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
