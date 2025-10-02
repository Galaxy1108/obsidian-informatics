#include<iostream>
#include<algorithm>
using namespace std;
long long a[1000005],res[1000005];
int v[1000005];
struct node
{
	int l,spe,sx;
}c[1000005];
bool cmp(node y,node z)
{
	return (y.l<z.l);
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,q,p,b,op,x,i,cnt1=0,cnt2=0,ans,t=0;
	cin>>n>>m>>q;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]%2==1)
		    cnt1++;
		else
		    cnt2++;
	}
	for(i=1;i<=m;i++)
	{
		cin>>p>>b;
		res[p]=b;
		v[p]=1;
		if(b%2)
		    cnt1--;
		else
		    cnt2--;
	}
	for(i=1;i<=q;i++)
	{
		cin>>op;
		ans=0;
		t=0;
		if(op==1)
		{
			cin>>p;
			v[p]=0;
			if(res[p]%2==1)
		    cnt1++;
		    else
		    cnt2++;
		}
		else
		{
			cin>>p>>x;
			v[p]=1;
			res[p]=x;
			if(x%2)
		    cnt1--;
		    else
		    cnt2--;
		}
		for(int j=1;j<=n;j++)
		{
			if(v[j])
			{
				if(j>1&&abs(res[j]-res[j-1])%2==1)
				    ans++;
			}
			else
			{
				b=j;
				while(v[j]==0&&j<=n)
				    j++;
				if(j>n)
				{
					if(b==1)
					{
						if(cnt1!=0&&cnt2!=0)
					        ans++;
					}
					else
					{
						c[++t].l=j-b;
					    c[t].sx=res[b-1]%2;
					    c[t].spe=1;
					}
					break;
				}
				if(b>1&&abs(res[j]-res[b-1])%2==1)
				    ans++;
				else
				{
					c[++t].l=j-b;
					c[t].sx=res[j]%2;
					if(b==1)
					    c[t].spe=1;
				}
			}
		}
		//cout<<cnt1<<" "<<cnt2<<endl;
		int c1=cnt1,c2=cnt2;
		sort(c+1,c+t+1,cmp);
		for(int j=1;j<=t;j++)
		{
			if(c[j].sx==0)
			{
				if(c[j].l<=c2)
				{
					c2-=c[j].l;
					if(c[j].spe)
					    c[j].spe=0;
				}    
				else
				{
					ans=ans+2;
					if(c[j].spe)
					{
						ans=ans-1;
						c[j].spe=0;
					}    
				}
			}
			if(c[j].sx==1)
			{
				if(c[j].l<=c1)
				{
					c1-=c[j].l;
					if(c[j].spe)
					    c[j].spe=0;
				}    
				else
				{
					ans=ans+2;
					if(c[j].spe)
					{
						ans=ans-1;
						c[j].spe=0;
					}    
				}	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
