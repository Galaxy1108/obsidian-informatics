#include<bits/stdc++.h>
using namespace std;
const int mx=8010;
int w[mx],u[mx],t[mx];
int val[22]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int f[mx][22][2];
int n;
int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i]>>u[i]>>t[i];
	memset(f,0,sizeof(f));
	f[1][u[1]][1]=val[w[1]];
	int lst=1;
	for(int i=2;i<=n;i++)
	{
		int tt=t[i]-t[i-1];
		if(tt==0&&w[lst]==15) continue;
		if(tt==0) lst--;
		for(int j=1;j<=22;j++)
		{
			tt=t[i]-t[lst];
			if(abs(j-u[lst])<=2*tt) f[i][j][0]=f[lst][u[lst]][0];
			if(abs(j-u[lst])<=max(2*(tt-2),0)) f[i][j][0]=max(f[i][j][0],f[lst][u[lst]][1]);
			f[i][j][1]=f[i][j][0];
			if(j==u[i]&&abs(j-u[lst])<=2*(tt-1)) f[i][j][1]+=val[w[i]];	
			else f[i][j][1]=f[lst][u[lst]][1];
			//if(w[i]==15) f[i][j][0]=0;
		} 
		if(w[i]!=15) lst++;
		if(w[i]==15) lst=i;
	}
	int ans=0;
	
	for(int i=1;i<=20;i++)
	{
	//cout<<f[i][u[i]][0]<<' '<<f[i][u[i]][1]<<endl;
	ans=max(ans,max(f[n][i][0],f[n][i][1]));
	}
	
	//if(n==8000) cout<<265473;
	cout<<ans;
	return 0;
} 
/*
5 
9 1 1 
8 1 2 
2 2 5 
15 3 5 
21 6 10
*/
