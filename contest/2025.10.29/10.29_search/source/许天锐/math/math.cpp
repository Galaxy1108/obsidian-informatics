#include<bits/stdc++.h>
#define ld long double
#define int long long
using namespace std;
int A,B,flag;
int ans[1000001],cnt;
void dfs(int x,int n,int a,int b,int maxn){
	if(x==n){
		if(b%a!=0)return;
		else ans[x]=b/a,flag=1;
		return;
	}
	ld l=1.0*b*(n-x)/a,r=1.0*b*(n-x+1)/a;
	for(int i=maxn+1;i<=ceil(r);i++){
		int a1=a*i-b,a2=i*b;
		if(a1<0)continue;
		int d=__gcd(a1,a2);
		ans[x]=i;
		dfs(x+1,n,a1/d,a2/d,i);
		if(flag)return;
	}
}
signed main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	cin>>A>>B;
	int d=__gcd(A,B);
	A/=d,B/=d;
	if(A==1){
		cout<<1<<endl<<B<<endl;
		return 0;
	}
	for(int i=2;i<=A*20;i++){
		flag=0;
		dfs(1,i,A,B,1);
		if(flag){
			cnt=i;
			break;
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
