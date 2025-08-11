#include <bits/stdc++.h>
using namespace std;
int n,l,r,ans=0x3f3f3f3f,tk;
int s[1000010];
int tong[1000010],pre[1000010],suf[1000010];
set<int> S;
int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	cin>>n>>l>>r;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		pre[i]=tong[s[i]];
		suf[tong[s[i]]]=i;
		tong[s[i]]=i;
	}

	for(int i=n;i>r;i--)
	{
		if(!suf[i]) S.insert(i);
		else if(!suf[suf[i]]) S.erase(suf[i]);
	}
	for(int i=r;i>=l;i--)
		if(suf[i]>r&&!suf[suf[i]])
			S.erase(suf[i]);
	for(int i=l-1;i;i--)
	{
		if(suf[i]&&!suf[suf[i]])
			S.erase(suf[i]);
		if(!pre[i]&&!S.empty())
		{
			tk=*S.begin();
			if(suf[i]==0||tk<suf[i])
				ans=min(ans,tk-i+1);
		}
	}
	if(ans==0x3f3f3f3f) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}