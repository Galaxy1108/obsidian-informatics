#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a) 
#define DOW(a,b,c) for(int a = b;a >= c;--a) 
#define ll long long 

const int MAXN = 12;
const int MOD = 0;

int m,n;

int tr[1<<MAXN];

int ls(int x){ return x*2; }
int rs(int x){ return x*2+1; }

void _build(int p,int dep){
	tr[p] = 1;
	if(dep >= m) return;
	_build(ls(p),dep+1);
	_build(rs(p),dep+1);
}

int tmp[2][1<<10];

struct Node{
	int id,p;
};

const char Cspace = char(32);

void mpr(int k){
	int i = 1;
	while(tmp[k][i] != 5){
		if(tmp[k][i] == 0) pr("%c",Cspace);
		else if(tmp[k][i] == 1) pr("/");
		else if(tmp[k][i] == 2) pr("\\");
		else if(tmp[k][i] == 3) pr("o");
		tmp[k][i] = 0;
		++i;
	}
	tmp[k][i] = 0;
	pr("\n"); 
}

int fo[MAXN];

int main(){
	
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	
	sc("%d%d",&m,&n);
	int rowcnt = 3<<(m-3);
	if(m == 2) rowcnt = 1;
	fo[1] = 1;
	REP(i,2,m){
		if(rowcnt == 1){
			fo[i] = fo[i-1]+2;
			break;
		}
		fo[i] = fo[i-1]+rowcnt;
		rowcnt /= 2;
	}
//	REP(i,1,m) pr("%d ",fo[i]);
	
	_build(1,0);
	
	REP(i,1,n){
		int rx,ly;
		sc("%d%d",&rx,&ly);
		if(ly == 0) continue;
		tr[((1<<(rx-1))+ly-1)/2] = 2;
		tr[(1<<(rx-1))+ly-1] = 0;
	}
	
	if(tr[1] == 0) return 0;
	tmp[0][3<<(m-2)] = 3;
	tmp[0][3<<(m-2)+5] = 5;
//	mpr(ko);
	int c = 0;
	queue<Node> q;
	q.push({3<<(m-2),1});
	rowcnt = 2;
	while(true){
		int ko = c%2,kn = (ko+1)%2;
		if(rowcnt == m+1) break;
		Node p;
		REP(kcnt,1,q.size()){
			p = q.front();
			q.pop();
			if(tmp[ko][p.id] == 3){
				if(tr[p.p] == 1){
					tmp[kn][p.id-1] = 2;
					tmp[kn][p.id+1] = 3;
					q.push({p.id-1,p.p});
					q.push({p.id+1,p.p});
				}
				if(tr[p.p] == 2){
					if(tr[ls(p.p)] != 0){
						tmp[kn][p.id-1] = 1;
						q.push({p.id-1,p.p});
					}
					if(tr[rs(p.p)] != 0){
						tmp[kn][p.id+1] = 2;
						q.push({p.id+1,p.p});
					}
				}				
			}
			if(tmp[ko][p.id] == 1){
				if(c == fo[rowcnt]){
					rowcnt++;
					tmp[kn][p.id-1] = 3;
					q.push({p.id-1,ls(p.p)});
				}else{
					tmp[kn][p.id-1] = 1;
					q.push({p.id-1,p.p});
				}
			}
			if(tmp[ko][p.id] == 2){
				if(c == fo[rowcnt]){
					rowcnt++;
					tmp[kn][p.id+1] = 3;
					q.push({p.id+1,rs(p.p)});
				}else{
					tmp[kn][p.id+1] = 2;
					q.push({p.id+1,p.p});
				}
			}
		}
		tmp[kn][p.id+5] = 5;
		mpr(ko);
		++c;
	}
	
	return 0;
}
