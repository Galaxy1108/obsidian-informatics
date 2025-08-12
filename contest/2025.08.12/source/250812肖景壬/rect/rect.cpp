#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,f[505][505];
bool canplace[505][505];
char ch;
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin>>ch;
			if(ch=='C') canplace[i][j]=1;
		}
	}
	int l,r,isin;
	for(int i = 1; i <= n; i++)
	{
		isin=0;
		for(int j = 1; j <= m+1; j++)
		{
			if((canplace[i][j])&&isin==0)
			{
				isin=1;
				l=j;
			}
			else if((!canplace[i][j])&&isin)
			{
				r=j-1;
				//cout<<i<<" "<<l<<" "<<r<<" "<<endl; 
				cnt++;
				for(int k = i; k <= n; k++)
				{
					isin=1;
					for(int ll = l; ll <= r; ll++)
					{
						if(!canplace[k][ll]) 
						{
							isin=0;
							break;
						}
					}
					if(!isin) break;
					for(int ll = l; ll <= r; ll++)
					{
						f[k][ll]=cnt;
						canplace[k][ll]=0;
					}
				}
				isin=0;
			 } 
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}
 } 
