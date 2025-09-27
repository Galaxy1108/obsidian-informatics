#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN=1e5+5;

int N,M;
ll l[MAXN],r[MAXN];

ll ab(ll a,ll b){
	if(a<b) return b-a;
	return a-b;
}

bool checkN(ll maxn){
	int top=1;
	for(int i=1;i<=N;i++){
		while(ab(l[i],r[top])>maxn&&top<=M) top++;
		if(top>M) return 0;
		top++;
	}
	return 1;
}

bool checkM(ll maxn){
	int top=1;
	for(int i=1;i<=M;i++){
		while(ab(r[i],l[top])>maxn&&top<=N) top++;
		if(top>N) return 0;
		top++;
	}
	return 1;
}

ll find_max(){
	ll maxn=0;
	for(int i=1;i<=N;i++) maxn=max(maxn,ab(l[i],r[i]));
	return maxn;
}


int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>l[i];
	for(int i=1;i<=M;i++) cin>>r[i];
	sort(l+1,l+N+1);
	sort(r+1,r+M+1);
	if(N==M){
		cout<<find_max();
		return 0;
	}
	else if(N<M){
		ll ans=1e9;
		ll l=0,r=1e9;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(checkN(mid)){
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		cout<<ans;
		return 0;
	}
	else if(N>M){
		ll ans=1e9;
		ll l=0,r=1e9;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(checkM(mid)){
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
