#include<bits/stdc++.h>
#define int long long
#define N 200000
#define inf (1ll*INT_MAX*N)
#define lowbit(x) (x&-x)
using namespace std;
struct Node{int l,r;}b[N+5];
int n,m,a[N+5],dp[N+5][2],pre[N+5],suf[N+5],tmp[N*3+5],tree[N*3+5],len;
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
bool cmp(Node x,Node y){
	if(x.l==y.l)return x.r<y.r;
	return x.l<y.l;
}
void modify(int x){
	while(x<=N*3){
		tree[x]++;
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
main(){
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	n=read(),m=read();
//	exit(0);
//	cout<<n<<" "<<m<<"\n";
	for(int i=1;i<=n;i++)tmp[i]=a[i]=read();//,cout<<a[i]<<"\n";
//	exit(0);
	for(int i=1;i<=m;i++)tmp[n+i]=b[i].l=read(),tmp[n+m+i]=b[i].r=read();//,cout<<i<<"\n";
	sort(tmp+1,tmp+1+n+m*2);
	sort(a+1,a+1+n),sort(b+1,b+1+m,cmp);
	a[n+1]=INT_MAX,a[0]=INT_MIN;
	len=unique(tmp+1,tmp+1+n+m*2)-tmp-1;
	for(int i=1;i<=n;i++)modify(lower_bound(tmp+1,tmp+1+len,a[i])-tmp);
	for(int i=1,j=0;i<=m+j;i++){
		b[i-j]=b[i];
//		cout<<i<<" "<<j<<" "<<i-j<<" "<<m<<" "<<b[i].l<<" "<<b[i].r<<"\n";
		if(query(lower_bound(tmp+1,tmp+1+len,b[i].r)-tmp)-query(lower_bound(tmp+1,tmp+1+len,b[i].l)-tmp-1)>0)j++,m--;
	}
//	for(int i=1;i<=m;i++){
//		cout<<"b["<<i<<"]:"<<b[i].l<<" "<<b[i].r<<" "<<(query(lower_bound(tmp+1,tmp+1+len,b[i].r)-tmp)-query(lower_bound(tmp+1,tmp+1+len,b[i].l)-tmp-1)>0)<<"\n";
//	}
	for(int i=1,j=1;i<=m&&j<=n;){
		while(a[j+1]<=b[i].l)j++;
		if(j<=n){
			if(a[j]<=b[i].l)suf[j]=b[i].l;
			i++;
		}
	}
	for(int i=m,j=n;i>0&&j>0;){
		while(a[j-1]>=b[i].r)j--;
		if(j>0){
			if(a[j]>=b[i].r)pre[j]=b[i].r;
			i--;
		}
	}
	for(int i=1;i<=n;i++){
		if(!pre[i])pre[i]=a[i];
		if(!suf[i])suf[i]=a[i];
	}
	if(pre[1]<a[1])dp[1][0]=inf,dp[1][1]=a[1]-pre[1];
	else dp[1][0]=dp[1][1]=0;
	for(int i=2;i<=n;i++){
		dp[i][0]=min(dp[i-1][0]+suf[i-1]-a[i-1],dp[i-1][1]+suf[i-1]-pre[i-1]);
		dp[i][1]=min(dp[i-1][0]+a[i]-pre[i],dp[i-1][1]+a[i]-pre[i]);
	}
	print(min(dp[n][0]+suf[n]-a[n],dp[n][1]+suf[n]-pre[n]));
	return 0;
}
