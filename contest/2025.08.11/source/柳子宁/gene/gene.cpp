#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
int n,l,r,ans,x;
int s[1000010],pre[1000010],suf[1000010],tag[1000010],nxt[1000010];
set<int> S;
int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	scanf("%d%d%d",&n,&l,&r);--l,++r;
	for(int i=1;i<=n;++i) scanf("%d",&s[i]);
	for(int i=1;i<=n;++i){
		++pre[s[i]];
		if(tag[s[i]]) nxt[tag[s[i]]]=i;
		tag[s[i]]=i;
	}
	memset(tag,0,sizeof(tag));
	ans=inf;
	for(int i=n;i>=1;--i){
		++suf[s[i]];--pre[s[i]];
		if(suf[s[i]]==1){
			if(i>=r) S.insert(i);
			tag[s[i]]=i; 
		}
		if(suf[s[i]]==2){
			if(tag[s[i]]>=r) S.erase(tag[s[i]]);
		}
		if(i>l) continue;
		if(pre[s[i]]) continue;
		if(S.empty()) continue;
		x=*S.begin();
		if(nxt[i]==0||nxt[i]>x) ans=min(ans,x-i+1);
	}
	if(ans==inf) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}