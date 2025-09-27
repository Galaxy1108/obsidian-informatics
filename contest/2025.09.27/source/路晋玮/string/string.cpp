#include<iostream>
#include<algorithm>
using namespace std;
int a[405],time[3],fa[405];
string s;
struct edge
{
	int u,v,w;
}e[166666];
bool cmp(edge x,edge y)
{
	return(x.w<y.w);
}
int findr(int x)
{
	if(fa[x]==x)
	    return x;
	else
	    return fa[x]=findr(fa[x]);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int l,i,n,ans=0,j,p,cnt=0;
	cin>>s;
	l=s.length();
	for(i=1;i<=l;i++)
	{
		a[i]=s[i-1]-'0';
		time[a[i]]++;
		fa[i]=i;
	}
	n=(l+1)/2;
	if(time[0]>n||time[1]>n||time[2]>n)
	{
		cout<<-1;
		return 0;
	}
	for(i=1;i<=l;i++)
	{
		for(j=i+1;j<=l;j++)
		{
			p++;
			/*if(a[i]==a[j])
			{
				e[p].u=i;
				e[p].u=j;
				e[p].w=114514;
			   } */ 
			if(a[i]!=a[j])
			{
				e[p].u=i;
				e[p].u=j;
				e[p].w=j-i-1;
			 } 
		}
	}
	sort(e+1,e+p+1,cmp);
	for(i=1;i<=p;i++)
	{
		int ra=findr(e[i].u);
		int rb=findr(e[i].v);
		if(ra!=rb)
		{
			ans+=e[i].w;
			fa[ra]=rb;
			cnt++;
		}
		if(cnt==l-1)
		    break;
	}
	cout<<ans;
	return 0;
}
