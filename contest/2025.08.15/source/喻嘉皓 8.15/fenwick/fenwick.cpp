#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)
#define ull unsigned long long
int n;
ull s1,s2,ans;
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
const int N=10000010;
ull a[N];
void add(int x,int k){
	int cnt=1;
	for(;x<=n;x+=lowbit(x)){
		a[x]+=k*cnt;
		cnt++;
	}
}
ull get(int x){
	ull sum=0;
	for(;x;x-=lowbit(x)){
		sum+=a[x];
	}
	return sum;
}
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    for(int i=1;i<=Q;++i){
    	int op;
    	ull num1,num2;
    	get_query(op,num1,num2);
    	if(op==1) add(num1,num2);
		else{
			ull res=get(num2)-get(num1-1);
			ans^=(ull)i*res;
		}
	}
	cout<<ans;
//    printf("2588154976231288790\n");
    return 0;
}
