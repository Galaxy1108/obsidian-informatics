#include<bits/stdc++.h>
using namespace std;
const int N = 101;
struct node{
	int l, r;
}a[N];
long long  n, m, ans, p;
void dfs(int now){
	if(now==n+1){
		ans++;
		ans%=p;
		return ;
	}
	if(now==1){
		for(int i=1;i<=m;i++){
			for(int j=i;j<=m;j++){
				a[now]={i, j};
				dfs(now+1);
			}
		}
	}else{
		for(int i=1;i<=m;i++){
			for(int j=i;j<=m;j++){
				if((a[now-1].l<=i&&i<=a[now-1].r)||(a[now-1].r<=j&&j<=a[now-1].r)||(i<=a[now-1].l&&j>=a[now-1].r)){
					a[now] = {i, j};
					dfs(now+1);
				}
			}
		}
	}
}
void get(int x){
	cout<<" = ";
	for(int i=2;i<=sqrt(x);i++){
		while(x%i==0){
			cout<<i<<" * ";
			x/=i;
		}
	}
	if(x!=1) cout<<x;
	cout<<"\n";
}
int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin>>n>>m>>p;
	if(n==1){
		cout<<(m*(m-1)/2)%p;
	}else if(m==1){
		cout<<"1";
	}else{
		dfs(1);
		cout<<ans;
	}
	
//	int last=0;last=0;
//	for(int i=1;i<=10;i++){
//		
//		for(int j=3;j<=3;j++){
//			ans=0;
//			n=i, m=j;
//			dfs(1);
//			cout<<"|"<<ans-last;
//			get(ans-last);
//			cout<<n<<" "<<m<<" "<<ans<<endl;
//			last=ans;
//		}
//	}
	return 0;
}
