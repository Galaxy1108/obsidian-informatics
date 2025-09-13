#include<bits/stdc++.h>
using namespace std;
int k;
int t;
int n;
int x;
int f[1000100][2];
int ansa=0,ansb=0;
int mod=998244353;
int b[10001];
int len=0;
void DFS(int tot,int num,int minn)
{
	if(tot<minn&&tot>0&&num>0)
	{
		return;
	}
	if(tot<=0&&num!=0)
	{
		return;
	}
	if(num<=0&&tot!=0)
	{
		return;
	}
	if(tot==0&&num==0)
	{
		ansb++;
		ansb%=mod;
		return;
	}
	for(int i=minn;i<=tot/num+1;i++)
	{
		b[++len]=i;
		DFS(tot-i,num-1,i);
		len--;
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(k>n/2)
		{
			cout<<n<<" "<<1<<endl;
			continue;
		}
		ansa=ansb=0;
		if(k==1)
		{
			memset(f,0,sizeof(f));
			f[1][1]=1;
			f[1][0]=0;
			for(int i=2;i<=n;i++)//1yes
			{
				f[i][0]+=f[i-1][1]+f[i-1][0];
				if(i!=n)
				{
					f[i][1]+=f[i-1][0];
				}
				f[i][0]%=mod;
				f[i][1]%=mod;
			}
			ansa+=f[n][0];
			ansa%=mod;
			
			memset(f,0,sizeof(f));
			f[1][1]=0;
			f[1][0]=1;
			for(int i=2;i<=n;i++)//1no
			{
				f[i][0]+=f[i-1][1]+f[i-1][0];
				f[i][1]+=f[i-1][0];
				f[i][0]%=mod;
				f[i][1]%=mod;
			}
			ansa+=(f[n][0]+f[n][1]);
			ansa%=mod;
			ansa=(ansa+mod-1)%mod;
		}
		else
		{
			//k!=1  ansa
			
		}
		//ansb
		x=n/(k+1);
		for(int i=1;i<=x;i++)
		{
			int j=n-i;
			//j-> i*()>=k 
			DFS(j,i,k);
		}
		cout<<ansa<<" "<<ansb<<endl;
	}
}
/*
1
6
5
6
8
9
10
*/
