#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n;
ull s1, s2;
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

ull a[10000005];
void add(int x,ull k){
    int cnt = 1;
    for (int i = x; i <= n;i+=(i & (-i))){
        a[i] += (cnt++) * k;
    }
}
ull query(int x){
    ull anss = 0;
    for (int i = x; i > 0;i-=(i & (-i))){
        anss += a[i];
    }
    return anss;
}

int main(){
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu", &n, &Q, &s1, &s2);
    ull anss = 0, id = 1;
    while(Q--){
        int op;
        ull num1, num2;
        get_query(op, num1, num2);
        if(op==1){
            add(num1, num2);
        }else{
            ull ans = query(num2) - query(num1 - 1);
            anss = (anss ^ (id * ans));
        }
        id++;
    }
    cout << anss;
    return 0;
}