#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define pii pair<int,int>
#define mpr make_pair

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

int n,a[N],T,b[N],ans;
vector<int> c[N];
struct que{
    priority_queue<pii> q;
    map<pii,int> m;
    void clear(){
        while(!q.empty())q.pop();
        m.clear();
    }
    void push(pii x){
        if(m[x])--m[x];
        else q.push(x);
    }
    void pop(){
        q.pop();
    }
    void del(pii x){
        m[x]++;
    }
    pii top(){
        while(m[q.top()]){
            --m[q.top()];q.pop();
        }
        return q.top();
    }
}q1;
struct que2{
    priority_queue<pii,vector<pii>,greater<pii>> q;
    map<pii,int> m;
    void clear(){
        while(!q.empty())q.pop();
        m.clear();
    }
    void push(pii x){
        if(m[x])--m[x];
        else q.push(x);
    }
    void pop(){
        q.pop();
    }
    void del(pii x){
        m[x]++;
    }
    pii top(){
        while(m[q.top()]){
            --m[q.top()];q.pop();
        }
        return q.top();
    }
}q2;

void work(){
    for(int i=1;i<=n;++i)c[i].clear();
    q1.clear();q2.clear();
    for(int i=1;i<=n;++i){
        q1.push(mpr(a[i],i));
        q2.push(mpr(a[i],i));
    }
    for(int i=1;i<n;++i){
        pii x=q1.top(),y=q2.top();
        // cout<<" i:"<<i<<" "
        q1.pop();q2.pop();
        q1.del(y);q2.del(x);
        b[i]=y.second;
        c[x.second].push_back(i);
        x.first-=y.first;
        q1.push(x);q2.push(x);
    }
    ans=1;
    for(int i=n-1;i>=1;--i){
        if(!c[b[i]].empty()){
            i=c[b[i]][c[b[i]].size()-1];
            ans=n-i+1;
            c[b[i]].erase(prev(c[b[i]].end()));
        }
    }
    print(ans);putchar('\n');
}

signed main(){
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    T=read();
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    work();
    while(--T){
        int m=read();
        for(int i=1;i<=m;++i){
            int x=read(),y=read();
            a[x]=y;
        }
        work();
    }
    return 0;
}