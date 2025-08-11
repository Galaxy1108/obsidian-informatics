#include<bits/stdc++.h>
using namespace std;
int ans[1000][100010];
int n,q,cnt=1;
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
}
void getanswer(int ccnt)
{
	int p1=1,p2=n/2+1;
	int cc=0;
	while(++cc<=n)
	{
		if(p2>n)
		ans[cnt][cc]=ans[cnt-1][p1],p1++;
		else if(p1>n/2)
		ans[cnt][cc]=ans[cnt-1][p2],p2++;
		else if(ans[cnt-1][p1]<ans[cnt-1][p2])
		ans[cnt][cc]=ans[cnt-1][p1],p1++;
		else
		ans[cnt][cc]=ans[cnt-1][p2],p2++;
	}
//	for(int i=1;i<=n;i++)
//	cout<<ans[cnt][i]<<' ';
//	cout<<endl;
	bool flag=0;
	for(int i=1;i<=n;i++)
	if(ans[cnt][i]!=ans[cnt-1][i])
	{
		flag=1;
		break;
	}
	if(flag==1)
	getanswer(++cnt);
	return ;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=fread(),q=fread();
	for(int i=1;i<=n;i++)
	ans[0][i]=fread();
//	cout<<endl;
	getanswer(cnt);
	while(q--)
	{
		int t=fread(),pos=fread();
		if(t>=cnt) cout<<ans[cnt][pos]<<'\n';
		else
		cout<<ans[t][pos]<<'\n';
	}
	return 0;
}
