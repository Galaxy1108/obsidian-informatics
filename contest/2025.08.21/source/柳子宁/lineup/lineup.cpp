#include<bits/stdc++.h>
using namespace std;
int n,ans;
int h[210];
pair<int,int> v[210];
int main()
{
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&h[i]);
		v[i]=make_pair(h[i],i);
	}
	sort(v+1,v+n+1);
	for(int i=1;i<=n;++i){
		if(v[i].second-i>0) ans+=v[i].second-i;
		else ans+=i-v[i].second;
	}
	printf("%d\n",ans);
	return 0;
}