#include<bits/stdc++.h>
#define int long long
#define N 300
#define M 10000
using namespace std;
int n,p,uu,uv,f[N+5],s[N+5],ans=INT_MAX;
vector<int>edge[N+5];
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
void build(int x){
	s[x]=1;
	for(int i:edge[x]){
		if(i==f[x])continue;
		f[i]=x,build(i),s[x]+=s[i];
	}
	return;
}
void dfs(vector<int>x,int sum){
	int cnt=0,maxn=INT_MIN,p;
//	cout<<"x:";
//	for(int i:x)cout<<i<<" ";
//	cout<<"\nans="<<ans<<"\n";
	for(int i:x){
		for(int j:edge[i]){
			if(j==f[i])continue;
//			cout<<"j="<<j<<" i="<<i<<" "<<f[i]<<"\n";
			cnt++;
			if(maxn<s[j])maxn=s[j],p=cnt;
		}
	}
	if(!cnt){
		ans=min(ans,sum);
		return;
	}
	if(rand()*1.0/RAND_MAX>0.4)p=rand()%cnt+1;
	vector<int>y;
	for(int i:x){
		for(int j:edge[i]){
			if(j==f[i])continue;
			p--;
			if(p!=0)y.push_back(j),sum++;
		}
	}
	dfs(y,sum);
	return;
}
void solve(vector<int>x,int sum){
	vector<int>y;
	while(1){
		int cnt=0,maxn=INT_MIN,p;
		for(int i:x){
			for(int j:edge[i]){
				if(j==f[i])continue;
	//			cout<<"j="<<j<<" i="<<i<<" "<<f[i]<<"\n";
				cnt++;
				if(maxn<s[j])maxn=s[j],p=cnt;
			}
		}
		if(!cnt){
			ans=min(ans,sum);
			return;
		}
		if(rand()*1.0/RAND_MAX>0.3)p=rand()%cnt+1;
		y.resize(0);
		for(int i:x){
			for(int j:edge[i]){
				if(j==f[i])continue;
				p--;
				if(p!=0)y.push_back(j),sum++;
			}
		}
		x=y;
	}
	return;
}
main(){
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	srand(time(0));
	n=read(),p=read();
	for(int i=1;i<=p;i++){
		uu=read(),uv=read();
		edge[uu].push_back(uv);
		edge[uv].push_back(uu);
	}
	build(1);
	vector<int>u;
	u.push_back(1);
	for(int i=1;i<=M;i++)solve(u,1);
	print(ans);
	return 0;
}
