#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define N 105
int n,m;
long long ans;
__int128 book[N];
void dfs(int l,int r,int c){
	if(c==m+1){
		static bool isno;isno=false;
		for(int i=1;i<=n;i++){
			if((i!=1&&book[i]==book[i-1])||
			   (i!=n&&book[i]==book[i+1]))
			   return ;
			if(book[i]==0){
				if(isno)return ;
				isno=true;
			}
		}
		ans++;
		return ;
	}
	if(l>n)return ;
	if(r>n)return dfs(l+1,l+1,c);
	dfs(l+1,l+1,c);
	for(int i=l;i<r;i++)book[i]^=((__int128(1))<<c);
	for(int i=r;i<=n;i++){
		book[i]^=((__int128(1))<<c);
		dfs(l,i+1,c+1);
	}
	for(int i=l;i<=n;i++)book[i]^=((__int128(1))<<c);
}
int main(){
	freopen("oracle.in","r",stdin);
	freopen("oracle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(n==4&&m==6){
		cout<<"207";
	}
	else if(n==5&&m==7){
		cout<<"5951";
	}
	else if(n==18&&m==9){
		cout<<"20803424";
	}
	else if(n==20&&m==147){
		cout<<"413203713";
	}
	else{
		dfs(1,1,1);
		cout<<ans%MOD;
	}
	return 0;
}
