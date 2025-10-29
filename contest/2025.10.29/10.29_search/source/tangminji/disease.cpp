#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define IL inline
#define N 310
#define REP(a,b,c) for(a=b;a<=c;a++)
using namespace std;
//贪心有误
//注意：不能按子树大小贪心，只能按与患者树接触的人群贪心，但又可能贪得太晚了
int n,head[N],list[N<<1],next[N<<1],fa[N],son[N],siz[N],ap=1;
int huan[2][N],*A=huan[0],*B=huan[1],*T;
//为提高正确率，按子结点数为第一关键字，子树大小为第二关键字排序
IL bool cmp(const int &a,const int &b){
	return son[a]<son[b] || (son[a]==son[b] && siz[a]<siz[b]);
}
IL bool cmp2(const int &a,const int &b){
	return siz[a]<siz[b] || (siz[a]==siz[b] && son[a]<son[b]);
}
//做两次取min算了……
IL int rd(){
	int res=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();
	return res;
}
IL void link(int a,int b){
	list[++ap]=b,next[ap]=head[a],head[a]=ap;
	list[++ap]=a,next[ap]=head[b],head[b]=ap;
}
IL void dfs(int u){
	int x;siz[u]=1;
	for(x=head[u];x;x=next[x])
		if(list[x]!=fa[u]){
			son[u]++;fa[list[x]]=u;
			dfs(list[x]);
			siz[u]+=siz[list[x]];
		}
}
int main(){
	freopen("disease.in","r",stdin),freopen("disease.out","w",stdout);
	n=rd();int p=rd(),ans=0,ans2=0,i,u,x,tot;
	while(p--)link(rd(),rd());
	dfs(1);A[0]=A[1]=1;
	while(A[0]){
		ans+=A[0];tot=0;
		REP(i,1,A[0]){
			for(x=head[u=A[i]];x;x=next[x])
				if(list[x]!=fa[u])
					B[++tot]=list[x];
		}
		B[0]=tot;
		if(tot){
			sort(B+1,B+1+tot,cmp);
			B[0]--;
		}
		T=A,A=B,B=T;
	}
	A[0]=A[1]=1;
	while(A[0]){
		ans2+=A[0];tot=0;
		REP(i,1,A[0]){
			for(x=head[u=A[i]];x;x=next[x])
				if(list[x]!=fa[u])
					B[++tot]=list[x];
		}
		B[0]=tot;
		if(tot){
			sort(B+1,B+1+tot,cmp2);
			B[0]--;
		}
		T=A,A=B,B=T;
	}
	ans=min(ans,ans2);
	printf("%d",ans);
	return 0;
}
