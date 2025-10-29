#include<bits/stdc++.h>
using namespace std;
int n,f[305],sz[305],ans=INT_MAX,q[10005],st,ta,N;
vector<int> e[305];
void dfs(int x){
    sz[x]=1;
    for(auto i:e[x])if(i!=f[x]){f[i]=x;dfs(i);sz[x]+=sz[i];}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("disease.in","r",stdin);
    freopen("disease.out","w",stdout);
    cin>>n>>N;
    for(int i=1;i<n;i++){int x,y;cin>>x>>y;e[x].push_back(y);e[y].push_back(x);}
    srand(time(NULL));
    dfs(1);
    for(int i=1;i<=10000;i++){
        st=ta=0;
        int cnt=n;
        for(auto j:e[1])q[ta++]=j;
        while(true){
            if(ta==st+1){cnt-=sz[q[st]];break;}
            if(ta<=st) break;
            int maxx=0,maxn=0;
            for(int j=st;j<ta;j++){if(sz[q[j]]>=maxx){maxn=maxx;maxx=sz[q[j]];}else if(sz[q[j]]>=maxn)maxn=sz[q[j]];}
            int kkk=rand();
            int tai=ta;
            bool flag=true;
            for(int j=st;j<tai;j++){
                if(kkk%250&&sz[q[j]]==maxx&&flag){cnt-=maxx;flag=false;continue;}
                if(kkk%250==0&&sz[q[j]]==maxn&&flag){cnt-=maxn;flag=false;continue;}
                for(auto o:e[q[j]]) if(o!=f[q[j]])q[ta++]=o;
            }
            st=tai;
        }
        ans=min(ans,cnt);
    }
    cout<<ans;
    return 0;
}