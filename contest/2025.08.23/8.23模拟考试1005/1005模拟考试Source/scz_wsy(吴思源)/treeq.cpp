#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	int f=1;char ch;
	while(ch=getchar(),!isdigit(ch))if(ch=='-')f=-1;x=ch-'0';
	while(ch=getchar(),isdigit(ch))x=x*10+ch-'0';x*=f; 
}
struct node{
	int ord,weight,to;
};
node make_node(int a,int b,int c)
{
	node x;
	x.ord=a,x.weight=b,x.to=c;
	return x;
}
vector<node> v[10000001];
long long Max,k;
int c[10000001];
int n,a[10000001],w[10000001],f[10000001];
inline int dfs(int fa,int x,int y)
{
//	cout<<fa<<' '<<x<<endl; 
	long long s=1;
	for(register int i=0;i<v[x].size();i++)
	{
		int t=v[x][i].to;
		if(t==fa)continue;
		s+=dfs(x,t,i);
	}
	long long ans=s*v[fa][y].weight;
	if(ans>=Max)
	{
		if(ans>Max)
		{
		
		k=1;
		c[k]=v[fa][y].ord;
	    }
	    else
	    {
	    	k++;
	    	c[k]=v[fa][y].ord;
		}
		Max=ans;
	}
//	cout<<s<<' '<<ans<<endl;
	return s;
}
int main()
{
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		read(a[i]),read(w[i]);
		v[a[i]].push_back(make_node(i,w[i],i+1));
		v[i+1].push_back(make_node(i,w[i],a[i]));
	} 
	v[0].push_back(make_node(0,0,0));

	for(int i=1;i<=n;i++)
	{
		k=0;
		Max=0;
	    dfs(0,i,0);
	    for(int j=1;j<=k;j++)
	    {
	    //	cout<<i<<' '<<c[j]<<endl;
	    	f[c[j]]++;
		}
	}
	int x=0;
	for(int i=1;i<n;i++)
	{
		x=x^f[i];
	}
	cout<<x<<endl;
	return 0;
}

