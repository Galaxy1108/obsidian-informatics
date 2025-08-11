#include<bits/stdc++.h>
#define int long long
using namespace std;
#define Mod 1000000007
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
const int N=2500010;
struct node{
	int w,id;
};
struct Deque{
	int h=2500000,t=2500001;
	node l[2*N];
	inline void push_front(node num){
		l[++h].w=num.w,l[h].id=num.id;
	}
	inline void push_back(node num){
		l[--t].w=num.w;l[t].id=num.id;
	}
	inline void pop_front(){
		h--;
	}
	inline void pop_back(){
		t++;
	}
}q;
int n,k;
int S[N];
//int read(){
//	int res=0;
//	char c=getchar();
//	while(c<'0'||c>'9') c=getchar();
//	while('0'<=c&&c<='9'){
//		res=res*10+(c-'0');
//		c=getchar();
//	}
//	return res;
//}
int f[N];
int _23[N];
signed main(){
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0); 
	n=Qread(),k=Qread();
	for(int i=1;i<=n;i++) S[i]=Qread();
	_23[0]=1;
	for(int i=1;i<=n;i++){
		_23[i]=_23[i-1]*23%Mod;
	}
	int ans=0;
//	int sum=0;
	for(int i=1;i<=n;i++){
		f[i]=LONG_LONG_MAX;
		if(n*k<=1e8){
			int maxx=0;
			for(int j=i;j>=max(1ll,i-k+1);j--){
				maxx=max(maxx,S[j]);
				f[i]=min(f[i],f[j-1]+maxx);
			}
			ans=(ans+(f[i]%Mod*_23[n-i]%Mod))%Mod;			
		}
		else{
			if(q.h>=q.t&&i-q.l[q.t].id+1>k) q.pop_back();//Î¬³ÖÇø¼ä 
			while(q.h>=q.t){
				if(S[i]>q.l[q.h].w) q.pop_front();
				else break;
			}
			q.push_front((node){S[i],i});
			node top=q.l[q.t];
			if(q.h>q.t){
				node top2=q.l[q.t+1];
				f[i]=f[top.id]+top2.w;
			}
			f[i]=min(f[i],f[max(1ll,i-k+1)-1]+top.w);
			ans=(ans+(f[i]%Mod*_23[n-i]%Mod))%Mod;	
		}
//		sum+=S[i];
//		cout<<f[i]<<' '<<sum<<'\n';
	}
//	cout<<'\n';
	printf("%d\n",ans);
	return 0;
}

