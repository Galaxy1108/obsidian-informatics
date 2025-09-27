#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e4+10;
ll n,k,m;
ll num[N];
bool sign[50];
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
int main(){
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
    read(n),read(k),read(m);
    for(ll i=1;i<=n;i++)
        read(num[i]);
    while(m--){
        ll op;
        read(op);
        if(op==1){
            ll p,v;
            read(p),read(v);
            num[p]=v;
        }
        else{
            ll cnt=k,ans=0x7fffffff;
            bool flag=0;
            for(ll i=1;i<=n-k+1;i++){
                ll j=i;
                cnt=k;
                memset(sign,0,sizeof(sign));
                for(;j<=n;j++){
                    if(!sign[num[j]]){
                        sign[num[j]]=1;
                        cnt--;
                    }
                    if(!cnt)
                        break;
                }
                if(i==1&&j==n+1&&cnt>0){
                    printf("-1\n");
                    flag=1;
                    break;
                }
                ans=min(ans,j-i+1);
            }
            if(!flag)
                printf("%lld\n",ans);
        }
    }
	return 0;
}
