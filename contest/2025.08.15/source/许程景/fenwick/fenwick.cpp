#include <stdio.h>
#define ull unsigned long long
int n,t;
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
        if(num1>num2){
            t=num2;
            num2=num1;
            num1=t;
        }
    }
}
#define lowbit(x) (x&(-x))
ull all[10000001];
ull ans;
void add(ull x,ull val){
	for(int i=1;x<=n;x+=lowbit(x),i++) all[x]+=i*val;
}
ull query(ull l,ull r){
	ull tmp=0ull;
	for(;r;r^=lowbit(r)) tmp+=all[r];
	for(l=l-1;l;l^=lowbit(l)) tmp-=all[l];
	return tmp;
}
int Q;
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    for(int i=1;i<=Q;i++){
        int op;
        ull x,y;
        get_query(op,x,y);
        // printf("<%d,%llu,%llu>\n",op,x,y);
        if(op==1) add(x,y);
        else ans^=query(x, y)*i;
    }
    printf("%llu\n",ans);
    return 0;
}