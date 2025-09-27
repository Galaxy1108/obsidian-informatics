#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
const int mx=5e4+10;
int n,k,m;
int a[mx];
int num[50];
map<int,int> ma;
//struct tree
//{
//	int l,r,num[31];
//}
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);	
	n=fread(),k=fread(),m=fread();
	int sum=0; 
	for(int i=1;i<=n;i++) a[i]=fread(),num[a[i]]++;
	for(int i=1;i<=k;i++) sum+=num[i]>=1;
//	build(1,1,n);
	while(m--)
	{
		int op=fread();
		if(op==1)
		{
			int p=fread(),v=fread();
			if(num[a[p]]==1) sum--;
			num[a[p]]--;
			if(num[v]==0) sum++;
			num[v]++;
			a[p]=v;
		}
		if(op==2)
		{
			if(sum!=k)
			{
				cout<<-1<<endl;
				continue;
			}
			else if(k==1)
			{
				cout<<1<<'\n';
			}
			else if(k==2) cout<<2<<'\n';
			else
			{
				int ans=n;
				int p=0;
				int cnt=0;
				ma.clear();
				for(int i=1;i<=n;i++)
				{
					if(i!=1)
					{
						if(ma[a[i-1]]==1) cnt--;
						ma[a[i-1]]--;
					}
					while(cnt<k&&p<n)
					{
						p++;
						if(ma[a[p]]==0) cnt++,ma[a[p]]=1;
						else ma[a[p]]++;
//						cout<<p<<' '<<cnt<<endl;
					}
//					cout<<"?\n";
//					cout<<i<<' '<<p<<endl;
					if(cnt==k)
					ans=min(ans,p-i+1);
				}
				cout<<ans<<endl; 
			}
		}
	}
	return 0;
}


