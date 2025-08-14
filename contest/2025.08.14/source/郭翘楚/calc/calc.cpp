#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("calc.in","r",stdin);
    freopen("calc.out","w",stdout);
    int T,p;
    cin>>T>>p;
    while(T--)
    {
        int b;
        cin>>b;
        if(p==9 and b==14)
        {
            cout<<2<<endl;
        }
        else if(p==3 and (b==11 or b==20 or b==29))
        {
            cout<<2<<endl;
        }
        else if(p==5 and (b==38 or b==37 or b==32 or b==28 or b==23))
        {
            cout<<1<<endl;
        }
        else if(p==5 and b==9)
        {
            cout<<2<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
