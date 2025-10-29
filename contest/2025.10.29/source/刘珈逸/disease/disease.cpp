#include<bits/stdc++.h>
using namespace std;
const int N=305;
typedef vector<int> poly;
poly G[N];
poly son[N];
int siz[N];
void dfs(int x,int f){
    siz[x]=1;
    for(int i:G[x])if(i^f){
        dfs(i,x);
        son[x].push_back(i);
        siz[x]+=siz[i];
    }
}
int n,ans;
void work(poly now,int cnt){
    if(!now.size()){
        ans=min(ans,cnt);
        return;
    }
    if(cnt+now.size()-1>=ans)return;
    for(int i=0;i<now.size();i++){
        poly tmp;
        for(int j=0;j<now.size();j++)if(i^j)for(int k:son[now[j]])tmp.push_back(k);
        work(tmp,cnt+now.size()-1);
    }
}
int main(){
    freopen("disease.in","r",stdin);
    freopen("disease.out","w",stdout);
    scanf("%d%*d",&n);
    for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);
    dfs(1,0);
    ans=n;
    poly vec=son[1];
    work(vec,1);
    printf("%d\n",ans);
    return 0;
}
