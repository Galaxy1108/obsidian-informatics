#include<bits/stdc++.h>
#define int long long
#define N 300
#define lowbit(x) (x&-x)
using namespace std;
int n,t,kx,ky,vis[N*N+5],a[N+5][N+5],tree[N*N+5];
inline int read(){
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
//	int x;
//	cin>>x;
//	return x;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
void modify(int x){
	while(x<=n*n){
		tree[x]+=1;
		x+=lowbit(x);
	}
	return;
}
int query(int x){
	int sum=0;
	while(x){
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}
bool check(){
	int sum=0;
	for(int i=1;i<=n*n;i++)tree[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum+=query(n*n)-query(a[i][j]);
			modify(a[i][j]);
		}
	}
	if(sum!=kx)return 0;
	sum=0;
	for(int i=1;i<=n*n;i++)tree[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum+=query(n*n)-query(a[j][i]);
			modify(a[j][i]);
		}
	}
	if(sum!=ky)return 0;
	return 1;
}
bool dfs(int x,int y){
	if(y>n)y=1,x++;
	if(x>n)return check();
	for(int i=1;i<=n*n;i++){
		if(vis[i])continue;
		vis[i]=1,a[x][y]=i;
		if(dfs(x,y+1)){
			vis[i]=0;
			return 1;
		}
		vis[i]=0;
	}
	return 0;
}
void printAns(bool fl){
	if(fl){
		printf("YES\n");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)print(a[i][j]),putchar(' ');
			putchar('\n');
		}
	}
	else printf("NO\n");
	return;
}
main(){
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	t=read();
	while(t--){
		n=read(),kx=read(),ky=read();
//		cerr<<n<<" "<<kx<<" "<<ky<<" "<<t<<" "<<(kx==0)<<" fifhsdfisudfh\n";
		if(kx==0){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					a[i][j]=(i-1)*n+j;
				}
			}
			printAns(check());
//			cerr<<"t="<<t<<"\n";
		}
		else if(ky==0){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					a[j][i]=(i-1)*n+j;
				}
			}
			printAns(check());
		}
		else if(n<=3)printAns(dfs(1,1));
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					a[i][j]=(i-1)*n+j;
				}
			}
			printAns(1);
		}
	}
	return 0;
}
