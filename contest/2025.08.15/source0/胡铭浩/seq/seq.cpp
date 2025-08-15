#include<bits/stdc++.h>
using namespace std;
inline int read() 
{
    register int x=0;
    register char ch=cin.get();
    while(!isdigit(ch)) ch=cin.get();
    while(isdigit(ch)) {(x*=10)+=(ch^48);ch=cin.get();}
    return x;
}
const int mod = 998244353;
const int N = 1e6+9;
int n,m,a[N];
vector<vector<int> >s;
vector<int>p,b;
int ans;
int main()
{
    ios::sync_with_stdio(0);
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    n=read();for(register int i(1);i<=n;++i) a[i]=read();
    m=read();for(register int i(1),x;i<=m;++i) x=read(),b.push_back(x);
    int lim=(1<<n)-1;
    for(register int i(1);i<=lim;++i)
    {
		p.clear();
        for(register int j(1);j<=n;++j) if(i&(1<<(j-1))) p.push_back(a[j]);
		s.push_back(p);
    }
    sort(s.begin(),s.end());unique(s.begin(),s.end());
    for(auto k:s) 
    if(k==b) return !printf("%d\n",ans+1);
    else ++ans;
    printf("%d\n",ans+1);
    return 0;
}
