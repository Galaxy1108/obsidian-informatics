#include<bits/stdc++.h>
using namespace std;
int n;
int val[22]={-1000000,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
struct der
{
	int v,s,t;
};
der m[8002];
int f[25003][21][6];
int finder[25003][21];
der sni[8002];

int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	cin>>n;
	int sn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i].v>>m[i].s>>m[i].t;
		finder[m[i].t][m[i].s]=m[i].v;
		if(m[i].v==15)
		{
			sn++;
			sni[sn]=m[i];
		}
	}
	int ksn=1;
	for(int i=0;i<=m[n].t;i++)
	{
		if(i==sni[ksn].t)
		{
			for(int j=0;j<=20;j++)
			{
				for(int k=0;k<=5;k++)
				{
					f[i][j][k]=-1000000;
					f[i+1][j][k]=-1000000;
				}
			}
			if(i==0) f[i][sni[ksn].s][0]=val[15];
			f[i][sni[ksn].s][0]=max(f[i][sni[ksn].s][0],f[i-2][sni[ksn].s][0]+val[15]);
			if(sni[ksn].s<=19) f[i][sni[ksn].s][0]=max(f[i][sni[ksn].s][0],f[i-1][sni[ksn].s+1][1]+val[15]);
			if(sni[ksn].s<=18) f[i][sni[ksn].s][0]=max(f[i][sni[ksn].s][0],f[i-1][sni[ksn].s+2][2]+val[15]);
			if(sni[ksn].s>=1) f[i][sni[ksn].s][0]=max(f[i][sni[ksn].s][0],f[i-1][sni[ksn].s-1][3]+val[15]);
			if(sni[ksn].s>=2) f[i][sni[ksn].s][0]=max(f[i][sni[ksn].s][0],f[i-1][sni[ksn].s-2][4]+val[15]);
			f[i][sni[ksn].s][0]=max(f[i][sni[ksn].s][0],f[i-1][sni[ksn].s][5]+val[15]);
			ksn++;
		}
		else
		{
			for(int j=0;j<=20;j++)
			{
				for(int k=0;k<=5;k++)
				{
					f[i][j][k]=max(f[i][j][k],f[i-2][j][0]);
					if(j<=19) f[i][j][k]=max(f[i][j][k],f[i-1][j+1][1]);
					if(j<=18) f[i][j][k]=max(f[i][j][k],f[i-1][j+2][2]);
					if(j>=1) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][3]);
					if(j>=2) f[i][j][k]=max(f[i][j][k],f[i-1][j-2][4]);
					f[i][j][k]=max(f[i][j][k],f[i-1][j][5]);
				}
				f[i][j][0]+=val[finder[i][j]];
			}
		}
	}
	int maxe=0;
		for(int j=0;j<=20;j++)
		{
			for(int k=0;k<=5;k++)
			{
				maxe=max(maxe,f[m[n].t][j][k]);
			}
		}
	cout<<maxe;
	return 0;
}
