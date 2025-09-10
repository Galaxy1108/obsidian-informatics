#include<bits/stdc++.h>
using namespace std;
int k,n;
int a[420][420];
bool f=0;
int check()
{
	int ans=0; 
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int z=j+1;z<=n;z++)
			{
				if(a[i][j]==a[i][z]&&a[i][j]==a[j][z])
				{
					ans++;
				}
			}
		}
	}
	return ans;
}
void DFS(int x,int y)
{
	if(f)
	{
		return;
	}
	if(x==n)
	{
		if(check()<=0)
		{
			cout<<n<<endl;
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<"---------"<<endl;
		//	f=1;
		}
		return;
	}
	for(int i=0;i<k;i++)
	{
		a[x][y]=i;
		if(y!=n)
		{
			DFS(x,y+1);
		}
		else
		{
			DFS(x+1,x+2);
		}
	}
}
int main()
{
	cin>>k;
	int f[7]={0,2,5,10,45,139,416};
	n=f[k];
	cout<<"------------"<<endl;
	DFS(1,2);
}
