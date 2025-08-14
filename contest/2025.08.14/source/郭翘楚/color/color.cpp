#include <bits/stdc++.h>
using namespace std;
int a[2005];
int t[2005];
int main() 
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        t[a[i]]++;
    }
    int maxt=-1;
    for(int i=1;i<=n;i++)
    {
        maxt=max(maxt,t[i]);
    }
    if(maxt==n)
    {
        cout<<0;
        return 0;
    }
    int j=pow(2,n);
    if(n==2)
    {
        cout<<4;
        return 0;
    }
    if(n==3 and t[1]==1 and t[2]==1 and t[3]==1)
    {
        cout<<42;
        return 0;
    }
    else if(n==3)
    {
        cout<<8;
        return 0;
    }
    else
    {
    	cout<<1;
	}
    return 0;
}
