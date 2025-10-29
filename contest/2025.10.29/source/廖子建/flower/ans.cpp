#include<bits/stdc++.h>
#define int long long
#define N 40
using namespace std;
int n,cnt[N+5],last[N+5],a[N*2+5];
string s[N+5];
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
bool dfs(int x){
	if(x>2*n){
		cout<<"if(n=="<<n<<")";
		for(int i=1;i<=n*2;i++){
			cout<<"a["<<i<<"]="<<a[i];
			if(i<n*2)cout<<",";
			else cout<<";";
		}
		cout<<"\n";
//		exit(0);
		return 1;
	}
	int b[N*2+5]={};
	for(int i=1;i<=n;i++){
		if(cnt[i]==0&&x+i+1>2*n)return 0;
		if(cnt[i]==1&&last[i]+i+1<x)return 0;
		if(cnt[i]==1&&b[last[i]+i+1]>0)return 0;
		if(cnt[i]==1)b[last[i]+i+1]=i;
	}
	if(b[x]>0){
		int i=b[x];
		cnt[i]++,a[x]=i;
		if(cnt[i]==1){
			last[i]=x;
		}
		if(dfs(x+1)){
			cnt[i]--;
			if(cnt[i]==0)last[i]=0;
			return 1;
		}
		cnt[i]--;
		if(cnt[i]==0)last[i]=0;
		return 0;
	}
//	cout<<x<<" "<<maxn<<"\n";
	for(int i=1;i<=n;i++){
		if(cnt[i]==2||cnt[i]==1&&last[i]+i+1!=x)continue;
		cnt[i]++,a[x]=i;
		if(cnt[i]==1){
			last[i]=x;
//			if(x+i+1>n*2){
//				cnt[i]--;
//				if(cnt[i]==0)last[i]=0;
//				continue;
//			}
		}
		if(dfs(x+1)){
			cnt[i]--;
			if(cnt[i]==0)last[i]=0;
			return 1;
		}
		cnt[i]--;
		if(cnt[i]==0)last[i]=0;
	}
	return 0;
}
main(){
//	freopen("flower.in","r",stdin);
	freopen("flower1.aaa","w",stdout);
//	n=read();
//	for(int i=1;i<=n;i++)cin>>s[i];
	for(n=1;n<=N;n++){
		if(0<n%4&&n%4<3)continue;
		cerr<<n<<"\n",dfs(1);
	}
	return 0;
}
