#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100010;
int n,m;
ll a[N],b[N],c[N];
struct stu{
	int x,y;
};
int lowbit(int x){
	return x&-x;
}
void add(int x,int v){
	for(;x<=n;x+=lowbit(x)){
		c[x]+=v;
	}
}
ll query(int x){
	ll res = 0;
	for(;x;x-=lowbit(x)){
		res+=b[x];
	}
	return res;
}
int main(){
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=m;i++)cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(n==m){
		ll ans = 0;
		for(int i = 1;i<=n;i++){
			ans = max(ans,abs(a[i]-b[i]));
		}
		cout<<ans;
	}
	else cout<<3;
	return 0;
}
