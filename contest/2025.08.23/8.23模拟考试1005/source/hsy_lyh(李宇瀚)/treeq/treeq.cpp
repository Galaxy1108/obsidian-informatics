#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=2e6+5;

int head[N],pre[N],ver[N],val[N],cnt=0;
int id[N],coun[N];
int siz[N];
int n;
ll maxn=0;
vector<int> ve;

void add_edge(int u,int v,int k,int x){   
    pre[++cnt]=head[u];
    head[u]=cnt;
    ver[cnt]=v;
    val[cnt]=k;
    id[cnt]=x;
    return;
}

void dfs(int nown,int fa){
    siz[nown]=1;
    for(int i=head[nown];i;i=pre[i]){
        int v=ver[i];
        if(v==fa) continue;
        dfs(v,nown);
        siz[nown]+=siz[v];
        if(siz[v]*1ll*val[i]>maxn){
            maxn=siz[v]*1ll*val[i];
            ve.clear();
            ve.push_back(id[i]);
        }
        else if(siz[v]*1ll*val[i]==maxn) ve.push_back(id[i]);
    }
    return;
}

void dfs2(int nown,int f){

    return;
}

int main(){
    freopen("treeq.in","r",stdin);
    freopen("treeq.out","w",stdout);
    cin>>n;
    bool flag=1;
    for(int i=2;i<=n;i++){
        int v,k;
        cin>>v>>k;
        add_edge(i,v,k,i-1);
        add_edge(v,i,k,i-1);
        if(k!=1) flag=0;
    }
    if(n<=5000){
        for(int i=1;i<=n;i++){
            ve.clear();
            maxn=0;
            dfs(i,0);
            for(int j=0;j<ve.size();j++){
                int t=ve[j];
                coun[t]++;
            }
        }
        int ans=0;
        for(int i=1;i<=n-1;i++) ans^=coun[i];
        cout<<ans<<endl;
    }
    else if(flag){

    }
    else{
        //Why is the problem so hard?
        //This is XJOI.
    }
    return 0;
}