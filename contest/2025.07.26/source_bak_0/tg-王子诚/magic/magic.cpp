#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll p[200005],n,q;
ll new_p[200005];
struct s{
	ll t,i,idx,anss;
};

s qs[1000005];

bool calc(){
	int a=0,b=n/2,cnts=0; 
	while(a<n/2 && b<n){
		if(p[a+1]<p[b+1]){
			new_p[++cnts]=p[++a];
		}else{
			new_p[++cnts]=p[++b]; 
		}
	} 
	while(a<n/2){
		new_p[++cnts]=p[++a];
	}
	while(b<n){
		new_p[++cnts]=p[++b]; 
	}
	bool flag=false;
	for(int i=1;i<=n;i++){
		if(new_p[i]!=p[i]){
			flag=true;
		}
		p[i]=new_p[i];
	}
	return flag;
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	ll cnts=0;
	while(q--){
		cnts++;
		cin>>qs[cnts].t>>qs[cnts].i;
		qs[cnts].idx=cnts;
	}
	sort(qs+1,qs+1+cnts,[](s a,s b){
		return a.t<b.t;
	}); 
	bool is_final=false;
	ll this_cnt=0;
	for(int i=1;i<=cnts;i++){
		if(is_final){
			qs[i].anss=p[qs[i].i];
		}else{
			for(;this_cnt<qs[i].t && !is_final;this_cnt++){
				is_final = !calc();
			}
			qs[i].anss=p[qs[i].i];
//			cout<<qs[i].idx<<' '<<qs[i].i<<' '<<qs[i].t<<endl;
		}
	}
	sort(qs+1,qs+1+cnts,[](s a,s b){
		return a.idx<b.idx;
	});
	for(int i=1;i<=cnts;i++){
		cout<<qs[i].anss<<'\n';
//		cout<<qs[i].idx<<'\n';
	}
}
