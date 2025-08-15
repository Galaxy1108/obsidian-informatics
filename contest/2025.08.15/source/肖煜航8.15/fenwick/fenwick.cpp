#include<bits/stdc++.h>
using namespace std;
#define N 10000005
#define ull unsigned long long
int n;
ull s1,s2;
ull my_rand(){
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
void get_query(int &op,ull &num1,ull &num2){
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
ull c[N];
void add(int x,ull k){
	ull cnt=1;
	for(int i=x;i<=n;i+=(i&-i),cnt++) c[i]+=cnt*k;
}
ull query(int x){
	ull sum=0;
	for(int i=x;i;i-=(i&-i)) sum+=c[i];
	return sum;
}
int Q;
int main(){
  	freopen("fenwick.in","r",stdin);
  	freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    ull ans=0;
    for(ull i=1;i<=Q;i++){
    	int op;ull x,y;
    	get_query(op,x,y);
    	if(op==1){
    		add(x,y);
		}
		else{
			ans^=(ull)(i*query(y)-i*query(x-1));
		}
	}
	printf("%llu",ans);
	return 0;
}
