#include <bits/stdc++.h>
using namespace std;
#define DIG 15
#define N6 1000005
#define MOD 1000000007ll
long long n,k,dig,lim[DIG],cnow[N6];
vector<long long>cnt,sum; 
map<long long,long long>mp[DIG][2],mcnt;
inline void normalize(long long& x){
	while(x>=MOD)x-=MOD;
}
void solve(){
	for(int di=dig;di>=1;di--){
		mp[di][di==dig][1]+=1;
	}
	for(int di=dig;di>=1;di--){
		for(int islim=0;islim<=1;islim++){
			static long long mx;mx=islim?lim[di]:9;
			for(int i=0;i<=mx;i++){
				for(auto v:mp[di][islim]){
					mp[di-1][islim&&(i==mx)][v.first*((long long)i)]+=v.second;
					normalize(mp[di-1][islim&&(i==mx)][v.first*((long long)i)]);
				}
			}
		}
	}
	for(auto v:mp[0][0]){
		mcnt[v.first]+=v.second;
		normalize(mcnt[v.first]);
	}
	for(auto v:mp[0][1]){
		mcnt[v.first]+=v.second;
		normalize(mcnt[v.first]);
	}
}
int main(){
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	dig=0;
	long long t=n;
	while(t){
		lim[++dig]=t%10;
		t/=10;
	}
	solve();
	priority_queue<long long,vector<long long>,greater<long long>>pq;
	for(auto v:mcnt){
//		cerr<<v.first<<":"<<v.second<<endl;
		if(v.first<1||v.first>n)continue;
		if(pq.size()<k){
			pq.emplace(v.second);
		}
		else if(pq.top()<v.second){
			pq.emplace(v.second);
		}
	}
	while(!pq.empty()){
		cnt.emplace_back(pq.top());
		pq.pop();
	}
	sort(cnt.begin(),cnt.end(),greater<long long>());
	long long ans=0;
	priority_queue<pair<long long,long long>>val;
	for(int i=0;i<cnt.size();i++){
		normalize(cnt[i]);
		val.emplace(cnt[cnow[i]=0]*cnt[i],i);
	}
	while(k>0&&!val.empty()){
		pair<long long,long long>p=val.top();
		val.pop();
		if(p.second==0){
			ans+=p.first%MOD;
			k--;
		}
		else{
			if(k>=2){
				ans+=p.first*2ll%MOD;
				k-=2;
			}
			else if(k>=1){
				ans+=p.first%MOD;
				k--;
			}
		}
		normalize(ans);
		if(cnow[p.second]<cnt.size()-p.second-1){//ÓÐÊý 
			cnow[p.second]++;
			val.emplace(cnt[cnow[p.second]]*cnt[p.second+cnow[p.second]],p.second);
		}
	}
//	for(long long i=0;i<cnt.size()&&k>0;i++){
//		normalize(cnt[i]);
//		sum.emplace_back((i>0?sum[i-1ll]:0)+cnt[i]);
//		normalize(sum[i]);
//		if(k>=2ll*i+1ll){
//			ans+=cnt[i]*((i>0?sum[i-1ll]*2ll:0)+cnt[i])%MOD;
//			normalize(ans);
//			k-=2ll*i+1ll;
//		}
//		else{
//			ans+=cnt[i]*(((k>>1ll)>0?sum[(k>>1ll)-1]*2ll:0)+((k&1ll)?cnt[(k>>1ll)]:0))%MOD;
//			normalize(ans);
//			break;
//		}
//	}
	printf("%lld",ans);
	return 0;
}

