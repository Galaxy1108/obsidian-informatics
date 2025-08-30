#include<bits/stdc++.h>
using namespace std;
int qpl[4000][11],cnt;
int pl[11],vis[11];
void dfs(int step)
{
	if(cnt>3900) return ;
	if(step>10)
	{
		for(int i=1;i<=cnt;i++)
		{
			bool b=0;
			for(int j=1;j<=10;j++)
			{
				if(abs(pl[j]-qpl[i][j])>1) {b=1;break;}
			}
			if(b==0) return ;
		}
		cnt++;
		for(int i=1;i<=10;i++)
		{
			qpl[cnt][i]=pl[i];
		}
	}
	for(int i=1;i<=10;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		pl[step]=i;
		dfs(step+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	int n;
	cin>>n;
	dfs(1);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		for(int j=1;j<=10;j++)
		{
			printf("%d ",qpl[i][j]);
		}
		printf("\n");
	}
	return 0;
}
