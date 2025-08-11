#include <bits/stdc++.h>
using namespace std;
int n,a[200005],q;
struct que{
	int t,i,id;
}qu[1000005];
int ans[1000005];
bool cmp(que a,que b)
{
	if(a.t!=b.t) return a.t<b.t;
	return a.i<b.i;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(register int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for(register int i=1;i<=q;i++)
	{
		cin>>qu[i].t>>qu[i].i;
		qu[i].id=i;
	}
	int tot=0;
	sort(qu+1,qu+q+1,cmp);
	bool fl=0;
	for(register int i=1;i<=q;i++)
	{
		int t=qu[i].t,x=qu[i].i;
		if(fl)
		{
			ans[qu[i].id]=a[x];
			continue;
		}
		else
		{
			
			for(register int j=tot;j<t;j++)
			{
				queue <int> s1,s2;
				for(register int j=1;j<=n/2;j++)
				{
					//cout<<a[i]<<" ";
					s1.push(a[j]);
				}
				for(register int j=n/2+1;j<=n;j++){
					//cout<<a[i]<<" ";
					s2.push(a[j]);
				} 
				if(fl)
				{
					break;
				}
				for(register int k=1;k<=n;k++)
				{
//					cout<<k<<" "<<s1.front()<<" "<<s2.front()<<"\n";
//					cout<<s1.size()<<" "<<s2.size()<<"\n";
					if(s1.size()==0)
					{
						if(s2.size()==n/2)
						{
							fl=1;
						}
						for(int l=k;l<=n;l++)
						{
							a[l]=s2.front();
							s2.pop();
						}
						break;
					}
					if(s2.size()==0)
					{
						if(s1.size()==n/2)
						{
							fl=1;
						}
						for(int l=k;l<=n;l++)
						{
							a[l]=s1.front();
							s1.pop();
						}
						break;
					}
					if(s1.front()<s2.front())
					{
						a[k]=s1.front();
						//cout<<a[k]<<" ";
						s1.pop();
					}
					else
					{
						a[k]=s2.front();
					//	cout<<a[k]<<" ";
						s2.pop();
					}
					
				}
				tot++;
			}
			
			ans[qu[i].id]=a[x];
		}
		
	}
	//cout<<"fl:"<<fl<<"\n";
	//cout<<"tot:"<<tot<<"\n";
	for(register int i=1;i<=q;i++)
	{
		cout<<ans[i]<<"\n";
	}
	return 0;
} 
