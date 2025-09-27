#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+50;
ll n,m,l,r,s1[N],s2[N],headl,headr,maxa=0,tmp1[N],tmp2[N];
ll k;

template<class T>
inline T read(){
	T x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
} 

void init(){
	l=1;
	r=1;
	headl=0;
	headr=0;
	sort(s1+1,s1+n+1);
	sort(s2+1,s2+m+1);
	k=max(n,m)-min(n,m);
	while(l<=n&&r<=m){
		if(n-l==m-r) break ;
		while(n<=m&&s2[r+1]<=s1[l]&&r<=m) r++;
		while(m<n&&s1[l+1]<=s2[r]&&l<=n) l++;
		if(n<=m) tmp1[r]=s1[l];
		if(m<n) tmp2[l]=s2[r];
		r++;
		l++;
	}
	if(n-l==m-r){
		for(ll i=l;i<=n;i++) tmp1[i+k]=s1[i];
		for(ll i=r;i<=m;i++) tmp2[i+k]=s2[i];
	}
	if(n<=m){
		for(ll i=1;i<=m;i++) s1[i]=tmp1[i];
	}else{
		for(ll i=1;i<=n;i++) s2[i]=tmp2[i];
	}
	return ;
}

void input(){
	n=read<ll>();
	m=read<ll>();
	for(ll i=1;i<=n;i++) s1[i]=read<ll>();
	for(ll i=1;i<=m;i++) s2[i]=read<ll>();
	return ;
}
int main(){
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	input();
	init();
//	for(ll i=1;i<=max(n,m);i++) cout<<s1[i]<<" ";
//	cout<<endl;
//	cout<<endl;
//	cout<<endl;
//	for(ll j=1;j<=max(n,m);j++) cout<<s2[j]<<" ";
//	cout<<endl;
	for(ll i=1;i<=max(n,m);i++){
		if(s1[i]!=0&&s2[i]!=0){
			maxa=max(maxa,abs(s1[i]-s2[i]));
		}
	}
	cout<<maxa<<endl;
	return 0;
}
