#include<bits/stdc++.h>
using namespace std;
int f[25][1000005];
int a[1000005],b[1000005],n,q,op,m,lst,now,tmp;
bool flg[25];
int lowbit(int x)
{
	return (x&(-x));
}
void add(int x,int y)
{
	for(int i = x; i <= n; i+=lowbit(i))
	{
		b[i]+=y;
	}
	return;
}
int ret;
int query(int x)
{
	ret=0; 
	for(int i = x; i >= 1; i-=lowbit(i))
	{
		ret+=b[i];
	} 
	return ret;
}
int l,r,mid,ans;
int findpos(int x)
{
	l=1,r=n,ans=-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if((mid-query(mid))>=x)
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;
}
int main()
{
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	lst=n;
	for(int i = 2; i <= 20; i++)
	{
		//cout<<i<<endl;
		f[i][1]=1;
		for(int j = 2; j <= n; j++)
		{
			now=(j+i-1)/i;
			tmp=(j-now)-f[i][j-now]+1;
			//cout<<tmp<<" ";
			f[i][j]=tmp/(i-1)*i+(tmp%(i-1)==0?0:tmp%(i-1)+1);
			//cout<<f[i][j]<<"   ";
		}
		//cout<<endl;
	}
	while(q--)
	{
		cin>>op>>m;
		if(op==1)
		{
			if(flg[m]) continue;
			else
			{
				flg[m]=1; 
				for(int i = 1; i <= n; i+=m)
				{
					if(a[i]==0)
					{
						a[i]=1;
						add(i,1);
						lst--;
					}
				}
			}
		}
		else if(op==2)
		{
			if(lst==0) continue;
			else
			{
				for(int i = 1; i <= n; i+=(m-1))
				{
					now=findpos(i);
					if(now==-1) break;
					if(a[now]==0)
					{
						a[now]=1;
						add(now,1);
						lst--;
					}
				}
			}
		}
		else
		{
			//cout<<lst<<" "<<f[m][lst]<<endl;
			if(lst==0) cout<<"-1\n";
			else cout<<findpos(f[m][lst])<<'\n';
		}
	}
}
