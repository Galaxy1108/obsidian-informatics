#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll as[2005][2005];
ll ms[2005];

ll xs[2005];
ll n;
ll nums[2005],tops;

inline ll succ(ll i){
	return (i==n ? 1 : i+1);
}

ll calc_num(){
	ll ans=0;
	nums[++tops]=0;
	nums[++tops]=2000000;
	sort(nums+1,nums+1+tops);
	for(int i=1;i<=tops-1;i++){
		ans+=(nums[i+1]-nums[i])*(nums[i+1]-nums[i]);
	}
	return ans;
}

ll calc(){
	ll ans=0;
	
	
	for(int i=1;i<=n;i++){
		tops=0;
		for(int j=xs[i];j<=ms[i];j++){
			nums[++tops]=as[i][j];
		}
		for(int j=1;j<=xs[succ(i)]-1;j++){
			nums[++tops]=as[succ(i)][j];
		}
		ans+=calc_num();
	}
	return ans;
}

ll anss=LLONG_MAX;

void get_x(int I){
	if(I==n+1){
		anss=min(anss,calc());
		return;
	}
	for(int i=1;i<=ms[I];i++){
		xs[I]=i;
		get_x(I+1);
	}
} 

int main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ms[i];
		for(int j=1;j<=ms[i];j++){
			cin>>as[i][j];
		}
	}
	get_x(1);
	cout<<anss;
	return 0;
}
