#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m,q;
struct node{
    ll data;
    bool sign;
}card[N];
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
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    read(n),read(m),read(q);
    for(ll i=1;i<=n;i++)
        read(card[i].data);
    for(ll i=1;i<=m;i++){
        ll a;
        read(a),read(card[a].data);
        card[a].sign=1;
    }
    while(q--){
        ll op,p,x,ans=0;
        read(op),read(p);
        if(op==1)
            card[p].sign=0;
        else{
            read(x);
            card[p].data=x;
            card[p].sign=1;
        }
        for(ll j=2;j<=n;j++){
            if((card[j].data%2==0&&card[j-1].data%2==1)||(card[j].data%2==1&&card[j-1].data%2==0)){
                if(card[j].sign&&card[j-1].sign)
                    ans++;
                else{
                    if(card[j].sign&&!card[j-1].sign){
                        card[j].data+=1;
                        card[j].sign=0;
                    }
                    else if(!card[j].sign&&card[j-1].sign){
                        card[j-1].data+=1;
                        card[j-1].sign=1;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}