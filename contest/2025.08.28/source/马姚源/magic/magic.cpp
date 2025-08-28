
#include <bits/stdc++.h>
#define lc (p<<1)
#define rc (p<<1|1)
#define int long long
using namespace std;
/*
需要维护：
a[i],b[i],c[i]的和
a[i]addtag
b[i]multag
c[i]covertag
a[i]+b[i]可以用和来算出来 
*/
const int N=2.5e5+10;
const int mod=998244353;
struct TreeNode{
	int l,r;
	int suma,sumb,sumc;
	int taga,tagb,tagc;
	int tagab,tagbc,tagac;
}tree[N<<2];
int a[N],b[N],c[N];
int Mod(int x){
	return ((x)%mod);
}
void up(int p){
	tree[p].suma=Mod(tree[lc].suma+tree[rc].suma);
	tree[p].sumb=Mod(tree[lc].sumb+tree[rc].sumb);
	tree[p].sumc=Mod(tree[lc].sumc+tree[rc].sumc);
}
void build(int p,int l,int r){
	tree[p].l=l,tree[p].r=r;
	tree[p].tagb=1;
	if(l==r){
		tree[p].suma=a[l];
		tree[p].sumb=b[l];
		tree[p].sumc=c[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	up(p);
}
void down(int p){
	if(tree[p].taga){
		tree[lc].taga+=tree[p].taga;
		tree[lc].taga=Mod(tree[lc].taga);
		tree[rc].taga+=tree[p].taga;
		tree[rc].taga=Mod(tree[rc].taga);
		tree[lc].suma+=tree[p].taga%mod*(tree[lc].r-tree[lc].l+1);
		tree[lc].suma=Mod(tree[lc].suma);
		tree[rc].suma+=tree[p].taga*(tree[rc].r-tree[rc].l+1);
		tree[rc].suma=Mod(tree[rc].suma);
		tree[p].taga=0;
	}
	if(tree[p].tagac){
		tree[lc].sumc+=tree[lc].suma%mod;
		tree[lc].sumc=Mod(tree[lc].sumc);
		tree[rc].sumc+=tree[rc].suma;
		tree[rc].sumc=Mod(tree[rc].sumc);
		tree[lc].tagac=tree[rc].tagac=tree[p].tagac;
		tree[p].tagac=0;
	}
	if(tree[p].tagc){
		tree[lc].sumc=tree[p].tagc*(tree[lc].r-tree[lc].l+1);
		tree[lc].sumc=Mod(tree[lc].sumc);
		tree[rc].sumc=tree[p].tagc*(tree[rc].r-tree[rc].l+1);
		tree[rc].sumc=Mod(tree[rc].sumc);
		tree[lc].tagc=tree[rc].tagc=tree[p].tagc;
		tree[p].tagc=0;
	}
	if(tree[p].tagb!=1){
		tree[lc].tagb*=tree[p].tagb%mod;
		tree[lc].tagb=Mod(tree[lc].tagb);
		tree[rc].tagb*=tree[p].tagb;
		tree[rc].tagb=Mod(tree[rc].tagb);
		tree[lc].sumb*=tree[p].tagb;
		tree[lc].sumb=Mod(tree[lc].sumb);
		tree[rc].sumb*=tree[p].tagb;
		tree[rc].sumb=Mod(tree[rc].sumb);
		tree[p].tagb=1;
	}
	if(tree[p].tagbc){
//		tree[lc].sumb+=(tree[lc].tagc)?(tree[lc].tagc*(tree[lc].r-tree[lc].l+1)):(tree[lc].sumc);
		tree[lc].sumb+=tree[lc].sumc%mod;
		tree[lc].sumb=Mod(tree[lc].sumb);
//		tree[rc].sumb+=(tree[rc].tagc)?(tree[rc].tagc*(tree[rc].r-tree[rc].l+1)):(tree[rc].sumc);
		tree[rc].sumb+=tree[rc].sumc;
		tree[rc].sumb=Mod(tree[rc].sumb);
		tree[lc].tagbc=tree[rc].tagbc=tree[p].tagbc;
		tree[p].tagbc=0;
	}
	if(tree[p].tagab){
//		tree[lc].suma+=tree[lc].sumb%mod*tree[lc].tagb;
		tree[lc].suma+=tree[lc].sumb%mod;
		tree[lc].suma=Mod(tree[lc].suma);
//		tree[rc].suma+=tree[rc].sumb%mod*tree[rc].tagb;
		tree[rc].suma+=tree[rc].sumb%mod;
		tree[rc].suma=Mod(tree[rc].suma);
		tree[lc].tagab=1;
		tree[rc].tagab=1;
		tree[p].tagab=0;
	}
		

		
}
void update_Asum(int p,int ql,int qr){
	if(ql<=tree[p].l&&tree[p].r<=qr){
		tree[p].suma+=tree[p].sumb%mod;
		tree[p].suma=Mod(tree[p].suma);
		tree[p].tagab=1;
		return;
	}
	down(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(ql<=mid)update_Asum(lc,ql,qr);
	if(qr>mid)update_Asum(rc,ql,qr);
	up(p);
}
void update_Bsum(int p,int ql,int qr){
	if(ql<=tree[p].l&&tree[p].r<=qr){
		tree[p].sumb+=tree[p].sumc%mod;
		tree[p].sumb=Mod(tree[p].sumb);
		tree[p].tagbc=1;
		return;
	}
	down(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(ql<=mid)update_Bsum(lc,ql,qr);
	if(qr>mid)update_Bsum(rc,ql,qr);
	up(p);
}
void update_Csum(int p,int ql,int qr){
	if(ql<=tree[p].l&&tree[p].r<=qr){
		tree[p].sumc+=tree[p].suma%mod;
		tree[p].sumc=Mod(tree[p].sumc);
		tree[p].tagac=1;
		return;
	}
	down(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(ql<=mid)update_Csum(lc,ql,qr);
	if(qr>mid)update_Csum(rc,ql,qr);
	up(p);
}
void update_A(int p,int ql,int qr,int x){
	if(ql<=tree[p].l&&tree[p].r<=qr){
		tree[p].suma+=x*(tree[p].r-tree[p].l+1);
		tree[p].taga+=x;
		tree[p].suma=Mod(tree[p].suma);
		tree[p].taga=Mod(tree[p].taga);
		return;
	}
	down(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(ql<=mid)update_A(lc,ql,qr,x);
	if(qr>mid)update_A(rc,ql,qr,x);
	up(p);
}
void update_B(int p,int ql,int qr,int x){
	if(ql<=tree[p].l&&tree[p].r<=qr){
		tree[p].sumb*=x%mod;
		tree[p].tagb*=x%mod;
		tree[p].sumb=Mod(tree[p].sumb);
		tree[p].tagb=Mod(tree[p].tagb);
		return;
	}
	down(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(ql<=mid)update_B(lc,ql,qr,x);
	if(qr>mid)update_B(rc,ql,qr,x);
	up(p);
}
void update_C(int p,int ql,int qr,int x){
	if(ql<=tree[p].l&&tree[p].r<=qr){
		tree[p].sumc=x*(tree[p].r-tree[p].l+1)%mod;
		tree[p].tagc=x;
		tree[p].sumc=Mod(tree[p].sumc);
		tree[p].tagc=Mod(tree[p].tagc);
		return;
	}
	down(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(ql<=mid)update_C(lc,ql,qr,x);
	if(qr>mid)update_C(rc,ql,qr,x);
	up(p);
}
int query_A(int p,int ql,int qr){
	if(ql<=tree[p].l&&tree[p].r<=qr)return tree[p].suma%mod;
	down(p);
	int res=0,mid=(tree[p].l+tree[p].r)>>1;
	if(ql<=mid)res+=query_A(lc,ql,qr),res=Mod(res);
	if(qr>mid)res+=query_A(rc,ql,qr),res=Mod(res);
	return res;
}
int query_B(int p,int ql,int qr){
	if(ql<=tree[p].l&&tree[p].r<=qr)return tree[p].sumb%mod;
	down(p);
	int res=0,mid=(tree[p].l+tree[p].r)>>1;
	if(ql<=mid)res+=query_B(lc,ql,qr),res=Mod(res);
	if(qr>mid)res+=query_B(rc,ql,qr),res=Mod(res);
	return res;
}
int query_C(int p,int ql,int qr){
	if(ql<=tree[p].l&&tree[p].r<=qr)return tree[p].sumc%mod;
	down(p);
	int res=0,mid=(tree[p].l+tree[p].r)>>1;
	if(ql<=mid)res+=query_C(lc,ql,qr),res=Mod(res);
	if(qr>mid)res+=query_C(rc,ql,qr),res=Mod(res);
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	if(n<=1000){
		int q;
		cin >> q;
		for(int i=1;i<=q;i++){
			int op,l,r;
			cin >> op >> l >> r;
			if(op==1){
				for(int j=l;j<=r;j++){
					a[j]+=b[j];
					a[j]%=mod;
				}
			}
			if(op==2){
				for(int j=l;j<=r;j++){
					b[j]+=c[j];
					b[j]%=mod;
				}
			}
			if(op==3){
				for(int j=l;j<=r;j++){
					c[j]+=a[j];
					c[j]%=mod;
				}
			}
			if(op==4){
				int v;cin >> v;
				for(int j=l;j<=r;j++){
					a[j]+=v;
					a[j]%=mod;
				}
			}
			if(op==5){
				int v;cin >> v;
				for(int j=l;j<=r;j++){
					b[j]*=v;
					b[j]%=mod;
				}
			}
			if(op==6){
				int v;cin >> v;
				for(int j=l;j<=r;j++){
					c[j]=v;
					c[j]%=mod;
				}
			}
			if(op==7){
				int ans1=0,ans2=0,ans3=0;
				for(int j=l;j<=r;j++){
					ans1+=a[j],ans2+=b[j],ans3+=c[j];
					ans1%=mod;
					ans2%=mod;
					ans3%=mod;
				}
				cout << ans1 << " " << ans2 << " " << ans3 << '\n';
			}
		}
		return 0;
	}
	build(1,1,n);
	int Q;
	cin >> Q;
	while(Q--){
		int op,l,r;
		cin >> op >> l >> r;
		if(op==1){
			update_Asum(1,l,r);
		}
		if(op==2){
			update_Bsum(1,l,r);
		}
		if(op==3){
			update_Csum(1,l,r);
		}
		if(op==4){
			int x;
			cin >> x;
			update_A(1,l,r,x);
		}
		if(op==5){
			int x;
			cin >> x;
			update_B(1,l,r,x);
		}
		if(op==6){
			int x;
			cin >> x;
			update_C(1,l,r,x);
		}
		if(op==7){
			cout << query_A(1,l,r) << " " << query_B(1,l,r) << " " << query_C(1,l,r) << endl;
		}
	}
	return 0;
} 
/*
4
1 1 1
1 1 1
1 1 1
1 1 1
5
5 1 4 2
2 1 4
4 1 4 1
1 1 4
7 1 4
*/
