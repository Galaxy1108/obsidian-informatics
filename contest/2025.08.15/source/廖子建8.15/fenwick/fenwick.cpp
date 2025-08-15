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
#define lowbit(x) (x&-x)
#define N 10000000
int Q,opt;
unsigned long long ux,uy,tree[N+5],ans=0;
void add(int x,unsigned long long v){
	int k=v;
	while(x<=n){
		tree[x]+=k;
		x+=lowbit(x),k+=v;
	}
	return;
}
unsigned long long find(int x){
	unsigned long long sum=0;
	while(x){
//		cout<<x<<" "<<tree[x]<<" find\n";
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}
unsigned long long read(){
	unsigned long long f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(unsigned long long x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    for(unsigned long long i=1;i<=Q;i++){
    	get_query(opt,ux,uy);
//    	cout<<opt<<" "<<ux<<" "<<uy<<" "<<ans<<"\n";
    	if(opt==1)add(ux,uy);
    	else ans^=i*(find(uy)-find(ux-1));
	}
	print(ans);
    return 0;
}
