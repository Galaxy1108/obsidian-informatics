#include<bits/stdc++.h>
using namespace std;
long long n;
long long k,m,tot;
long long A[110],f[100010];
long long V[100010],ans,mul;
map<long long,long long> mp[15];
priority_queue<pair<long long,int> > q;
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	scanf("%lld%d",&n,&k);
	long long N=n;
	while(N){
		A[++m]=N%10;
		N/=10;
	}
	mul=1;
	for(int i=m;i>=1;--i){
		for(auto v:mp[i+1]){
			if(v.first==0) continue;
			mp[i][v.first*1]+=v.second;
			mp[i][v.first*2]+=v.second;
			mp[i][v.first*3]+=v.second;
			mp[i][v.first*4]+=v.second;
			mp[i][v.first*5]+=v.second;
			mp[i][v.first*6]+=v.second;
			mp[i][v.first*7]+=v.second;
			mp[i][v.first*8]+=v.second;
			mp[i][v.first*9]+=v.second;
		} 
		for(int j=1;j<A[i]+(i==1);++j){
			mp[i][mul*j]++;
		}
		if(i<m){
			for(int j=1;j<10;++j){
				mp[i][j]++;
			}
		}
		mul*=A[i]; 
	}
	for(auto v:mp[1]){
		if(v.first==0) continue;
		V[++tot]=v.second;
	}
	sort(V+1,V+tot+1);
	reverse(V+1,V+tot+1);
	for(int i=1;i<=tot;++i){
		f[i]=1;
		q.push(make_pair(V[i]*V[1],i));
	} 
	while(!q.empty()&&k){
		ans+=q.top().first;
		ans%=1000000007;
		int p=q.top().second;
		q.pop(),--k;
		if(f[p]<tot){
			++f[p];
			q.push(make_pair(V[p]*V[f[p]],p));
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
