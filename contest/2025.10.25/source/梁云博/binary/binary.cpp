#include <bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;



int n,m;

namespace moi
{
    int uid,qid,res;
    int cnt1,cnt0;
    int a[N],book[1000005],pos[N],ans[N];
    struct update{
        int pre,val,pos;
    }u[N];
    struct T{
        int l,r,t,id;
    }b[N];
    void add(int x)
    {
        book[a[x]]++;
        if(book[a[x]]==1)res++;
    }

    // void add(int x)
    // {
    //     cnt1+=x==1;
    //     cnt0+=x==0;
    //     if(cnt1)
    // }

    void del(int x)
    {
        cnt1-=x==1;
        cnt0-=x==0;

    }
    void upd(int t,int l,int r)
    {
        int pos=u[t].pos;
        if(l<=pos && pos<=r)
        {
            del(pos);
            a[pos]=u[t].val;
            add(pos);
        }
        else a[pos]=u[t].val;
    }
    void udo(int t,int l,int r)
    {
        int pos=u[t].pos;
        if(l<=pos && pos<=r)
        {
            del(pos);
            a[pos]=u[t].pre;
            add(pos);
        }
        else a[pos]=u[t].pre;
    }
}

namespace solve
{
    using namespace moi;
    void solve()
    {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int len=pow(n,2.0/3);
        for(int i=1;i<=(n+len-1)/len;i++)
            for(int j=(i-1)*len+1;j<=i*len;j++)
                pos[j]=i;
        cin>>m;
        int x,y,ty;
        for(int i=1;i<=m;i++)
        {
            cin>>ty;
            if(ty==1)
            {
                cin>>x;
                y=a[x]^1;
                u[++uid]={a[x],y,x};
                a[x]=y;
            }
            else 
            {
                cin>>x>>y;
                b[++qid]={x,y,uid,qid};
            }
        }
        sort(b+1,b+1+qid,[](T a,T b)
        {
            if(pos[a.l]==pos[b.l] && pos[a.r]==pos[b.r])return a.t<b.t;
            else if(pos[a.l]==pos[b.l])return pos[a.r]<pos[b.r];
            else return pos[a.l]<pos[b.l];
        });
        for(int i=uid;i>=1;i--)a[u[i].pos]=u[i].pre;
        int l=1,r=0,t=0;
        for(int i=1;i<=qid;i++)
        {
            int ql=b[i].l,qr=b[i].r,qt=b[i].t;
            while(t<qt)upd(++t,l,r);
            while(t>qt)udo(t--,l,r);
            while(l>ql)add(--l);
            while(r<qr)add(++r);
            while(l<ql)del(l++);
            while(r>qr)del(r--);
            ans[b[i].id]=res;
        }
        for(int i=1;i<=qid;i++)cout<<ans[i]<<"\n";
    }
}

namespace solve2
{
    bitset<N> a;
    int pre[N];
    void solve()
    {
        cin>>n;
        for(int i=1,x;i<=n;i++)cin>>x,a[i]=x,pre[i]=pre[i-1]+a[i];
        // for(int i=1;i<=n;i++)cout<<pre[i]<<" ";
        // cout<<"\n";
        cin>>m;
        int ty,l,r,x;

        while(m--)
        {
            cin>>ty;
            if(ty==1)
            {
                cin>>x;
                a[x]=a[x]^1;
                for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
            }
            else
            {
                cin>>l>>r;
                int ans=0;
                for(int i=l;i<=r;i++)
                {
                    for(int j=i;j<=r;j++)
                    {
                        int cnt=pre[j]-pre[i-1];
                        if(cnt&1)
                        {
                            if(i-j+1-cnt>=2)ans++;
                        }
                        else ans++;
                    }
                }
                cout<<ans<<"\n";
            }
        }
    }
}

signed main()
{
    
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve2::solve();

    return 0;
}