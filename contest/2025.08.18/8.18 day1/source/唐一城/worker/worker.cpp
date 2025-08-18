#include <bits/stdc++.h>
using namespace std;
const int N=105;
int f[N][15][15][15];
int n,A[N],B[N],C[N];
int main()
{
    freopen("worker.in","r",stdin);
    freopen("worker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        A[i]=A[i-1],B[i]=B[i-1],C[i]=C[i-1];
        char c;
        cin>>c;
        if(c=='A')A[i]++;
        if(c=='B')B[i]++;
        if(c=='C')C[i]++;   
    }
    int sum=0;
    if(A[n])sum++;
    if(B[n])sum++;
    if(C[n])sum++;
    if(n<=10){cout<<sum;return 0;}
    memset(f,0x3f,sizeof f);
    f[10][A[10]][B[10]][C[10]]=0;
    for(int i=10;i<=n;i++)
    {
        for(int a=0;a<=10;a++)
        {
            for(int b=0;b<=10;b++)
            {
                for(int c=0;c<=10;c++)
                {
                    int ja=min(i+a,n),jb=min(i+b,n),jc=min(i+c,n);
                    f[ja][A[ja]-A[i]][b+B[ja]-B[i]][c+C[ja]-C[i]]=min(f[ja][A[ja]-A[i]][b+B[ja]-B[i]][c+C[ja]-C[i]],f[i][a][b][c]+1);
                    f[jb][a+A[jb]-A[i]][B[jb]-B[i]][c+C[jb]-C[i]]=min(f[jb][a+A[jb]-A[i]][B[jb]-B[i]][c+C[jb]-C[i]],f[i][a][b][c]+1);
                    f[jc][a+A[jc]-A[i]][b+B[jc]-B[i]][C[jc]-C[i]]=min(f[jc][a+A[jc]-A[i]][b+B[jc]-B[i]][C[jc]-C[i]],f[i][a][b][c]+1);
                }
            }
        }
    }
    int ans=INT_MAX;
    for(int a=0;a<=10;a++)
    {
        for(int b=0;b<=10;b++)
        {
            for(int c=0;c<=10;c++)
            {
                int t=0;
                if(a)t++;
                if(b)t++;
                if(c)t++;
                ans=min(ans,f[n][a][b][c]+t);
            }
        }
    }
    cout<<ans;
    return 0;
}