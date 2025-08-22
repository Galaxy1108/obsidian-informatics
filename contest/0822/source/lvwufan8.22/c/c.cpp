#include<bits/stdc++.h>
#include <random>
#include <algorithm>
using namespace std;
int n,seed;
const int MAXN=5010;
int a[MAXN][MAXN];
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    cin>>n>>seed;
    if(seed==0)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n+1;j++)
            {
                cin>>a[i][j];
            }
        } 
    }
    else
    {
        gen(n,seed);
    }
    if(n==2)
    {
        int a1,a2,a3,b1,b2,b3;
        if(a[1][1]==3)
        {
            a1=1;
        }
        if(a[1][2]==3)
        {
            a1=2;
        }
        if(a[1][3]==3)
        {
            a1=3;
        }
        if(a[1][1]==2)
        {
            a2=1;
        }
        if(a[1][2]==2)
        {
            a2=2;
        }
        if(a[1][3]==2)
        {
            a2=3;
        }
        if(a[1][1]==1)
        {
            a3=1;
        }
        if(a[1][2]==1)
        {
            a3=2;
        }
        if(a[1][3]==1)
        {
            a3=3;
        }
        //-----------------
        if(a[2][1]==3)
        {
            b1=1;
        }
        if(a[2][2]==3)
        {
            b1=2;
        }
        if(a[2][3]==3)
        {
            b1=3;
        }
        if(a[2][1]==2)
        {
            b2=1;
        }
        if(a[2][2]==2)
        {
            b2=2;
        }
        if(a[2][3]==2)
        {
            b2=3;
        }
        if(a[2][1]==1)
        {
            b3=1;
        }
        if(a[2][2]==1)
        {
            b3=2;
        }
        if(a[2][3]==1)
        {
            b3=3;
        }
        //----------------
        if(a1==b1)
        {
            cout<<a1<<" "<<b1;
        }
        if(a1==b2)
        {
            cout<<a1<<" "<<b1;
        }
        if(a1==b3)
        {
            cout<<a2<<" "<<b2;
        }
    }
}