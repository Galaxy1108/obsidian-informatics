#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n;
ull s1,s2,an;
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
__int128 b[10000007];
__int128 ans=-1,mod=pow(2,64);
ull cnt=0;
void add1(ull x,ull k){
	for(;x<=n;x+=(x&-x)){
		b[x]+=k;
		
	}
} 
void add(ull x,ull k){
	for(;x<=n;x+=(x&-x)){
		add1(x,k);
	}
} 

__int128 ans1=0;
__int128 query(ull x){
	ans1=0;
	while(x){
		ans1+=b[x];
		x-=(x&-x);
	}
	return ans1;
}
int main(){
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    int opt;
    ull t1,t2;
    for(int i=1;i<=Q;i++){
    	get_query(opt,t1,t2);
    	if(opt==1){
    		add(t1,t2);
		}
		else{
			if(ans==-1) ans=i*(query(t2)-query(t1-1));
			else ans^=i*(query(t2)-query(t1-1));
			ans%=mod;
		} 
	}
	an=ans;
	if(an==-1) cout<<0<<endl;
	else cout<<an<<endl;
    return 0;
}
