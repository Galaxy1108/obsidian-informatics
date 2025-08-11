#include<bits/stdc++.h>
using namespace std;
#define lb(x) (x&(-x))
const int N=1e6+5,inf=1e9;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int n,l,r,a[N],ans=inf,t[N];
bool vis[N];
vector<int> nums[N];

void add(int x,int v){
    while(x<=n){
        t[x]+=v;
        x+=lb(x);
    }
}

int sum(int x){
    int ans=0;
    while(x){
        ans+=t[x];
        x-=lb(x);
    }
    return ans;
}

int sum(int l,int r){
    return sum(r)-sum(l-1);
}

signed main(){
    freopen("gene.in","r",stdin);
    freopen("gene.out","w",stdout);
    n=read();l=read();r=read();
    for(int i=1;i<=n;++i){
        a[i]=read();nums[a[i]].push_back(i);
    }
    for(int i=1;i<l;++i){
        if(nums[a[i]].size()>1&&nums[a[i]][1]<=r)vis[i]=0;
        else vis[i]=1;
        add(i,vis[i]);
    }
    for(int i=r+1;i<=n;++i){
        if(i==nums[a[i]][nums[a[i]].size()-1]){
            int last=nums[a[i]].size()>1?nums[a[i]][nums[a[i]].size()-2]+1:1;
            if(sum(last,l-1)){
                for(int j=l-1;j>=last;--j){
                    if(vis[j]){
                        print(i-j+1);putchar('\n');return 0;
                    }
                }
            }
        }
        if(nums[a[i]][0]<l&&vis[nums[a[i]][0]]){
            vis[nums[a[i]][0]]=0;
            add(nums[a[i]][0],-1);
        }
    }
    puts("-1");
    return 0;
}