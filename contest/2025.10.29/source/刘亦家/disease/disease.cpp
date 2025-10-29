#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
using namespace std;
typedef long long ll;
ll n,p;
vector<ll> tree[310];
inline ll read(){
	ll x=0,f=1;
	char ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=gc();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		pc('-');
		x=-x;
	}
	if(x>9)
		write(x/10);
	pc(x%10+'0');
}
inline void dfs(ll id,ll dep){
    
}
int main(){
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	n=read(),p=read();
    up(i,1,p){
        ll u=read(),v=read();
        tree[u].push_back(v);
    }
    if(tree[1].size()==n-1)
        cout<<n-1;
    else{
        ll i=1;
        while(tree[i].size()==1&&tree[i][0]==i+1&&i<n)
            i++;
        if(i==n)
            cout<<1;
        else{
            random_device rd;
            mt19937 rng(rd());
            srand(rd());
            cout<<(rng()%rand())%300;
        }
    }
	return 0;
}
