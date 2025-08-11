#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int k,tot;
long long n,N,pre,ans;
int a[110],f[10010];
long long V[10010];
priority_queue<pair<long long,int> > q;
map<long long,long long> mp[15];
int main()
{
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	scanf("%lld%d",&n,&k);
	N=n;
	while(n) a[++tot]=n%10,n/=10;
	for(int i=1;i<a[tot];++i) mp[tot][i]=1;
	pre=a[tot];
	for(int t=tot-1;t>=1;--t){
		for(auto v:mp[t+1]){
			mp[t][v.first*0]+=v.second;
			mp[t][v.first*1]+=v.second;
			mp[t][v.first*2]+=v.second;
			mp[t][v.first*3]+=v.second;
			mp[t][v.first*4]+=v.second;
			mp[t][v.first*5]+=v.second;
			mp[t][v.first*6]+=v.second;
			mp[t][v.first*7]+=v.second;
			mp[t][v.first*8]+=v.second;
			mp[t][v.first*9]+=v.second;
		}
		for(int i=0;i<a[t];++i) ++mp[t][pre*i];
		for(int i=1;i<=9;++i) ++mp[t][i];
		pre=pre*a[t];
	}
	++mp[1][pre];
	tot=0;
	for(auto v:mp[1]){
		if(v.first<=0||v.first>N) continue;
		V[++tot]=v.second;
	}
	sort(V+1,V+tot+1);
	reverse(V+1,V+tot+1);
	for(int i=1;i<=tot;++i){
		f[i]=1;
		q.push(make_pair(V[i]*V[1],i));
	}
	while(k--){
		if(q.empty()) break;
		ans=(ans+q.top().first)%mod;
		int id=q.top().second;
		q.pop();
		++f[id];
		if(f[id]<=tot){
			q.push(make_pair(V[id]*V[f[id]],id));
		}
	}
	printf("%lld\n",ans);
	return 0;
}
