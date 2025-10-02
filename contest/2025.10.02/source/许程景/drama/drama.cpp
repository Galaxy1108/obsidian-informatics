#include <cstdio>
#include <stack>
#include <algorithm>
struct nd{
    int l,r;
    int lch,rch;
}nds[2000010];
long long all[2000010];
int n;
long long STmx[2000010][22];
void build_tree(){
    std::stack<int> st;
    st.push(0);
    for(int i=1;i<=n;i++){
	nds[i].lch=nds[i].rch=-1;
	int defeat=-1;
	while(all[i]<all[st.top()]) defeat=st.top(),st.pop();
	nds[st.top()].rch=i;
        nds[i].lch=defeat;
	st.push(i);
    }
}
void givval(int cnd,int l,int r){
    //printf("dot:%d\n",cnd);
    nds[cnd].l=l,nds[cnd].r=r;
    if(~nds[cnd].lch) givval(nds[cnd].lch,l,cnd);
    if(~nds[cnd].rch) givval(nds[cnd].rch,cnd+1,r);
}
__int128 getmx(int i,int j){
    int k=std::__lg(j-i);
    return std::max(STmx[i][k],STmx[j-(1<<k)][k]);
}
void prt(__int128 x){
    if(x>=10) prt(x/10);
    printf("%c",x%10+'0');
}
int main(){
    freopen("drama.in","r",stdin);
    freopen("drama.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",all+i);
    for(int i=1;i<=n;i++) STmx[i][0]=all[i];
    for(int k=1;(1<<k)<=n;k++){
	for(int i=1;i+(1<<k)<=n+1;i++){
	    STmx[i][k]=std::max(STmx[i][k-1],STmx[i+(1<<(k-1))][k-1]);
	}
    }
    build_tree();
    givval(nds[0].rch,1,n+1);
    __int128 ans=0ull;
    for(int i=1;i<=n;i++){
	//printf("[%d,%d),<%d>,-%d,%d-\n",nds[i].l,nds[i].r,all[i],root,all[root]);
	ans=std::max(ans,getmx(nds[i].l,nds[i].r)*all[i]*(nds[i].r-nds[i].l));
    }
    prt(ans);
}
