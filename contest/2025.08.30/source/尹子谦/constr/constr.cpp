#include<bits/stdc++.h>
using namespace std;
int qpl[200000][11],cnt=1,lst[10];
int pl[11],vis[11],n;
void dfs(int step)
{
	if(cnt>7000) return ;
	if(step>10)
	{
		for(int i=cnt;i>=1;i--)
		{
			bool b=0;
			for(int j=1;j<=10;j++)if(abs(pl[j]-qpl[i][j])>1) {b=1;break;}
			if(b==0) return ;
		}
		cnt++;
		for(int i=1;i<=10;i++) cout<<pl[i]<<' ',qpl[cnt][i]=pl[i];
		cout<<endl;
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
	cin>>n; 
	cout<<7000<<endl;
	dfs(1);
	return 0;
}
