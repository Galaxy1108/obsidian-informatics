#include<bits/stdc++.h>
#include"testlib.h"
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
//void ensure(bool o){
//	if (!o) quitf(_wa,"Wrong Answer"),exit(0);
//}
/*
perfectScore
inf. ouf.
quitf(_wa,"Wrong Answer")
quitf(_ok,"Correct") 
quitp(perfectScore*0.5,"Partial Correct")���� 
*/
const int M=1e5+10;
int n,p[M],q[M],h[M],vis[M],d[M];
bool judge(){
	F(i,1,n) vis[i]=0;
	F(i,1,n){
		int x=p[i],len=0;
		if (!vis[x]){
			for (;!vis[x];vis[x]=1,x=p[x]) len++;
			d[len]++;	
		}
	}
	F(i,1,n) vis[i]=0;
	F(i,1,n){
		int x=q[i],len=0;
		if (!vis[x]){
			for (;!vis[x];vis[x]=1,x=q[x]) len++;
			d[len]--;
			if (d[len]<0) return 0;
		}
	}
	return 1;
}
void check(int *p,int *q,int *h){
	static int hh[M],res[M];
	F(i,1,n) ensure(p[i]>=1 && p[i]<=n && h[i]>=1 && h[i]<=n && q[i]>=1 && q[i]<=n);
	F(i,1,n) hh[h[i]]=i;
	F(i,1,n) ensure(hh[i]>=1 && hh[i]<=n);
	F(i,1,n) res[i]=hh[p[h[i]]];
	F(i,1,n) ensure(res[i]==q[i]);
}
int main(int argc, char** argv) {
	registerLemonChecker(argc, argv);
	n = inf.readInt();
	int C = 0;
	F(i,1,n) p[i]=inf.readInt();
	F(i,1,n) q[i]=inf.readInt();
	bool ok=judge();
	string tmp=ouf.readString();
	bool aok=tmp[0]=='Y';
	if (aok^ok){
		quitf(_wa,"Wrong Answer");
		return 0;
	}
	if (!ok){
		quitf(_ok,"Correct");
		return 0;
	}
	F(i,1,n) h[i]=ouf.readInt();
	check(p,q,h);
	quitf(_ok,"Correct");
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

