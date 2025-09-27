#include<bits/stdc++.h>
using namespace std;
const int N=5e4+100;
int minn,n,m,k,cnt[40],a[N];
void get()
{
	memset(cnt,0,sizeof cnt);
	minn=1e9;
	int l=1,r=1;
	for( r=1;r<=n;r++)
	{
		bool check=1;
		cnt[a[r]]++;
		while(cnt[a[l]]>1) cnt[a[l]]--,l++;
		for(int i=1;i<=k;i++) 
			if(!cnt[i])
			{
				check=0;
				break;
			}
		if(check) minn=min(minn,r-l+1);
	}
	if(minn==1e9) minn=-1;
}
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	get();
	while(m--)
	{
		int opt,pos,val;
		cin>>opt;
		if(opt==1)
		{
			cin>>pos>>val;
			a[pos]=val;
		}
		else
		{
			get();
			cout<<minn; 
			puts("");
		}
	}
	return 0;
} 
