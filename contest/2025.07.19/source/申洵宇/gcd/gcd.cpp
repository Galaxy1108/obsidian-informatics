#include <bits/stdc++.h>
using namespace std;
/*
f(n,m)=floor(n/k)*floor(m/k)*sum(i=1~min(n/k,m/k)){miu(i)}
p/i=k的i是p/(k+1)+1~p/k 

整除分块有16倍常数，卡不过？ 
*/
#define N 1000005
struct node{
	int fi,se;
};
int pw[N];
long long f[N];
//long long cnt=0;
vector<int>pr;
bitset<N>book;
void init(int n=1000000){
	book[0]=book[1]=1;
	f[0]=0,f[1]=1;
	pw[1]=1;
	for(int i=2;i<=n;i++){
		if(!book[i]){
			pr.emplace_back(i);
			f[i]=-1;
			pw[i]=i;
		}
		for(auto v:pr){
			if(1ll*v*i>n)break;
			book[v*i]=1;
			if(i%v==0){
				if(i==pw[i]){
					f[v*i]=0;
				}
				else{
					f[v*i]=f[i/pw[i]]*f[v*pw[i]];
				}
				pw[v*i]=pw[i]*v;
				break;
			}
			f[v*i]=f[v]*f[i];
			pw[v*i]=v;
		}
	}
	for(int i=1;i<=n;i++){
		f[i]+=f[i-1];
	}
}
inline long long calc(long long n,long long m,long long k){
	static node vp[N],vq[N];
	static int cp,cq;
	long long p=n/k,q=m/k;
	int mx=min(p,q);
//	long long res=0;
//	for(int i=min(p,q);i>=1;i--){
//		res+=(p/i)*(q/i)*f[i];
//	}
//	return res;
	cp=cq=0;
	for(register int i=1;1ll*i*i<=p;i++){
		cp++;
		vp[cp].fi=i;
		vp[cp].se=i;
	}
	for(register int i=p/((int)(sqrt(p))+1);i>=1;i--){
		cp++;
		vp[cp].fi=p/(i+1)+1;
		vp[cp].se=p/i;
	}
	while(cp>0&&vp[cp].fi>mx)cp--;
	if(cp>0)vp[cp].se=min(vp[cp].se,mx);
	for(register int i=1;1ll*i*i<=q;i++){
		cq++;
		vq[cq].fi=i;
		vq[cq].se=i;
	}
	for(register int i=q/((int)(sqrt(q))+1);i>=1;i--){
		cq++;
		vq[cq].fi=q/(i+1)+1;
		vq[cq].se=q/i;
	}
	while(cq>0&&vq[cq].fi>mx)cq--;
	if(cq>0)vq[cq].se=min(vq[cq].se,mx);
//	cerr<<"1~"<<p<<":";
//	for(auto v:vp){
//		cerr<<v.fi<<","<<v.se<<' ';
//	}
//	cerr<<endl<<"1~"<<q<<":";
//	for(auto v:vq){
//		cerr<<v.fi<<","<<v.se<<' ';
//	}
//	cerr<<endl;
//	if(((4*((int)sqrt(max(p,q)))-vp.size()+vq.size())<0))cerr<<4*((int)sqrt(max(p,q)))<<vp.size()+vq.size()<<endl; 
	int lst=1;//上一次还没做的第一个点
	long long res=0; 
	for(register int i=1,j=1;i<=cp&&j<=cq;){
//		cnt++;
		if(vp[i].se<vq[j].se){
			//lst~vp[i].se
			res+=(p/lst)*(q/lst)*(f[vp[i].se]-f[lst-1]);
			lst=vp[i].se+1;
			i++;
		}
		else if(vp[i].se>vq[j].se){
			//lst~vq[j].se
			res+=(p/lst)*(q/lst)*(f[vq[j].se]-f[lst-1]);
			lst=vq[j].se+1;
			j++;
		}
		else{
			//lst~vp[i].se/vq[j].se
			res+=(p/lst)*(q/lst)*(f[vp[i].se]-f[lst-1]);
			lst=vp[i].se+1;
			i++,j++;
		}
	}
	return res;
}
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	int T;
	cin>>T;
	int a,b,c,d,k;
	while(T--){
		cin>>a>>b>>c>>d>>k;
		cout<<(calc(b,d,k)-calc(b,c-1,k)-calc(a-1,d,k)+calc(a-1,c-1,k))<<'\n';
	}
//	cerr<<cnt;
	return 0;
}
