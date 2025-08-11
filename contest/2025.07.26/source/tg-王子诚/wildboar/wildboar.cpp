#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct s{
	ll v,w,last;
	friend bool operator<(s a,s b){
		return a.w>b.w;
	} 
};

struct s2{
	ll v,w;
};
//ll last_ro[2005];
//ll new_last_ro[2005];
priority_queue<s> pq;
vector<s2> maps[2005]; 
ll xs[100005];
ll min_l[100005];

bool is_s[100005];

int main(){
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	ll n,m,t,l;
	cin>>n>>m>>t>>l;
	for(int i=1;i<=m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		maps[a].emplace_back((s2){b,c});
		maps[b].emplace_back((s2){a,c});
	}
	for(int i=1;i<=l;i++){
		cin>>xs[i];
	}
	while(t--){
		ll p,q;
		cin>>p>>q;
		xs[p]=q;
		ll anss=0;
		ll lss=-1;
		bool fflag=false;
		for(int i=1;i<l;i++){
			pq.push({xs[i],0,lss});
			for(int j=1;j<=n;j++){
				min_l[j]=INT_MAX;
			}
			min_l[xs[i]]=0;
			while(!pq.empty()){
				s u=pq.top();
				pq.pop();
				bool flag=false;
				for(auto v:maps[u.v]){
					ll vs=v.v;
//					cout<<u.v<<' '<<v.v<<' '<<u.last<<' '<<u.w+v.w<<' '<<min_l[vs]<<'\n';
					if(v.v==u.last){
						continue;
					}
					min_l[vs]=min(min_l[vs],u.w+v.w);
					if(v.v==xs[i+1]){
						lss=u.v;
						flag=true;
						break;
					} 
//					cout<<"TEST\n";
					pq.push({v.v,u.w+v.w,u.v}); 
//					cout<<"P:"<<v.v<<' '<<u.w+v.w<<' '<<u.v<<endl;
				}
				if(flag){
					break;
				}
			}
			while(!pq.empty()){
				pq.pop();
			}
			if(min_l[xs[i+1]]==INT_MAX){
				cout<<-1;
				fflag=true;
				break;
			}
			anss+=min_l[xs[i+1]];
		}
		if(fflag){
			continue;
		}
		cout<<anss<<'\n';
	}
} 
