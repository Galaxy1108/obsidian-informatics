#include <bits/stdc++.h>
using namespace std;
int s[1000005],tr[1000005],tl[1000005];
int main()
{
    freopen("gene.in","r",stdin);
    freopen("gene.out","w",stdout);
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=r;i++)
    {
        tl[s[i]]++;
    }
    for(int i=l;i<=n;i++)
    {
        tr[s[i]]++;
    }
    int ans=0x3f3f3f3f;
    int le=l-1;
    int minr=-1;
    for(;le>=1;le--)
    {
        tr[s[le]]++;
        if(tl[s[le]]==1)
        {
            tl[s[le]]++;
            for(int ri=r+1;ri<=n and ri-le+1<ans;ri++)
            {
                if(tr[s[ri]]==1 and s[le]!=s[ri])
                {
                    ans=ri-le+1;
                    break;
                }
            }
        }
        
    }
    if(ans==0x3f3f3f3f or ans<=0)
    {
        cout<<-1;
        return 0;
    }
    cout<<ans;
}
// #include <bits/stdc++.h>
// using namespace std;
// int s[1000005];
// int b[1000005];
// int n;
// bool hf(int l,int r)
// {
//     for(int i=l;i<=n;i++)
//     {
//         if(s[i]==s[r] and i!=r)
//         {
//             return false;
//         }
//     }
//     for(int i=r;i>=1;i--)
//     {
//         if(s[i]==s[l] and i!=l)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// int main() 
// {
//     freopen("gene.in","r",stdin);
//     freopen("gene.out","w",stdout);
//     int l,r;
//     cin>>n>>l>>r;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>s[i];
//     }
//     int ans=1e9;
//     if(n>=1e5)
//     {
//         cout<<-1<<endl;
//         return 0;
//     }
//     for(int i=l;i>=1;i--)
//     {
//         for(int j=r;j<=n;j++)
//         {
//             if(hf(i,j) and s[i]!=s[j])
//             {
//                 ans=min(ans,j-i+1);
//                 break;
//             }
//         }
//     }
//     if(ans==1e9)
//     {
//         cout<<-1;
//     }
//     else
//     {
//         cout<<ans+2;
//     }
//     return 0;
// }