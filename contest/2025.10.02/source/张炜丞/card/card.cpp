#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

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

int n,m,q,s[2],ans=0,pre[N];
bool a[N];

struct node{
    int p,len;
    bool operator<(const node &n1)const{
        return len==n1.len?p<n1.p:len<n1.len;
    }
};

set<int> b;
set<node> c[2],uc[2];

bool add(node x,bool f){
    // cout<<" /add x:"<<x.p<<" len:"<<x.len<<" f:"<<f<<" s:"<<s[f]<<endl;
    if(x.len>s[f])return 0;
    ans-=2;
    s[f]-=x.len;
    return 1;
}

void erase(int x){
    if(!pre[x])return;
    if(a[x]!=a[pre[x]]){
        --ans;return;
    }
    if(c[a[x]].find({x,x-pre[x]-1})!=c[a[x]].end()){
        s[a[x]]+=x-pre[x]-1;
        c[a[x]].erase({x,x-pre[x]-1});
    }
    else{
        ans-=2;
        uc[a[x]].erase({x,x-pre[x]-1});
    }
}

void add(int x){
    if(!pre[x])return;
    if(a[x]!=a[pre[x]]){
        ++ans;return;
    }
    node ax={x,x-pre[x]-1};
    if(!c[a[x]].empty()&&ax<(*prev(c[a[x]].end()))){
        s[a[x]]-=x-pre[x]-1;
        c[a[x]].insert({x,x-pre[x]-1});
    }
    else{
        ans+=2;
        uc[a[x]].insert({x,x-pre[x]-1});
    }
}

void maintain(){
    for(int i=0;i<=1;++i){
        while(s[i]<0){
            s[i]+=(*prev(c[i].end())).len;
            ans+=2;
            uc[i].insert(*prev(c[i].end()));
            c[i].erase(*prev(c[i].end()));
        }
        while(!uc[i].empty()&&add((*uc[i].begin()),i)){
            // cout<<" siz:"<<uc[i].size()<<endl;
            c[i].insert(*uc[i].begin());
            uc[i].erase(*uc[i].begin());
        }
    }
}

int get_bc(){
    int fst=*b.begin(),ed=*prev(b.end());
    int ans=0;bool f=0;
    if(fst-1>s[a[fst]])++ans;
    else s[a[fst]]-=fst-1,f=1;
    if(n-ed>s[a[ed]])++ans;
    if(f)s[a[fst]]+=fst-1;
    return ans;
}

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read();m=read();q=read();
    for(int i=1;i<=n;++i){
        int x=read();
        s[x&1]++;
    }
    // cout<<"/cc1"<<endl;
    for(int i=1;i<=m;++i){
        int p=read(),x=read();
        a[p]=x&1;
        s[a[p]]--;
        b.insert(p);
    }
    // cout<<" /cc2"<<endl;
    for(auto i=b.begin();i!=b.end();++i){
        if(i==b.begin())continue;
        pre[*i]=*(prev(i));
        // cout<<" i:"<<*i<<" pre:"<<pre[*i]<<" a:"<<a[*i]<<endl;
        if(a[pre[*i]]!=a[*i]){
            ++ans;
        }
        else{
            uc[a[*i]].insert({*i,*i-pre[*i]-1});
            // cout<<" i:"<<*i<<" len:"<<*i-pre[*i]-1<<" a:"<<a[*i]<<endl;
            // cout<<" siz:"<<uc[a[*i]].size()<<endl;
            ans+=2;
        }
    }
    maintain();
    // cout<<" ans:"<<ans<<endl;
    for(int i=1,op,p,x;i<=q;++i){
        // cout<<" i:"<<i<<endl;
        op=read();p=read();
        if(op==1){
            auto nxts=b.upper_bound(p);
            int nxt=(nxts==b.end())?0:*nxts;
            erase(p);
            if(nxt)erase(nxt);
            b.erase(p);
            if(nxt)pre[nxt]=pre[p],pre[p]=0;
            if(nxt)add(nxt);
            s[a[p]]++;
        }
        else{
            x=read()&1;
            a[p]=x;s[x]--;
            auto nxts=b.upper_bound(p);
            int nxt=(nxts==b.end())?0:*nxts;
            // cout<<" /dd1"<<endl;
            if(nxt)erase(nxt);
            // cout<<" /dd2"<<endl;
            b.insert(p);
            pre[p]=*prev(b.lower_bound(p));
            if(nxt)pre[nxt]=p;
            // cout<<" p:"<<p<<" a:"<<a[p]<<" pre:"<<pre[p]<<" a:"<<a[pre[p]]<<" nxt:"<<nxt<<" a:"<<a[nxt]<<endl;
            add(p);
            // cout<<" /dd3"<<endl;
            if(nxt)add(nxt);
        }
        maintain();
        print(ans+get_bc());putchar('\n');
        // cout<<" pre:";
        // for(int i=1;i<=n;++i){
        //     cout<<" "<<pre[i];
        // }cout<<endl;
    }
    return 0;
}

/*
10 8 10 15 4 12 10 14 5 18 7 9 11 5 12 6 18 1 4 10 5 7 7 2 15 9 14 4 10 2 8 11
*/