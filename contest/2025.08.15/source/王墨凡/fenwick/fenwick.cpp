#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n;
ull s1,s2;
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
#undef ull
int Q;
unsigned long long tree1[10000086],tree2[10000086],ans,mod;
void add1(int x,int k){
	unsigned long long mem=k;
	for(;x<=n;x+=x&(-x)){
		tree1[x]+=k;
		tree2[x]+=mem;
		mem+=k;
	}
}
unsigned long long ask(int x){
	unsigned long long res=0;
	for(;x;x-=x&(-x)){
		res+=tree2[x];
	}
	return res;
}
int main(){
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
	int op,cnt;
	unsigned long long num1,num2;
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    for(int i=1;i<=Q;i++){
    	get_query(op,num1,num2);
		if(op==1){
			add1(num1,num2);
		}
		else{
			unsigned long long now=ask(num2)-ask(num1-1);
			ans^=i*now;
		}
	}
	cout << ans;
    return 0;
}
