#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int A[N];
int B[N];
int n,q,k;
void work()
{
    for(int a = 0;a <= 10;a++)
    {
        for(int b = 0;b <= 10;b++)
        {
            for(int c = 1;c <= 10;c++)
            {
                bool flag = 0;
                for(int i = 0;i < k;i++)
                {
                    if((a*i + b)/c != B[i]) 
                    {
                        flag = 1;
                        break;
                    }
                }
                if(!flag)
                {
                    cout<<a<<" "<<b<<" "<<c<<"\n";
                    return ;
                }
            }
        }
    }
}
void solve()
{
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>A[i];
    cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        k = r-l+1;
        for(int i = 0;i < k;i++) B[i] = A[i+l];
        work();
    }
}
int main()
{
    //system("fc d.out d1.out");
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    int T;cin>>T;
    while(T--) solve();
    return 0;
}