#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
struct Data{
    ll v00,v01,v10,v11,ans;
    void upd0(int v){
        v=min(v,2);
        if(v==1){
            ans+=v10+v11;
            v10=v00,v11=v01;
            v00=v01=0;
        }
        if(v==2){
            ans+=v00+v01+v10+v11;
            v00=v01=v10=v11=0;
        }
    }
    void upd1(int v){
        v&=1;if(!v)return;
        swap(v00,v01);
        swap(v10,v11);
    }
};
ll operator*(Data x,Data y){
    return x.v00*(y.v00+y.v10+y.ans)+x.v01*(y.v01+y.v11+y.ans)+x.v10*(y.v00+y.v10+y.v11+y.ans)+x.v11*(y.v01+y.v10+y.v11+y.ans)+x.ans*(y.v00+y.v01+y.v10+y.v11+y.ans);
}
Data operator+(Data x,Data y){
    return {x.v00+y.v00,x.v01+y.v01,x.v10+y.v10,x.v11+y.v11,x.ans+y.ans};
}
struct Node{
    Data vl,vr;
    ll ans;
    int cnt0,cnt1;
}t[N<<2];
Node operator+(Node x,Node y){
    Node res;
    res.cnt0=x.cnt0+y.cnt0;
    res.cnt1=x.cnt1+y.cnt1;
    res.ans=x.ans+y.ans+x.vr*y.vl;
    res.vl=y.vl;res.vl.upd0(x.cnt0);res.vl.upd1(x.cnt1);res.vl=res.vl+x.vl;
    res.vr=x.vr;res.vr.upd0(y.cnt0);res.vr.upd1(y.cnt1);res.vr=res.vr+y.vr;
    return res;
}
int n,m,a[N];
void pushup(int p){
    t[p]=t[p<<1]+t[p<<1|1];
}
void build(int p,int l,int r){
    if(l==r){
        if(a[l]){
            t[p].vl=t[p].vr={0,1,0,0,0};
            t[p].ans=0;
            t[p].cnt0=0;
            t[p].cnt1=1;
        }else{
            t[p].vl=t[p].vr={0,0,1,0,0};
            t[p].ans=1;
            t[p].cnt0=1;
            t[p].cnt1=0;
        }return;
    }int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}
void change(int p,int l,int r,int k){
    if(l==r){
        if(a[l]){
            t[p].vl=t[p].vr={0,1,0,0,0};
            t[p].ans=0;
            t[p].cnt0=0;
            t[p].cnt1=1;
        }else{
            t[p].vl=t[p].vr={0,0,1,0,0};
            t[p].ans=1;
            t[p].cnt0=1;
            t[p].cnt1=0;
        }return;
    }int mid=l+r>>1;
    if(k<=mid)change(p<<1,l,mid,k);
    else change(p<<1|1,mid+1,r,k);
    pushup(p);
}
Node query(int p,int l,int r,int l1,int r1){
    if(l1<=l&&r<=r1)return t[p];
    int mid=l+r>>1;
    if(r1<=mid)return query(p<<1,l,mid,l1,r1);
    if(l1>mid)return query(p<<1|1,mid+1,r,l1,r1);
    return query(p<<1,l,mid,l1,r1)+query(p<<1|1,mid+1,r,l1,r1);
}
namespace seg{
    set<int>st;
    ll sum[N<<2];
    ll calc(int l1,int l2){
        ll ans=1ll*l1*l2;
        for(int i=1;i<=min(l1,2);i++)for(int j=1;j<=min(l2,2);j++)if(i+j<=3)ans--;
        // printf("calc:%d %d %lld\n",l1,l2,ans);
        return ans;
    }
    ll calc(int pos,int l,int r){
        int L=*prev(st.lower_bound(pos))+1;
        int R=*(st.upper_bound(pos))-1;
        // printf("CALC:%d %d %d\n",pos,L,R);
        L=max(L,l);
        R=min(R,r);
        return calc(pos-L+1,R-pos+1);
    }
    void pushup(int p){
        sum[p]=sum[p<<1]+sum[p<<1|1];
    }
    void build(int p,int l,int r){
        if(l==r){
            if(a[l])sum[p]=calc(l,1,n);
            else sum[p]=0;
            return;
        }int mid=l+r>>1;
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        pushup(p);
    }
    void change(int p,int l,int r,int k){
        if(l==r){
            if(a[l])sum[p]=calc(l,1,n);
            else sum[p]=0;
            return;
        }int mid=l+r>>1;
        if(k<=mid)change(p<<1,l,mid,k);
        else change(p<<1|1,mid+1,r,k);
        pushup(p);
    }
    ll query(int p,int l,int r,int l1,int r1){
        if(l1<=l&&r<=r1)return sum[p];
        int mid=l+r>>1;ll res=0;
        if(l1<=mid)res+=query(p<<1,l,mid,l1,r1);
        if(r1>mid)res+=query(p<<1|1,mid+1,r,l1,r1);
        return res;
    }
    void init(){
        st.insert(0),st.insert(n+1);
        for(int i=1;i<=n;i++)if(a[i])st.insert(i);
        build(1,1,n);
    }
    void upd(int x){
        if(st.count(x))st.erase(x);
        else st.insert(x);
        int L=*prev(st.lower_bound(x));
        int R=*(st.upper_bound(x));
        if(L!=1)change(1,1,n,L);
        change(1,1,n,x);
        if(R!=n+1)change(1,1,n,R);
    }
    ll query(int l,int r){
        ll res=query(1,1,n,l,r);
        if(!res)return 0;
        int x=*(st.lower_bound(l)),y=*prev(st.upper_bound(r));
        if(x==y)return calc(x,l,r);
        return res-calc(x,1,n)-calc(y,1,n)+calc(x,l,r)+calc(y,l,r);
    }
}
int main(){
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    scanf("%d",&m);
    build(1,1,n);seg::init();
    while(m--){
        int op;scanf("%d",&op);
        if(op==1){
            int x;scanf("%d",&x);a[x]^=1;
            change(1,1,n,x);seg::upd(x);
        }else{
            int l,r;scanf("%d%d",&l,&r);
            Node res=query(1,1,n,l,r);
            printf("%lld\n",res.ans-seg::query(l,r));
        }
    }
    return 0;
}
/*
区间中:0的数量<=1，要求1的数量为偶数
否则一定合法
*/