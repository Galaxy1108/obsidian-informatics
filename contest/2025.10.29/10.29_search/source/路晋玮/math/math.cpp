#include<iostream>
#include<algorithm>
using namespace std;
int ys[1000005],top,m,n,minl=2e8,ans[1000005],flag=0;
void dvd(int x)
{
	top=0;
	ys[++top]=1;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			ys[++top]=i;
			if(x/i!=i)
			    ys[++top]=x/i;
		}
	}
	return ;
}
void dfs(int k,int s,int lst)
{
	if(s==n)
	{
		minl=min(minl,k);
		return ;
	}
	for(int i=lst+1;i<=top;i++)
	{
		if(s+ys[i]<=m)
		    dfs(k+1,s+ys[i],i);
		else
		    break;
	}
	return ;
}
void dfsagain(int k,int s,int lst)
{
	if(s==n)
	{
		if(k==minl)
		    flag=1;
		return ;
	}
	for(int i=lst+1;i<=top;i++)
	{
		if(s+ys[i]<=m)
		{
			ans[k]=ys[i];
			dfsagain(k+1,s+ys[i],i);
			if(flag)
			    return ;
		}    
		else
		    break;
	}
	return ;
}
int main()
{
	freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
	int a,b,i,j;
	cin>>a>>b;
	while(minl==2e8)
	{
		m+=a;
		n+=b;
		dvd(n);
		sort(ys+1,ys+top+1);
		dfs(0,0,0);
	}
	cout<<minl<<endl;
	dfsagain(0,0,0);
	for(i=0;i<minl;i++)
	    cout<<ans[i]<<" ";
	return 0;
}
