#include<bits/stdc++.h>
using namespace std;
int n,q;
int y[100010];
int c,a,b;
double k1;
int t;
int l,r;
bool check()
{
    for(int i=l;i<=r;i++)
    {
        int x=i-l;
        int y1=(a*x+b)/c;
        if(y1!=y[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    ios:sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
       cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>y[i];
        }
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            cin>>l>>r;
            if(l==r)
            {
                cout<<"0"<<" "<<y[l]<<" "<<"1"<<endl;
                continue;
            }
            k1=1.0*(y[r]-y[l]+1)/(r-l);
            for(int j=1;;j++)
            {
                c=j;
                int la=0,ra=c*k1,lb=c*y[l],rb=c*y[l]+c;
                for(int k=la;k<=ra;k++)
                {
                    a=k;
                    for(int p=lb;p<=rb;p++)
                    {
                        b=p;
                        if(check())
                        {
                            cout<<a<<" "<<b<<" "<<c<<endl;
                            goto mn;
                        }
                    }
                }
            } 
            mn:;
        }
        
    }
    
}