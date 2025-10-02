#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t int128;
const int N=2e6+10;
ll n;
ll high[N];
queue<ll> q;
priority_queue<ll> maxheap;
priority_queue<ll,vector<ll>,greater<ll>> minheap;
inline void read(ll &a){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	a=x*f;
}
inline int128 int128_max(int128 a,int128 b){
    if(a>=b)
        return a;
    else
        return b;
}
inline void write(int128 a){
    if(a>9)
        write(a/10);
    putchar(a%10+'0');
}
inline void in(ll x){
    q.push(x);
    maxheap.push(x);
    minheap.push(x);
}
inline void out(){
    q.pop();
    maxheap.pop();
    minheap.pop();
}
int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
    read(n);
    for(ll i=1;i<=n;i++)
        read(high[i]);
    int128 ans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            maxheap.push(high[j]);
            minheap.push(high[j]);
            int128 tmp=maxheap.top()*minheap.top()*(j-i+1);
            ans=int128_max(ans,tmp);
        }
        while(minheap.size())
            minheap.pop();
        while(maxheap.size())
            maxheap.pop();
    }
    write(ans);
    // for(ll i=1;i<=n;i++){
    //     if(q.size()){
    //         int128 pre=maxheap.top()*minheap.top()*q.size();
    //         in(high[i]);
    //         int128 now=maxheap.top()*minheap.top()*q.size();
    //         if(now<pre){
    //             out();
    //             while(q.size()){
    //                 int128 tmp=maxheap.top()*minheap.top()*q.size();
    //                 ans=int128_max(tmp,ans);
    //                 if(maxheap.top()==q.front())
    //                     maxheap.pop();
    //                 if(minheap.top()==q.front())
    //                     minheap.pop();
    //                 q.pop();
    //             }
    //             while(minheap.size())
    //                 minheap.pop();
    //             while(maxheap.size())
    //                 maxheap.pop();
    //         }
    //     }
    //     else
    //         in(high[i]);
    // }
    // write(ans);
	return 0;
}
