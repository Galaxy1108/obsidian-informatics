#include<bits/stdc++.h>
#define int long long
#define N 100000
using namespace std;
struct Node{int l,r,a,b,l1,l2,r1,r2,o,z,lv,lw,rv,rw,ra,rb,rc,la,lb,lc;};
struct UNode{int id,t,v;};
int n,m,a[N+5],opt,ux,uy;
Node tree[N*4+5]; 
bool debug=0;
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
bool cmp(UNode x,UNode y){
	return x.v<y.v;
}
Node pushup2(Node x,Node y){
	int l=x.l,r=y.r,mid=x.r;
	Node u;
	UNode ua[10];
	int len=0;
	u.o=x.o+y.o;
	u.z=x.z+y.z;
	u.l=x.l,u.r=y.r;
	u.rv=y.rv;
	if(y.o%2==0)u.rv+=x.rv;
	else u.rv+=x.rw;
	u.rw=y.rw;
	if(y.o%2==0)u.rw+=x.rw;
	else u.rw+=x.rv;
	u.lv=x.lv;
	if(x.o%2==0)u.lv+=y.lv;
	else u.lv+=y.lw;
	u.lw=x.lw;
	if(x.o%2==0)u.lw+=y.lw;
	else u.lw+=y.lv;
	if(y.r1&&y.r2)u.r1=y.r1,u.r2=y.r2;
	else if(y.r1)u.r1=y.r1,u.r2=x.r1;
	else u.r1=x.r1,u.r2=x.r2;
	if(x.l1&&x.l2)u.l1=x.l1,u.l2=x.l2;
	else if(x.l1)u.l1=x.l1,u.l2=y.l1;
	else u.l1=y.l1,u.l2=y.l2;
	if(y.ra&&y.rb&&y.rc)u.ra=y.ra,u.rb=y.rb,u.rc=y.rc;
	else if(y.ra&&y.rb)u.ra=y.ra,u.rb=y.rb,u.rc=x.ra;
	else if(y.ra)u.ra=y.ra,u.rb=x.ra,u.rc=x.rb;
	else u.ra=x.ra,u.rb=x.rb,u.rc=x.rc;
	if(x.la&&x.lb&&x.lc)u.la=x.la,u.lb=x.lb,u.lc=x.lc;
	else if(x.la&&x.lb)u.la=x.la,u.lb=x.lb,u.lc=y.la;
	else if(x.la)u.la=x.la,u.lb=y.la,u.lc=y.lb;
	else u.la=y.la,u.lb=y.lb,u.lc=y.lc;
	return u;
}
Node query(int s,int t,int l,int r,int p){
	if(s<=l&&r<=t)return tree[p];
	int mid=(l+r)>>1;
	if(s<=mid&&mid<t)return pushup2(query(s,t,l,mid,p*2),query(s,t,mid+1,r,p*2+1));
	if(s<=mid)return query(s,t,l,mid,p*2);
	return query(s,t,mid+1,r,p*2+1);
}
Node pushup(Node x,Node y){
	int l=x.l,r=y.r,mid=x.r;
	Node u;
	UNode ua[10];
	int len=0;
	u.o=x.o+y.o;
	u.z=x.z+y.z;
	u.l=x.l,u.r=y.r;
	u.rv=y.rv;
	if(y.o%2==0)u.rv+=x.rv;
	else u.rv+=x.rw;
	u.rw=y.rw;
	if(y.o%2==0)u.rw+=x.rw;
	else u.rw+=x.rv;
	u.lv=x.lv;
	if(x.o%2==0)u.lv+=y.lv;
	else u.lv+=y.lw;
	u.lw=x.lw;
	if(x.o%2==0)u.lw+=y.lw;
	else u.lw+=y.lv;
	if(y.r1&&y.r2)u.r1=y.r1,u.r2=y.r2;
	else if(y.r1)u.r1=y.r1,u.r2=x.r1;
	else u.r1=x.r1,u.r2=x.r2;
	if(x.l1&&x.l2)u.l1=x.l1,u.l2=x.l2;
	else if(x.l1)u.l1=x.l1,u.l2=y.l1;
	else u.l1=y.l1,u.l2=y.l2;
	if(y.ra&&y.rb&&y.rc)u.ra=y.ra,u.rb=y.rb,u.rc=y.rc;
	else if(y.ra&&y.rb)u.ra=y.ra,u.rb=y.rb,u.rc=x.ra;
	else if(y.ra)u.ra=y.ra,u.rb=x.ra,u.rc=x.rb;
	else u.ra=x.ra,u.rb=x.rb,u.rc=x.rc;
	if(x.la&&x.lb&&x.lc)u.la=x.la,u.lb=x.lb,u.lc=x.lc;
	else if(x.la&&x.lb)u.la=x.la,u.lb=x.lb,u.lc=y.la;
	else if(x.la)u.la=x.la,u.lb=y.la,u.lc=y.lb;
	else u.la=y.la,u.lb=y.lb,u.lc=y.lc;
//	if(debug){
//		cout<<"debug:"<<u.la<<" "<<u.lb<<" "<<u.lc<<" "<<u.ra<<" "<<u.rb<<" "<<u.rc<<" "<<u.l1<<" "<<u.l2<<" "<<u.r1<<" "<<u.r2<<"\n";
//		exit(0);
//	}
	u.a=x.a+y.a+x.rv*y.lv+x.rw*y.lw;
	u.b=x.b+y.b;
	ua[++len]={0,0,l};
	ua[++len]={1,1,x.ra+1};
	ua[++len]={2,1,x.rb+1};
	ua[++len]={3,1,x.rc+1};
	ua[++len]={1,2,x.r1+1};
	ua[++len]={2,2,x.r2+1};
	ua[++len]={0,0,mid+1};
	sort(ua+1,ua+1+len,cmp);
	for(int i=1,j=0,k=0;i<len;i++){
		if(ua[i].t==1){
			if(!j)j=ua[i].id;
			else j=min(j,ua[i].id);
		}
		if(ua[i].t==2){
			if(!k)k=ua[i].id;
			else k=min(k,ua[i].id);
		}
		if(debug){
			cout<<"debug:i="<<i<<" "<<ua[i].v<<" "<<ua[i+1].v<<" "<<j<<" "<<k<<"\n";
		}
		if(ua[i].v>=l&&ua[i].v<ua[i+1].v){
			Node uu=query(ua[i].v,ua[i+1].v-1,1,n,1),vv;
			int kk=0;
			if(j==0&&k==0)vv=y;
			else if(j==0&&k==2){
				if(y.l1==0)continue;
				vv=query(y.l1,r,1,n,1);
				if(y.l1>mid+1)kk=query(mid+1,y.l1-1,1,n,1).o;
			}
			else if(j==0&&k==1){
				if(y.l2==0)continue;
				vv=query(y.l2,r,1,n,1);
				if(y.l2>mid+1)kk=query(mid+1,y.l2-1,1,n,1).o;
			}
			else if(j==3&&k==0){
				if(y.la==0)continue;
				vv=query(y.la,r,1,n,1);
				if(y.la>mid+1)kk=query(mid+1,y.la-1,1,n,1).o;
			}
			else if(j==3&&k==2){
				if(y.la==0)continue;
				if(y.l1==0)continue;
				if(debug){
					cout<<uu.rv<<" "<<query(max(y.l1,y.la),r,1,n,1).lw;
					exit(0);
				}
				vv=query(max(y.l1,y.la),r,1,n,1);
				if(max(y.l1,y.la)>mid+1)kk=query(mid+1,max(y.l1,y.la)-1,1,n,1).o;
			}
			else if(j==3&&k==1){
				if(y.la==0)continue;
				if(y.l2==0)continue;
				vv=query(max(y.l2,y.la),r,1,n,1);
				if(max(y.l2,y.la)>mid+1)kk=query(mid+1,max(y.l2,y.la)-1,1,n,1).o;
			}
			else if(j==2&&k==0){
				if(y.lb==0)continue;
				vv=query(y.lb,r,1,n,1);
				if(y.lb>mid+1)kk=query(mid+1,y.lb-1,1,n,1).o;
			}
			else if(j==2&&k==2){
				if(y.lb==0)continue;
				if(y.l1==0)continue;
				vv=query(max(y.l1,y.lb),r,1,n,1);
				if(max(y.l1,y.lb)>mid+1)kk=query(mid+1,max(y.l1,y.lb)-1,1,n,1).o;
			}
			else if(j==2&&k==1){
				if(y.lb==0)continue;
				if(y.l2==0)continue;
				vv=query(max(y.l2,y.lb),r,1,n,1);
				if(max(y.l2,y.lb)>mid+1)kk=query(mid+1,max(y.l2,y.lb)-1,1,n,1).o;
			}
			else if(j==1&&k==0){
				if(y.lc==0)continue;
				vv=query(y.lc,r,1,n,1);
				if(y.lc>mid+1)kk=query(mid+1,y.lc-1,1,n,1).o;
			}
			else if(j==1&&k==2){
				if(y.lc==0)continue;
				if(y.l1==0)continue;
				vv=query(max(y.l1,y.lc),r,1,n,1);
				if(max(y.l1,y.lc)>mid+1)kk=query(mid+1,max(y.l1,y.lc)-1,1,n,1).o;
			}
			else if(j==1&&k==1){
				if(y.lc==0)continue;
				if(y.l2==0)continue;
				vv=query(max(y.l2,y.lc),r,1,n,1);
				if(max(y.l1,y.lc)>mid+1)kk=query(mid+1,max(y.l1,y.lc)-1,1,n,1).o;
			}
			if(kk%2==0)u.b+=uu.rw*vv.lv+uu.rv*vv.lw;
			else u.b+=uu.rw*vv.lw+uu.rv*vv.lv;
		}
	}
	return u;
}
Node query2(int s,int t,int l,int r,int p){
	if(s<=l&&r<=t)return tree[p];
	int mid=(l+r)>>1;
	if(s<=mid&&mid<t)return pushup(query2(s,t,l,mid,p*2),query2(s,t,mid+1,r,p*2+1));
	if(s<=mid)return query2(s,t,l,mid,p*2);
	return query2(s,t,mid+1,r,p*2+1);
}
void modify(int l,int r,int x,int p){
	if(l==r){
		if(tree[p].o){
			tree[p].a=tree[p].z=1,tree[p].b=tree[p].o=0;
			tree[p].ra=tree[p].rb=tree[p].rc=tree[p].la=tree[p].lb=tree[p].lc=0;
			tree[p].r1=tree[p].l1=l,tree[p].r2=tree[p].l2=0;
			tree[p].lw=tree[p].rw=0;
			tree[p].lv=tree[p].rv=1;
		}
		else{
			tree[p].b=tree[p].z=tree[p].a=0,tree[p].o=1;
			tree[p].ra=tree[p].rb=tree[p].rc=tree[p].la=tree[p].lb=tree[p].lc=0;
			tree[p].ra=tree[p].la=l;
			tree[p].r1=tree[p].l1=tree[p].r2=tree[p].l2=0;
			tree[p].lw=tree[p].rw=1;
			tree[p].lv=tree[p].rv=0;
		}
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)modify(l,mid,x,p*2);
	if(mid<x)modify(mid+1,r,x,p*2+1);
	tree[p]=pushup(tree[p*2],tree[p*2+1]);
	return;
}
void build(int l,int r,int p){
	if(l==r){
		tree[p].l=tree[p].r=l;
		if(!a[l]){
			tree[p].a=tree[p].z=1,tree[p].b=tree[p].o=0;
			tree[p].ra=tree[p].rb=tree[p].rc=tree[p].la=tree[p].lb=tree[p].lc=0;
			tree[p].r1=tree[p].l1=l,tree[p].r2=tree[p].l2=0;
			tree[p].lw=tree[p].rw=0;
			tree[p].lv=tree[p].rv=1;
		}
		else{
			tree[p].b=tree[p].z=tree[p].a=0,tree[p].o=1;
			tree[p].ra=tree[p].rb=tree[p].rc=tree[p].la=tree[p].lb=tree[p].lc=0;
			tree[p].ra=tree[p].la=l;
			tree[p].r1=tree[p].l1=tree[p].r2=tree[p].l2=0;
			tree[p].lw=tree[p].rw=1;
			tree[p].lv=tree[p].rv=0;
		}
//		cout<<"tree["<<p<<"]:"<<tree[p].l<<" "<<tree[p].r<<" "<<tree[p].o<<" "<<tree[p].z<<" "<<tree[p].a<<" "<<tree[p].b<<"\n";
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,p*2),build(mid+1,r,p*2+1);
	tree[p]=pushup(tree[p*2],tree[p*2+1]);
//	cout<<"tree["<<p<<"]:"<<tree[p].l<<" "<<tree[p].r<<" "<<tree[p].o<<" "<<tree[p].z<<" "<<tree[p].a<<" "<<tree[p].b<<"\n";
	return;
}
void printtree(int l,int r,int p){
	if(l==r){
		cout<<"tree["<<p<<"]:"<<tree[p].l<<" "<<tree[p].r<<" "<<tree[p].o<<" "<<tree[p].z<<" "<<tree[p].a<<" "<<tree[p].b<<" "<<tree[p].lv<<" "<<tree[p].lw<<" "<<tree[p].rv<<" "<<tree[p].rw<<"\n";
		return;
	}
	int mid=(l+r)>>1;
	printtree(l,mid,p*2);
	printtree(mid+1,r,p*2+1);
//	cout<<"tree["<<p<<"]:"<<tree[p].l<<" "<<tree[p].r<<" "<<tree[p].o<<" "<<tree[p].z<<" "<<tree[p].a<<" "<<tree[p].b<<" "<<tree[p].lv<<" "<<tree[p].lw<<" "<<tree[p].rv<<" "<<tree[p].rw<<"\n";
	return;
}
main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,n,1);
//	debug=1;
//	pushup(tree[2],tree[3]);
//	return 0;
	debug=0;
	m=read();
	while(m--){
		opt=read();
		if(opt==1){
			ux=read();
			modify(1,n,ux,1);
		}
		else{
			ux=read(),uy=read();
			Node u=query2(ux,uy,1,n,1);
			print(u.a+u.b);
			putchar('\n');
		}
//		cout<<"printtree:\n";
//		printtree(1,n,1);
	}
	return 0;
}
