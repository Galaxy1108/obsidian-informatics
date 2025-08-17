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
int op,Q,cnt;
ull num1,num2,num[10000010],ans,ANS;
int x;
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    double tim=clock();
    for(int i=1;i<=Q;i++)
    {
        get_query(op,num1,num2);

        // printf("%d %llu %llu\n",op,num1,num2);

        if(op==1)
        {
            for(x=num1,cnt=1;x<=n;x+=(x&-x),cnt++)
                num[x]+=num2*cnt;
        }
        else
        {
            ans=0;
            for(x=num2;x;x-=(x&(-x)))
                ans+=num[x];
            for(x=num1-1;x;x-=(x&(-x)))
                ans-=num[x];
            ans*=i;
            ANS^=ans;
        }

        // for(int i=1;i<=n;i++) printf("%llu ",num[i]);printf("\n");
    }
    printf("%llu\n",ANS);
    cerr<<(clock()-tim)/1000<<endl;
    return 0;
}