#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
const int M=1e2+5;

template<class T>
inline T read(){
	T x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
} 

ll a[M],b[M],c[M],n;
ll s[N];

string tostring(ll x){
	string ret="";
	while(x){
		ret=char(x%10+'0')+ret;
		x/=10;
	}
	return ret ;
}

bool compare(string a,string b){
	if(a.size()!=b.size()) return a.size()>b.size();
	ll tmp=0;
	while(tmp<a.size()){
		if(a[tmp]!=b[tmp]) return a[tmp]>b[tmp];
		tmp++;
	}
	return 1;
}

string maxx(string a,string b){
	if(a=="") return b;
	if(compare(b,a)) return b;
	else return a;
}

string minn(string a,string b){
	if(a=="") return b;
	if(compare(a,b)) return b;
	else return a;
}

string gje(string x,string y){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	string ret="";
	for(ll i=0;i<x.size();i++){
		a[x.size()-i-1]=x[i]-'0';
	}
	for(ll j=0;j<y.size();j++){
		b[y.size()-j-1]=y[j]-'0';
	}
	ll len=x.size()+y.size()+1;
	for(ll i=0;i<x.size();i++){
		for(ll j=0;j<y.size();j++){
			c[i+j]+=a[i]*b[j];
			c[i+j+1]+=c[i+j]/10;
			c[i+j]%=10;
		}
	}
	for(ll i=0;i<=len;i++){
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	while(c[len]==0&&len!=1) len--;
	for(ll i=0;i<=len;i++){
		ret=char(c[i]+'0')+ret;
	}
	return ret ;
}

ll ls[4*N],rs[4*N];
string maxa[4*N],mina[4*N],ans;

void build(ll now,ll l,ll r){
	ls[now]=l;
	rs[now]=r;
	if(l==r){
		maxa[now]=tostring(s[l]);
		mina[now]=tostring(s[r]);
		return ;
	}
	ll mid=(l+r)>>1;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	maxa[now]=maxx(maxa[2*now],maxa[2*now+1]);
	mina[now]=minn(mina[2*now],mina[2*now+1]);
	return ;
}

string ask(ll now,ll l,ll r,ll k){
	if(l<=ls[now]&&rs[now]<=r){
		if(k==0) return mina[now];
		if(k==1) return maxa[now];
	}
	ll mid=(ls[now]+rs[now])>>1;
	string ret="";
	if(l<=mid){
		if(k==0) ret=minn(ret,ask(2*now,l,r,k));
		if(k==1) ret=maxx(ret,ask(2*now,l,r,k));
	}
	if(r>mid){
		if(k==0) ret=minn(ret,ask(2*now+1,l,r,k));
		if(k==1) ret=maxx(ret,ask(2*now+1,l,r,k));
	}
	return ret ;
}

int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	n=read<ll>();
	for(ll i=1;i<=n;i++){
		s[i]=read<ll>();
	}
	build(1,1,n);
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			ans=maxx(ans,gje(gje(ask(1,i,j,1),ask(1,i,j,0)),tostring(j-i+1)));
		}
	}
	cout<<ans<<endl;
	return 0;
}

