#include<bits/stdc++.h>
#define int long long 
using namespace std;
int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}
struct frac{
    int x,y;
    frac(int x=0,int y=0):x(x),y(y){}
};
frac operator-(frac x,frac y){
    frac res;
    res.y=x.y*y.y;
    res.x=x.x*y.y-x.y*y.x;
    int v=gcd(res.x,res.y);
    res.x/=v,res.y/=v;
    return res;
}
bool operator<(frac x,frac y){
    return x.x*y.y<y.x*x.y;
}
int mxd;
int x,y;
int val[10];
bool flag;
void dfs(int x,int lst,frac now){
    if(x==mxd){
        if(now.x==1&&now.y>val[x-1]){
            val[x]=now.y;
//            printf("%lld\n",mxd);
            for(int i=1;i<=mxd;i++)printf("%lld%c",val[i]," \n"[i==mxd]);
            flag=1;
        }return;
    }
    for(int i=max(lst+1,(now.y+now.x-1)/now.x);;i++){
        if(frac(mxd-x+1,i)<now)break;
		val[x]=i;
        dfs(x+1,i,now-frac(1,i));
        if(flag)return;
    }
}
int solve(int x,int y){
    flag=0;mxd=0;
    while(!flag){
        mxd++;
        dfs(1,0,frac(x,y));
    }
    return 0;
}
signed main(){
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
	int x,y;scanf("%lld%lld",&x,&y);
	if(!x){
		puts("0");
		return 0; 
	}
	int v=gcd(x,y);x/=v,y/=v;
	solve(x,y);
	return 0;
}
