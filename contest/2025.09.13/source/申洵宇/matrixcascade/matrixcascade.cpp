#include <bits/stdc++.h>
using namespace std;
int n;
long long x,y;
namespace sub_3{
int mx;
bitset<15>book;
int c[5][5];
class BIT{
public:
#define lowbit(x) ((x)&(-(x)))
	int c[5*5],n;
	void clear(){memset(c,0,sizeof(c));}
	void add(int u,int x){
		for(int i=u;i<=n;i+=lowbit(i)){
			c[i]+=x;
			// cerr<<i<<'\n';
		}
	}
	int ask(int u){
		static int res;res=0;
		for(int i=u;i>=1;i-=lowbit(i)){
			res+=c[i];
			// cerr<<i<<'\n';
		}
		return res;
	}
#undef lowbit
}st;
bool check(){
	st.n=mx;
	st.clear();
	static long long s;
	s=0;
	for(int i=n;i>=1;i--){
		for(int j=n;j>=1;j--){
			s+=st.ask(c[i][j]);
			st.add(c[i][j],1);
		}
	}
	if(s!=x)return false;
	s=0;
	st.clear();
	for(int j=n;j>=1;j--){
		for(int i=n;i>=1;i--){
			s+=st.ask(c[i][j]);
			st.add(c[i][j],1);
		}
	}
	if (s!=y)return false;
	return true;
}
bool dfs(int i,int j){
	// cerr<<i<<' '<<j<<'\n';
	if(i>n){
		// for(int a=1;a<=n;a++){
		// 	for(int b=1;b<=n;b++){
		// 		cerr<<c[i][j]<<' ';
		// 	}
		// 	cerr<<'\n';
		// }
		if(check()){
			cout<<"YES\n";
			for(int a=1;a<=n;a++){
				for(int b=1;b<=n;b++){
					cout<<c[a][b]<<' ';
				}
				cout<<'\n';
			}
			return true;
		}
		else return false;
	}
	if(j>n)return dfs(i+1,1);
	for(int v=1;v<=mx;v++){
		if(!book[v]){
			book[v]=1;
			c[i][j]=v;
			if(dfs(i,j+1))return true;
			book[v]=0;
		}
	}
	return false;
}
void solve(){
	mx=n*n;
	book.reset();
	if(!dfs(1,1)){
		cout<<"NO\n";
	}
}
}
void solve(){
	cin>>n>>x>>y;
	if(x==0){
		if(y==((1ll*n*n*(n-1)*(n-1))>>2)){
			cout<<"YES\n";
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cout<<(i-1)*n+j<<' ';
				}
				cout<<'\n';
			}
		}
		else{
			cout<<"NO\n";
		}
	}
	else if(y==0){
		if(x==((1ll*n*n*(n-1)*(n-1))>>2)){
			cout<<"YES\n";
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cout<<(j-1)*n+i<<' ';
				}
				cout<<'\n';
			}
		}
		else{
			cout<<"NO\n";
		}
	}
	else{
		if(n<=3){
			sub_3::solve();
			return ;
		}
		cout<<"YES\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<(i-1)*n+j<<' ';
			}
			cout<<'\n';
		}
	}
}
int main(){
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}