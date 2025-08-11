//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
//#define cerr cout
//#define DEBUG
typedef long long ll;
constexpr const int N=2e5,M=N;
struct passenger{
	int d,c;
	bool on;
}a[M+1];
ll x,t;
int n,m,w;
ll s[N+1+1];
ll ans=1ll<<62;
//p ʱ��,1~p-1 ���� step,����վλ�� pos,���� water L ˮ 
void dfs(int p,ll step,int pos,int water,int len){
	#ifdef DEBUG
	for(int i=1;i<=len;i++){
		cerr<<" ";
	}
	cerr<<"dfs("<<p<<","<<step<<","<<pos<<","<<water<<")\n";
	#endif 
	if(step>=ans){
		return;
	}
	if(p>=x){
		ans=min(ans,step);
		return;
	}
	if(s[pos]==p){
		ll maxNeed=ceil(1.0*(s[pos+1]-p)/t)*(m+1)-water;
		for(ll i=maxNeed;i>=!p;i--){
			#ifdef DEBUG
			for(int i=1;i<=len;i++){
				cerr<<" ";
			}cerr<<"��"<<i<<"Lˮ:\n";
			#endif
			dfs(p+1,step+1ll*i*w,pos+1,water+i-!p,len+1);
		}
	}else{
		//˾�� 
		if(p%t==0){
			if(water){
				#ifdef DEBUG
				for(int i=1;i<=len;i++){
					cerr<<" ";
				}
				cerr<<"˾����ˮ\n";
				#endif
				dfs(p+1,step,pos,water-1,len+1);
			}else{
				#ifdef DEBUG
				for(int i=1;i<=len;i++){
					cerr<<" ";
				}
				cerr<<"˾��ûˮ��\n";
				#endif
			}
			return;
		}
		for(int i=1;i<=m;i++){
			if(!a[i].on){
				continue;
			}
			if(a[i].d==p%t){
				if(water){
					#ifdef DEBUG
					for(int i=1;i<=len;i++){
						cerr<<" ";
					}
					cerr<<"�˿�"<<i<<"��ˮ,����"<<water-1<<"L.\n";
					#endif
					dfs(p+1,step,pos,water-1,len+1);
				}else{
					#ifdef DEBUG
					for(int i=1;i<=len;i++){
						cerr<<" ";
					}
					cerr<<"�˿�"<<i<<"ûˮ��,�³�,�˷�"<<a[i].c<<"\n";
					#endif
					a[i].on=false;
					dfs(p+1,step+a[i].c,pos,water,len+1);
					a[i].on=true;
				}
				return;
			}
		}
		#ifdef DEBUG
		for(int i=1;i<=len;i++){
			cerr<<" ";
		}
		cerr<<"���˺�ˮ\n";
		#endif
		//���˺�ˮ 
		dfs(p+1,step,pos,water,len+1);
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>x>>n>>m>>w>>t;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	s[n+1]=x;
	for(int i=1;i<=m;i++){
		cin>>a[i].d>>a[i].c;
		a[i].on=true;
	}
	sort(a+1,a+m+1,[](passenger a,passenger b){
		return a.d<b.d;
	});
	dfs(0,0,0,0,0);
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
