#include<bits/stdc++.h>
#define int long long
#define N 10000000
#define M 5000
using namespace std;
int n,f[N+5],w[N+5],s[N+5],to[N+5],head[N+5],ans[N+5],suf[N+5],Ans,maxn,p,a[M+5][M+5],dep[M+5],hs[M+5],top[M+5];
bool type=1,type2=1;
inline int read(){
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
inline void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
inline void dfs(int x){
    s[x]=1;
    for(int i=head[x];i;i=to[i]){
        dfs(i);
        s[x]+=s[i];
    }
    maxn=0;
    for(int i=head[x];i;i=to[i]){
        if(maxn<s[i])p=i,maxn=s[i];
    }
    if(maxn>n-s[x]){
        for(int i=head[x];i;i=to[i]){
            if(s[i]==maxn)ans[i]++;
        }
    }
    else ans[x]++;
    return;
}
inline void build(int x,int d){
    dep[x]=d,s[x]=1;
    for(int i=head[x];i;i=to[i]){
        build(i,d+1);
        s[x]+=s[i];
        if(s[i]>s[hs[x]])hs[x]=i;
    }
    return;
}
inline void build2(int x,int t){
    top[x]=t;
    if(hs[x])build2(hs[x],t);
    for(int i=head[x];i;i=to[i]){
        if(i==hs[x])continue;
        build2(i,i);
    }
    return;
}
inline int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        x=f[top[x]];
    }
    if(dep[x]<dep[y])return x;
    return y;
}
main(){
    freopen("treeq.in","r",stdin);
    freopen("treeq.out","w",stdout);
    n=read();
    for(int i=2;i<=n;i++){
        f[i]=read(),w[i]=read();
        to[i]=head[f[i]],head[f[i]]=i;
        if(w[i]!=1)type=0;
        if(f[i]!=i-1)type2=0;
    }
//     if(type2){
//         for(int i=n;i>1;i--)suf[i]=max(suf[i+1],w[i]);
//         maxn=0;
//         for(int i=2;i<=n;i++){
//             s[i]=max(maxn,suf[i+1]),max=max(maxn,w[i]);
//         }
//         return 0;
//     }
    if(type){
        dfs(1);
        for(int i=2;i<=n;i++)Ans^=ans[i];
        print(Ans);
        return 0;
    }
    // cout<<"Untype\n";
    build(1,1),build2(1,1);
    for(int i=1;i<=n;i++){
        maxn=0;
        for(int j=2;j<=n;j++){
            if(lca(i,j)!=j){
                a[i][j]=s[j]*w[j];
            }
            else{
                a[i][j]=(n-s[j])*w[j];
            }
            maxn=max(maxn,a[i][j]);
        }
        for(int j=2;j<=n;j++){
            if(a[i][j]==maxn){
                ans[j]++;
            }
        }
    }
    for(int i=2;i<=n;i++)Ans^=ans[i]/*,cout<<"ans["<<i<<"]="<<ans[i]<<"\n"*/;
    print(Ans);
    return 0;
}
