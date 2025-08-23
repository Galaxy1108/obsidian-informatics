#include<bits/stdc++.h>
using namespace std;
const int mx=3e2+10;
int n,m,p;
int f[mx][mx][mx];

int dfs(int k,int x,int y)
{
	int ans=0;
	if(x>n||y>n||x<0||y<0) return 0;
	else if(k==1) ans=1;
	else if(k%2==1)
	{
		ans=(ans+(dfs(k-1,x+1,y)+dfs(k-1,x,y+1))%p)%p;
	} 
	else if(k%2==0)
	{
		ans=(ans+(dfs(k-1,x-1,y)+dfs(k-1,x,y-1))%p)%p;
	} 
	return ans%p;
}

  
int main()
{
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	cin>>n>>m>>p;
	
	int sum=0;
	for(int i=1;i<=n;i++)
		sum=(sum+dfs(2*m,i,n-i+1)*((i>0)+(n-i+1>0)))%p;
	
cout<<sum;
	return 0;
} 


