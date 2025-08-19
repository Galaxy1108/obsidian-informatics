#include <bits/stdc++.h>
using namespace std;
int n,w[8005],u[8005],t[8005];
int f[25][25005][8005];
int s[8005],tot;
int v[24]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2}
int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>w[i]>>u[i]>>t[i];
		if(w[i]==15)
		{
			s[++tot]=w[i];
		}
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=25000;j++)
		{
			for(int k=1;k<=n;k++)
			{
				f[i][j][k]=max(f[i-1][j-1][k],f[i+1][j-1][k],f[i-1][j-1][k-1]+v[w[i]],f[i+1][j-1][k-1]+v[w[i]])
			}
		}
	}
	
	return 0;
} 
