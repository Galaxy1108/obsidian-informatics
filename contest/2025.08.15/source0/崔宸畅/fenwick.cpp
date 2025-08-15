#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n;
ull s1,s2;
int lowbit(int x){return x&(-x);}
inline ull my_rand()
{
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
int op;ull num1,num2;
ull Ans;
const int maxn=1e7+50;
int a[maxn];
__uint128_t sum[maxn];
inline void add(register int x,int k){
	for(register int cz=1;x<=n;x+=lowbit(x),cz++) sum[x]+=k*cz,sum[x]-=(sum[x]>>64)<<64;
}
inline ull get_sum(register int x){
	__uint128_t ans=0;
	for(;x;x-=lowbit(x)){ans+=sum[x];ans-=(ans>>64)<<64; }
	return ans;
}
inline void get_query(int &op,ull &num1,ull &num2){
    op=my_rand()%2+1;
    if(op==1){
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
    }
    else{
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)
             swap(num1,num2);
    }
}
//#undef ull
int Q;
int main(){
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    for(register int i=1;i<=Q;i++){
    	get_query(op,num1,num2);
    	if(op==2){
    		__uint128_t W=get_sum(num2)-get_sum(num1-1);
    		Ans^=W*i;Ans-=((__uint128_t)Ans>>64)<<64;
		}
		else{
			add(num1,num2);
		}
	}
	printf("%llu",Ans);
//	cout<<Ans;
//    printf("2588154976231288790\n");
    return 0;
}
