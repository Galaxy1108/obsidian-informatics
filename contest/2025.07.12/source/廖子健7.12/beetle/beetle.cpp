#include<bits/stdc++.h>
#define int long long
#define N 2500000
#define Mod 1000000007
using namespace std;
int n,k,s[N+5],head=1,tail=1,pre[N+5]={},f[N+5]={},st[N+5][22]={},ans=0,fff[N+5]={};
pair<int,int>q[N+5];
int gmax(int x,int y){
	return max(st[x][((int)log2(y-x+1))],st[y-(1ll<<((int)log2(y-x+1)))+1][((int)log2(y-x+1))]);
}
int fpow(int x,int y){
	if(!y)return 1;
	if(y&1)return fpow(x*x%Mod,y>>1)*x%Mod;
	return fpow(x*x%Mod,y>>1);
}
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
main(){
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)s[i]=read();
	for(int i=2;i<=n;i++){
		if(s[i-1]>=s[i])pre[i]=i-1;
		else pre[i]=pre[i-1];
	}
	for(int i=n;i>0;i--){
		st[i][0]=s[i];
		for(int j=1;i+(1ll<<j)-1<=n;j++)st[i][j]=max(st[i][j-1],st[i+(1ll<<(j-1))][j-1]);
	}
//	cout<<gmax(1,1)<<"\n";
	for(int i=1;i<=n;i++){
//		if(i==1)f[i]=s[i];
//		else f[i]=q[head].first+gmax(q[head].second+1,i);
		fff[i]=LONG_LONG_MAX;
		for(int j=max(i-k,0ll);j<i;j++)fff[i]=min(fff[i],fff[j]+gmax(j+1,i));
//		cout<<fff[i]<<" "<<f[i]<<" "<<q[head].first<<" "<<q[head].second<<" "<<gmax(q[head].second+1,i)<<" "<<s[i]<<" "<<i<<"  dadsad21331312131\n"; 
		ans=(ans+fff[i]%Mod*fpow(23,n-i)%Mod)%Mod;
//		if(i==n)break;
//		if(q[head].second<i-k+1)head++;
//		while(head<=tail&&q[tail].first+gmax(q[tail].second+1,i+1)>f[i]+s[i+1])tail--;
//		q[++tail].first=f[i],q[tail].second=i;
	}
	print(ans);
	return 0;
}
