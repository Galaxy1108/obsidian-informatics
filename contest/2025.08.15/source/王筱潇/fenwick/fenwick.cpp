#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ii __int128
ii mod=1;
int n;
ii a[10000010];
ull s1,s2;
ii anss,ans;
void bdd(ii x,ii k){
	for(;x<=n;x+=(x&-x)){
		a[x]=(a[x]+k)%mod;
	}
}
void add(ii x,ii k){
	for(;x<=n;x+=(x&-x)){
		bdd(x,k);
	}
}
ull my_rand()
{
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
void get_query(int &op,ull &num1,ull &num2)
{
    op=my_rand()%2+1;
    if(op==1)
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
    }
    else
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)
             swap(num1,num2);
    }
}
int Q;
ii query(ii x){
	ii ansss=0;
	for(;x;x-=(x&-x)){
		ansss+=a[x];
	}
	return ansss;
}
int main(){
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    mod=pow(2,64);
    ull num1,num2;
    int op;
    for(int i=1;i<=Q;i++){
    	get_query(op,num1,num2);
    	if(op==1){
    		add(num1,num2);
		}
    	if(op==2) ans^=i*(query(num2)-query(num1-1));
    	ans%=mod;
	}
	
	printf("%lld",(ull)ans);
    return 0;
}
