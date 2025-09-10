#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=1e9+7;
ll n,k;
int s[15];
int oo(ll a){
    int shu=0;
    ll os=a;
    while(a>0){
        a/=10;
        ++shu;
    }
    for(int i=1;i<=shu;++i) {s[i]=os%10;os/=10;}
    return shu;
}
ll dp[13][42][30][20][20];
bool yf[13][42][30][20][20];
void ch(int wi,int a[4]){
    while(wi%2==0) a[0]--,wi/=2;
    while(wi%3==0) a[1]--,wi/=3;
    while(wi%5==0) a[2]--,wi/=5;
    while(wi%7==0) a[3]--,wi/=7;
}
ll dfs(int wi,bool c,int a[4]){
	if(wi==0){
		for(int i=0;i<4;++i){
			if(a[i]!=0) return 0;
		}
		return 1;
	}
	int b[4];
	for(int i=0;i<4;++i) {
    	if(a[i]<0) return 0;
    	b[i]=a[i];
	}
    ll ans=0;
    if(c){
        if(s[wi]>0){
            ch(s[wi],a);
            ans+=dfs(wi-1,1,a);
        }
        for(int i=0;i<4;++i) a[i]=b[i];
        for(int i=s[wi]-1;i>=1;--i){
            ch(i,a);
            ans+=dfs(wi-1,0,a);
            for(int i=0;i<4;++i) a[i]=b[i];
        }
        return ans%M;
    }
    if(yf[wi][a[0]][a[1]][a[2]][a[3]]>0) return dp[wi][a[0]][a[1]][a[2]][a[3]];
    for(int i=9;i>=1;--i){
        ch(i,a);
        ans+=dfs(wi-1,0,a);
        for(int i=0;i<4;++i) a[i]=b[i];
    }
    ans%=M;
    yf[wi][a[0]][a[1]][a[2]][a[3]]=1;
    dp[wi][a[0]][a[1]][a[2]][a[3]]=ans;
    return ans;
}
const int F=3e6;
ll ccd[F];
int ct=0;
struct qwq{
    int fa,fb;
    bool operator < (const qwq &xx)const{
        return ccd[fa]*ccd[fb]<ccd[xx.fa]*ccd[xx.fb];
    }
};
priority_queue <qwq> p;
int main(){
	freopen("find.in","r",stdin);
    freopen("find.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    int yo=oo(n);
    ll aa=1,bb=1,cc=1,dd=1;
    ll ans=0;
    int df[4];
    for(int i=0;i<=40;++i,aa*=2){
        if(aa>n) break;
        for(int j=0;j<=30;++j,bb*=3){
            if(aa*bb>n) break;
            for(int w=0;w<=20;++w,cc*=5){
                if(aa*bb*cc>n) break;
                for(int q=0;q<=20;++q,dd*=7){
                    if(aa*bb*cc*dd>n) break;
                    ans=0;
                    df[0]=i,df[1]=j,df[2]=w,df[3]=q;
                    for(int g=yo;g>=1;--g){
                        if(g==yo)ans+=dfs(g,1,df);
                        else ans+=dfs(g,0,df);
                    }
                    ccd[++ct]=ans%M;
                }
                dd=1;
            }
            cc=1;
        }
        bb=1;
    }
    sort(ccd+1,ccd+ct+1);
    ll outs=0;
    int lo=ct;
    qwq f,g;
    f.fa=ct,f.fb=ct;
    p.push(f);
    while(k--){
        f=p.top();p.pop();
        outs=(outs+(ccd[f.fa]*ccd[f.fb])%M)%M;
        if(f.fa==lo){
            g.fa=lo-1;
            g.fb=ct;lo--;
            p.push(g);
        }
        if(f.fb>1){
            g.fa=f.fa;
            g.fb=f.fb-1;
            p.push(g);
        }
    }
    printf("%lld",(outs%M+M)%M);
    return 0;
}
