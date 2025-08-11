#include <bits/stdc++.h>
using namespace std;
bool mp[12][600]; 
int cs[15]={1,2,5,11,23,47,95,191,383,767};
int f[15]={1,2,4,8,16,32,64,128,256,512};
int kg[15]={3,5,11,23,47,95,191,383,767};
int m,n;
inline void dfs(int i,int c)
{
//	cout<<c;
	mp[c][i]=1;
	if(c>=m)
	{
		return ;
	}
	dfs(i*2-1,c+1);
	dfs(i*2,c+1);
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(register int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[x][y]=1;
		dfs(y,x);
	} 
	int tot=1;
	int k=1,o=m-2;
	while(o--)
	{
		k*=2;
	}
	k=k*6;
	for(register int i=1;i<m;i++)
	{
		
		int c=(k+1)>>1;
		c-=tot;
		//cout<<c<<" "<<tot;
		for(register int j=0;j<c;j++) cout<<" ";
		for(register int j=1;j<=f[i-1];j++)
		{
			if(mp[i][j])
			{
				cout<<" ";
			}
			else
			{
				cout<<"o";
			}
			for(register int p=1;p<=kg[m-i];p++) cout<<" ";
		}
		cout<<"\n";
		int fd=1;
		if(i==m)
		{
			break;
		}
		for(register int j=1;j<=cs[m-i-1];j++)
		{
			tot++;
			int c=(k+1)>>1;
			c-=tot;
			for(int i=0;i<c;i++) cout<<" ";
			for(int k=1;k<=f[i-1];k++)
			{	
				if(mp[i+1][k*2-1])
				{
					//cout<<i+1<<" "<<k<<"\n";
					cout<<" ";
				}
				else
				{
					cout<<"/";
				}
				for(int e=1;e<=fd;e++)
				{
					cout<<" ";
				}
				if(mp[i+1][k*2]) cout<<" ";
				else cout<<"\\";
				for(int e=1;e<=c*2+1;e++) cout<<" ";
			}
			fd+=2;
			cout<<"\n";
		}
		tot++;
		
	}
	for(register int j=1;j<=f[m-1];j++)
	{
		if(mp[m][j])
		{
			cout<<" ";
		}
		else
		{
			cout<<"o";
		}
		if(j%2==1){
			cout<<"   ";
		}
		else
		{
			cout<<" ";
		 } 
		
	}
	cout<<"\n";
	return 0;
} 
