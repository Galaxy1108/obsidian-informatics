#include<bits/stdc++.h>
#define int long long
#define double long double
#define N 1000000
#define M 1000000
#define It set<Node>::iterator
using namespace std;
struct ODT{
	struct Node{
		int l,r,v;
		bool friend operator<(Node const &x,Node const &y){return x.l<y.l;}
	};
	set<Node>tree;
	It split(int p){
		It tx=tree.lower_bound({p,0,0});
		if(tx!=tree.end()&&tx->l==p)return tx;
		tx=prev(tx);
		int tl=tx->l,tr=tx->r,tv=tx->v;
		tree.erase(tx),tree.insert({tl,p-1,tv});
		return tree.insert({p,tr,tv}).first;
	}
	void assign(int l,int r,int v){
		It tr=split(r+1),tl=split(l);
		tree.erase(tl,tr);
		tree.insert({l,r,v});
		return;
	}
	int query(int p){
		It u=tree.lower_bound({p,0,0});
		if(u!=tree.end()&&u->l==p)return u->v;
		u--;
		return u->v;
	}
	void printTree(){
		for(It i=tree.begin();i!=tree.end();i++){
			cout<<i->l<<" "<<i->r<<" "<<i->v<<" printTree\n";
		}
		return;
	}
}pre,nex;
double const eps=1e-12,T0=2000000,Tk=1e-5,D=0.98,eT=0.9;
int n,X[N],P[N+5],C[N+5],sum[N+5],bans=LONG_LONG_MAX,ans,ur,uv,un,up,dp[2][N+5];
bool a[N+5];
mt19937 rnd;
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
void init(){
	rnd.seed(time(0)),srand(time(0));
	n=read();
	for(int i=1;i<=n;i++){
		X[i]=read(),P[i]=read(),C[i]=read();
		sum[i]=sum[i-1]+P[i];
	}
	return;
}
int getEngery(){
	int Sum=0,Ans=0;
	for(int i=1;i<=n;i++){
		if(a[i])Ans+=C[i],Sum=0;
		else Sum+=P[i],Ans+=(X[i+1]-X[i])*Sum;
//		cout<<a[i]<<" "<<P[i]<<" "
	}
	return Ans;
}
int dEngery(int p){
	int la=pre.query(p),lb=p,lc=nex.query(p);
//	cout<<la<<" "<<lb<<" "<<lc<<" "<<(X[lb]-X[lc])<<" "<<(sum[lb]-sum[la])<<" "<<C[lb]<<" dEngery\n";
	return (X[lb]-X[lc])*(sum[lb]-sum[la])+C[lb];
}
void solve(){
	pre.tree.clear(),nex.tree.clear();
	pre.tree.insert({0,n+1,0}),nex.tree.insert({0,n+1,0});
	a[n]=1;
//	pre.assign(1,1,1);
	for(int i=1;i<n;i++)a[i]=rand()%2;
	for(int i=1;i<=n;i++){
		if(a[i-1])pre.assign(i,i,i-1);
		else pre.assign(i,i,pre.query(i-1));
	}
	for(int i=n;i>0;i--){
//		cout<<i<<" "<<a[i]<<" "<<rand()<<" nex\n";
		if(a[i+1])nex.assign(i,i,i+1);
		else nex.assign(i,i,nex.query(i+1));
//		nex.printTree();
	}
	ans=getEngery();
//	cout<<ans<<" Engery\n";
	bans=min(bans,ans);
	for(double t=T0;t>Tk;t*=D){
		ur=rand()%(n-1)+1;
		uv=dEngery(ur)*(a[ur]?-1:1);
//		cout<<ur<<" "<<uv<<" "<<ans<<" "<<dEngery(ur)<<" run\n";
		if(uv<0||exp((-uv)*1.0/t)>rand()*1.0/RAND_MAX){
			ans+=uv,bans=min(bans,ans);
			if(a[ur]){
				un=nex.query(ur),up=pre.query(ur);
				pre.assign(ur+1,un,up);
				nex.assign(up,ur-1,un);
			}
			else{
				un=nex.query(ur),up=pre.query(ur);
				pre.assign(ur+1,un,ur);
				nex.assign(up,ur-1,ur);
			}
			a[ur]=!a[ur];
		}
	}
	return;
}
main(){
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	init();
	if(n<=30000){
		for(int i=1;i<=n+1;i++)dp[1][i]=LONG_LONG_MAX;
		dp[1][1]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n+1;j++)dp[i&1^1][j]=LONG_LONG_MAX;
			for(int j=1;j<=i;j++){
				if(dp[i&1][j]==LONG_LONG_MAX)continue;
				dp[i&1^1][j]=min(dp[i&1^1][j],dp[i&1][j]+(X[i+1]-X[i])*(sum[i]-sum[j-1]));
				dp[i&1^1][i+1]=min(dp[i&1^1][i+1],dp[i&1][j]+C[i]);
			}
		}
		print(dp[n&1^1][n+1]);
		return 0;
	}
	while(clock()<=CLOCKS_PER_SEC*eT)solve();
	print(bans);
	return 0;
}
