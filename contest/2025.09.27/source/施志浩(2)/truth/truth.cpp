#include<iostream>
#include<unordered_set>
using namespace std;
int n,k,m,cnt[31],p,v,op,a[50005],i,j,l,mn,ans[50005];
unordered_set <int> s;
int main()
{
	ios::sync_with_stdio(0);
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	cin>>n>>k>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			s.insert(a[j]);
			if(s.size()==k)
			{
				ans[i]=j-i+1;
				s.clear();
				break;
			}
		}
	}
	while(m--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>p>>v;
			cnt[a[p]]--;
			cnt[v]++;
	//		cout<<cnt[a[p]]<<" "<<cnt[v];
			for(l=p-1;l>=1;l--)
				if(a[l]==a[p])
					break;
			a[p]=v;
			if(l==0) l++;
	//		cout<<"	"<<l<<"	"<<p<<'\n';
			for(i=l;i<=p;i++)
			{
				for(j=i;j<=n;j++)
				{
					s.insert(a[j]);
					if(s.size()==k)
					{
						ans[i]=j-i+1;
						s.clear();
						break;
					}
				}
			}
		}
		if(op==2)
		{
			bool flag=0;
			for(i=1;i<=k;i++)
				if(cnt[i]==0)
				{
					cout<<-1<<'\n';
					flag=1;
					break;
				}
			if(flag)
				continue;
			mn=n+1;
			for(i=1;i<=n;i++)
			{
		//		cout<<ans[i]<<" ";
				if(ans[i]==0)
					continue;
				else
					mn=min(mn,ans[i]);
			}
			cout<<mn<<'\n';
		}
	}
	return 0;
}
/*
8 3 22
1 2 3 2 3 1 2 2

*/

/*
4 3 5 
2 3 1 2 
2 
1 3 3 
2 
1 1 1 
2

6 3 6 
1 2 3 2 1 1 
2 
1 2 1 
2 
1 4 1 
1 6 2 
2

*/

