#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,ans[N][N],cnt;
bool mp[N][N];
signed main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	    {
	    	char ch;
	    	cin>>ch;
	    	if(ch=='C') mp[i][j]=1;
		}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j])
			{
				int h=1;
				while(mp[i][j+h-1]) h++;
				h--;
				int k=1;
				bool b=0;
				for(;k<=n;k++)
				{
					if(b) break;
					for(int p=j;p<=h+j-1;p++) 
					{
						if(!mp[i+k][p])
						{
							b=1;
							break;
						}
					}
				}
				k--;
				cnt++;
				for(int p=i;p<=i+k-1;p++) 
					for(int q=j;q<=j+h-1;q++)
						ans[p][q]=cnt,mp[p][q]=0;
			}
		}
	}
	for(int i=1;i<=n;i++,cout<<endl)
	    for(int j=1;j<=m;j++)
	    	cout<<ans[i][j]<<' ';
	return 0;
}
