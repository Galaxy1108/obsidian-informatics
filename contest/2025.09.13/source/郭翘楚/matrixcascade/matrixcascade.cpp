#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c[310][310],vis[310*310];
int a[114514];
struct BIT
{
	int c[310*310],n;
	void clear(){memset(c,0,sizeof(c));}
	inline int lowbit(int x){return x&(-x);}
	void add(int u,int x)
	{
		for (int i=u;i<=n;i+=lowbit(i))
			c[i]+=x;
	}
	int ask(int u)
	{
		int res=0;
		for (int i=u;i>=1;i-=lowbit(i))res+=c[i];
		return res;
	}
}t;
int main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll n,X,Y;
		scanf("%lld%lld%lld",&n,&X,&Y);
		bool flag=false;
		if(n<=3)
		{
			for(int i=1;i<=n*n;i++)
			{
				a[i]=i;
			}
			do
			{
				t.clear(),t.n=n*n;
				ll s=0;
				double ans=1.0;
				for(int i=0;i<n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						c[i+1][j]=a[i*n+j];
					}
				}
				for (int i=n;i>=1;i--)for(int j=n;j>=1;j--)
					s+=t.ask(c[i][j]),t.add(c[i][j],1);
				if(s!=X)
				{
					continue;
				}
		//		cerr<<n<<' '<<X<<' '<<Y<<' '<<s<<' ';
				s=0;t.clear();
				for (int i=n;i>=1;i--)for (int j=n;j>=1;j--)
					s+=t.ask(c[j][i]),t.add(c[j][i],1);
				if(s!=Y)
				{
					continue;
				}
				if(ans==1.0)
				{
					cout<<"YES"<<endl;
					for(int i=1;i<=n;i++)
					{
						for(int j=1;j<=n;j++)
						{
							cout<<c[i][j]<<" ";
						}
						cout<<'\n';
					} 
					flag=true;
					break;
				}
			}while(next_permutation(a+1,a+1+n*n));
			if(!flag)
			{
				cout<<"NO"<<endl;
			}
		}
		else
		{
			if(min(X,Y)==0)
			{
				if(X==0)
				{
					t.clear(),t.n=n*n;
					for(int i=1;i<=n;i++)
					{
						for(int j=1;j<=n;j++)
						{
							c[i][j]=(i-1)*n+j;
						}
					}
					ll s=0;
					for (int i=n;i>=1;i--)for (int j=n;j>=1;j--)
						s+=t.ask(c[j][i]),t.add(c[j][i],1);
					if(s!=Y)
					{
						cout<<"NO"<<'\n';
					}
					else
					{
						cout<<"YES"<<endl;
						for(int i=1;i<=n;i++)
						{
							for(int j=1;j<=n;j++)
							{
								cout<<c[i][j]<<" ";
							}
							cout<<'\n';
						}
					}
				}
				else if(Y==0)
				{
					t.clear(),t.n=n*n;
					for(int i=1;i<=n;i++)
					{
						for(int j=1;j<=n;j++)
						{
							c[j][i]=(i-1)*n+j;
						}
					}
					ll s=0;
					for (int i=n;i>=1;i--)for(int j=n;j>=1;j--)s+=t.ask(c[i][j]),t.add(c[i][j],1);
					if(s!=X)
					{
						cout<<"NO"<<'\n';
					}
					else
					{
						cout<<"YES"<<endl;
						for(int i=1;i<=n;i++)
						{
							for(int j=1;j<=n;j++)
							{
								cout<<c[i][j]<<" ";
							}
							cout<<'\n';
						}
					}
				}
			}
			else
			{
				int k=n*n;
				if(k*(k-1)/2==X or k*(k-1)/2==Y)
				{
					cout<<"NO"<<'\n';
				}
				else
				{
					cout<<"YES"<<'\n';
					for(int i=0;i<n;i++)
					{
						for(int j=1;j<=n;j++)
						{
							cout<<i*n+j<<" ";
						}
						cout<<'\n';
					}
				}
			}
		}
	}
	return 0;
}

