#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+100;
int n,l,r,s[N],cnt1[N],cnt2[N],L=-1,R=-1;
signed main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=r;i++) cnt1[s[i]]++;
	for(int i=l;i<=n;i++) cnt2[s[i]]++;
	for(int i=l-1;i>=1;i--) 
		if(cnt1[s[i]]==1)
		{
			L=i;
			break;
		}
	for(int i=r+1;i<=n;i++) 
		if(cnt2[s[i]]==1)
		{
			R=i;
			break;
		}
		if(L==-1||R==-1) cout<<-1;
	else cout<<R-L+1;
	return 0;
} 
