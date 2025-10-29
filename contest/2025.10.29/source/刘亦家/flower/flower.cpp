#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
using namespace std;
typedef long long ll;
ll n;
ll cnt[45],pos[45];
string name[45];
vector<ll> ans;
inline void dfs(ll sum){
	if(sum==2*n){
		for(auto i:ans)
			cout<<name[i]<<endl;
		exit(0);
	}
	up(i,1,n){
		if(cnt[i]==2){
			pos[i]=sum;
			cnt[i]--;
			ans.push_back(i);
			dfs(sum+1);
			cnt[i]++;
			ans.pop_back();
		}
		else if(cnt[i]==1){
			if(sum-pos[i]-1==i){
				cnt[i]--;
				ans.push_back(i);
				dfs(sum+1);
				cnt[i]++;
				ans.pop_back();
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	up(i,1,n){
		string col;
		cin>>col;
		name[i]=col;
		cnt[i]=2;
	}
	dfs(0);
	return 0;
}