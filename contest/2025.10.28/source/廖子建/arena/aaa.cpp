#include<bits/stdc++.h>
#define int long long
#define N 500
#define Mod 998244353
using namespace std;
int n,m,a[N+5],b[N+5],ans;
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
void dfs(int x){
	if(x>n){
		ans=(ans+1)%Mod;
//		cout<<"a:";
		for(int i=1;i<=n;i++)b[i]=a[i];//,cout<<a[i]<<" ";
//		cout<<"\n";
		sort(b+1,b+1+n);
		int t=0,tag=0;
		while(t<n){
			if(t==n-1){
				ans=(ans-1+Mod)%Mod;
				break;
			}
			tag+=n-t-1;
			while(t<n&&b[t+1]-tag<1)t++;
		}
//		if(t==n){
//			cout<<a[1]<<" "<<a[2]<<"\n"; 
//		}
		return;
	}
	for(int i=1;i<=m;i++){
		a[x]=i;
		dfs(x+1);
	}
	return;
}
main(){
	freopen("arena.aaa","r",stdin);
	freopen("arena1.aaa","w",stdout);
	string s;
	while(cin>>s){
		cout<<"else "<<s<<"\n";
	}
	return 0;
}
