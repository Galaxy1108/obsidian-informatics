#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<bitset>
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=1e6+5;
struct node{
	int ls,rs,val,sz,p;
}q[N];
int idx;
int New(int x){
	idx++;
	q[idx]={0,0,x,1,rand()};
	return x;
}
void pu(int id){
	q[id].sz=q[q[id].ls].sz+q[q[id].rs].sz+1;
}
int merge(int x,int y){
	if(!x||!y) return x+y;
	if(q[x].p<q[y].p){
		q[x].rs=merge(q[x].rs,y);
		pu(x);
		return x;
	}
	else{
		q[y].ls=merge(x,q[y].ls);
		pu(y);
		return y;
	}
}
void split(int id,int k,int &x,int &y){
	if(!id){
		x=y=0;
		return;
	}
	if(q[id].val<=k){
		x=id;
		split(q[id].rs,k,q[id].rs,y);
	}
	else{
		y=id;
		split(q[id].ls,k,x,q[id].ls);
	}
	pu(id);
}
int kth(int id,int k){
	if(q[q[id].ls].sz+1==k) return q[id].val;
	else if(q[q[id].ls].sz>=k) return kth(q[id].ls,k);
	else return kth(q[id].rs,k-1-q[q[id].ls].sz);
}
int f[21][N];
int n,Q,rt;
bitset<N> vis;
void delet(int val){
	int x,y,z;
	split(rt,val,x,z);
	split(x,val-1,x,y);
	y=merge(q[y].ls,q[y].rs);
	rt=merge(merge(x,y),z);
}
bool fck[25];
void solve1(int x){
	if(fck[x]) return;
	fck[x]=1;
	for(int i=1;i<=n;i+=x){
		if(!vis[i]){
			delet(i);
			vis[i]=1;
		}
	}
}
void delet1(int x){
	int val=kth(rt,x);
	delet(val);
	vis[val]=1;
}
void solve2(int x){
	int cnt=0;int al=q[rt].sz;
	for(int i=1;i<=al;i+=x){
		delet1(i-cnt);
		cnt++;
	}
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	srand(114514);
	n=read(),Q=read();
	for(int i=2;i<=20;i++){
		f[i][1]=1;
		for(int j=2;j<=n;j++){
			f[i][j]=j-(f[i][j-(j+i-1)/i]+(f[i][j-(j+i-1)/i]>j%i-1)*((f[i][j-(j+i-1)/i]-max(j%i-1,0)-1)/(i-1)+(bool)(j%i)))+1;
		}
	}
	for(int i=1;i<=n;i++) rt=merge(rt,New(i)); 
	while(Q--){
		int opt=read(),x=read();
		if(opt==1){
			solve1(x);
		}
		else if(opt==2){
			solve2(x);
		}
		else{
			write(kth(rt,f[x][q[rt].sz]));
			putchar('\n');
		}
	}
	return 0;
}
