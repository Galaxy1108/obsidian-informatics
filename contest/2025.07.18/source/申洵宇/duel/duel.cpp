#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define LGN 25 
struct node{
	int op,x,y;
}qs[N];
int n,q,p[N];
namespace sub1{
	int tp[N];
	void solve(){
		for(int qn=1;qn<=q;qn++){
			if(qs[qn].op==1){
				p[qs[qn].x]=qs[qn].y;
			}
			else if(qs[qn].op==2){
				
				for(int i=qs[qn].x;i<=qs[qn].x+(1<<qs[qn].y)-1;i++){
					tp[i]=p[i];
				}
				for(int i=1;i<=qs[qn].y;i++){
					for(int j=qs[qn].x;j<=qs[qn].x+(1<<qs[qn].y)-1;j+=(1<<i)){
						tp[j]=abs(tp[j]-tp[j+(1<<(i-1))]);
					}
				}
				cout<<tp[qs[qn].x]<<'\n';
//				printf("%d\n",tp[qs[qn].x]);
			}
		}
	}
}
namespace sub2{
	class BIT{
	#define lowbit(x) ((x)&(-(x)))
	public:
		int val[N];
		BIT(){
			memset(val,0,sizeof(val));
		}
		void build(){
			for(int i=1;i<=n;i++){
				val[i]^=p[i];
				if(i+lowbit(i)<=n)val[i+lowbit(i)]^=val[i];
			}
		}
		void cxor(int x){
			for(int i=x;i<=n;i+=lowbit(i)){
				val[i]^=1;
			}
		}
		int qxor(int x){
			int res=0;
			for(int i=x;i>=1;i-=lowbit(i)){
				res^=val[i];
			}
			return res;
		}
	#undef lowbit
	}bit;
	void solve(){
		bit.build();
		for(int qn=1;qn<=q;qn++){
			if(qs[qn].op==1){
				if((bit.qxor(qs[qn].x)^(qs[qn].x>1?bit.qxor(qs[qn].x-1):0))!=qs[qn].y)bit.cxor(qs[qn].x);
			}
			else if(qs[qn].op==2){
				cout<<(bit.qxor(qs[qn].x+(1<<qs[qn].y)-1)^(qs[qn].x>1?bit.qxor(qs[qn].x-1):0))<<'\n';
//				printf("%d\n",bit.qxor(qs[qn].x+(1<<qs[qn].y)-1)^(qs[qn].x>1?bit.qxor(qs[qn].x-1):0));
			}
		}
	}
}
namespace sub3{
	int st[LGN][N],lg2[N];
	void solve(){
		lg2[1]=1;
		for(int i=2;i<=n;i++){
			lg2[i]=lg2[i>>1]+1;
		}
		for(int i=1;i<=n;i++){
			st[0][i]=p[i];
		}
		for(int i=1;i<=lg2[n];i++){
			for(int j=1;j+(1<<(i-1))<=n;j++){
				st[i][j]=abs(st[i-1][j]-st[i-1][j+(1<<(i-1))]);
			}
		}
		for(int i=1;i<=q;i++){
			cout<<st[qs[i].y][qs[i].x]<<'\n';
//			printf("%d\n",st[qs[i].y][qs[i].x]);
		}
	}
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
//	scanf("%d%d",&n,&q);
	bool subtask2=true,subtask3=true;
	for(int i=1;i<=n;i++){
		cin>>p[i];
//		scanf("%d",&p[i]);
		if(p[i]>1)subtask2=false;
	}
	for(int i=1;i<=q;i++){
		cin>>qs[i].op>>qs[i].x>>qs[i].y;
//		scanf("%d%d%d",&qs[i].op,&qs[i].x,&qs[i].y);
		if(qs[i].op==1)subtask3=false;
		if(qs[i].op==1&&qs[i].y>1)subtask2=false;
	}
	if(subtask2){
		sub2::solve();
	}
	else if(subtask3){
		sub3::solve();
	}
	else/*if(n<=1000&&q<=1000)*/{
		sub1::solve();
	} 
	return 0;
}

