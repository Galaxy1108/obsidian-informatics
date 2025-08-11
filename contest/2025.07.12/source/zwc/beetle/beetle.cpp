#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define lb(x) (x&(-x))
#define ls(x) t[x].ls
#define rs(x) t[x].rs
#define pii pair<int,int>
#define mpr make_pair
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
const int N=2.5e6+5,P=1e9+7,inf=1e18;

int read(){
	int ans=0;
	char c=getchar();
	bool f=0;
	for(;!isdigit(c);c=getchar())if(c=='-')f=1;
	for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
	return f?-ans:ans;
}

void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10|48);
}

int n,m,a[N],L[N],f[N],st[N],l,r;
stack<int> stk;
//priority_queue<int,vector<int>,greater<int> > q;



int sumx[N],vx[N],al=2,ar=1,mid=2;

void add_r(int x){
    //cout<<" /addr x:"<<x<<" al:"<<al<<" ar:"<<ar<<endl;
    sumx[++ar]=x;vx[ar]=x;
    if(ar>mid)sumx[ar]=min(sumx[ar],sumx[ar-1]);
}

void add_l(int x){
    sumx[--al]=x;vx[al]=x;
    if(al<mid)sumx[al]=min(sumx[al],sumx[al+1]);
}

void anew(){
    mid=al+ar+1>>1;
    if(al>ar)return;
    for(int i=mid;i>=al;--i){
        sumx[i]=vx[i];
        if(i<mid)sumx[i]=min(sumx[i],sumx[i+1]);
    }
    for(int i=mid;i<=ar;++i){
        sumx[i]=vx[i];
        if(i>mid)sumx[i]=min(sumx[i],sumx[i-1]);
    }
}

void del_r(){
    //cout<<" /delr al:"<<al<<" ar:"<<ar<<endl;
    --ar;
    if(ar<mid)anew();
}

void del_l(){
    //cout<<" /dell al:"<<al<<" ar:"<<ar<<endl;
    ++al;
    if(al>mid)anew();
}

int qry(){
    if(al>ar)return inf;
    return min(sumx[al],sumx[ar]);
}

signed main(){
    freopen("beetle.in","r",stdin);
    freopen("beetle.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i){
        while(!stk.empty()&&a[i]>=a[stk.top()])stk.pop();
        if(!stk.empty())L[i]=stk.top();
        else L[i]=0;
        stk.push(i);
    }
    memset(f,0x3F,sizeof(f));
    f[0]=0;f[1]=a[1];add_r(f[L[1]]+a[1]);st[1]=1;
    for(int i=2,l=1,r=1,last=0;i<=n;++i){
        while(l<=r&&a[i]>a[st[r]]){
            //erase(f[L[st[r]]]+a[st[r]]);
            del_r();
            --r;
        }
        //cout<<" i:"<<i<<" L:"<<L[i]<<" r:"<<st[r]<<endl;
        st[++r]=i;
        add_r(f[L[i]]+a[i]);
        while(l<=r&&L[st[l]]<i-m){
            last=st[l];
            //erase(f[L[st[l]]]+a[st[l]]);
            del_l();
            //cout<<" /last :"<<last<<endl;
            ++l;
        }
        f[i]=qry();
        if(last){
            f[i]=min(f[i],f[i-m]+a[last]);
        }
        //cout<<" i:" <<i<<" f:"<<f[i]<<endl;
    }
    int ans=0,x=1;
    for(int i=n;i>=1;--i,x=x*23%P){
        ans=(ans+f[i]%P*x%P)%P;
    }
    print(ans);putchar('\n');
    return 0;
}
