#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int n0=0,n1=0;
int a[1000100];
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
        {
            n0++;
        }
        else
        {
            n1++;
        }
    }
}