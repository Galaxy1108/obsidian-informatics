#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n,s,t,x,y;
signed main()
{
    freopen("never.in","r",stdin);
    freopen("never.out","w",stdout);
    cin>>T;
    if(T<=5)
    {
        while(T--)
        {
            cin>>n>>s>>t>>x>>y;
            int p=s;
            for(int i=1;i<=n;i++)
            {
                if(p>=t)
                {
                    p-=x;
                }
                else
                {
                    p+=y;
                }
            }
            cout<<p<<endl;
        }
    }
    else
    {
        while(T--)
        {
            cin>>n>>s>>t>>x>>y;
            if(x==y)
            {
                if(s<t)
                {
                    int p=ceil(1.0*(t-s)/x);
                    int k1=s+p*x;
                    int k2=k1-y;
                    if((n-p)%2==0)
                    {
                        cout<<k1<<endl;
                        continue;
                    }
                    else
                    {
                        cout<<k2<<endl;
                        continue;
                    }
                }
                if(s==t)
                {
                    if(n%2==0)
                    {
                        cout<<s<<endl;
                        continue;
                    }
                    else
                    {
                        cout<<s-x<<endl;
                        continue;
                    }
                }
                if(s>t)
                {
                    int p=ceil(1.0*(s-t)/x);
                    int k1=s-p*x;
                    int k2=k1+y;
                    if((n-p)%2==0)
                    {
                        cout<<k1<<endl;
                        continue;
                    }
                    else
                    {
                        cout<<k2<<endl;
                        continue;
                    }
                }
            }
            else
            {
                int num=n,p=s;
                while(num)
                {
                    if(p==t)
                    {
                        num--;
                        p-=x;
                        continue;
                    }
                    if(p<t)
                    {
                        int mo=ceil(1.0*(t-p)/y);
                        if(num<mo)
                        {
                            p+=num*y;
                            num=0;
                        }
                        else
                        {
                            p+=mo*y;
                            num-=mo;
                        }
                        continue;
                    }
                    if(p>t)
                    {
                        int mo=ceil(1.0*(p-t)/x);
                        if(num<mo)
                        {
                            p-=num*x;
                            num=0;
                        }
                        else
                        {
                            p-=mo*x;
                            num-=mo; 
                        }
                        continue;
                    }
                }
                cout<<p<<endl;
                continue;
            }
        }
    }
}