#include <cstdio>
using ld=double;

int bb,ww;
ld ans[1010][1010];

ld dfs(ld b,ld w)
{
    if (ans[(int)b][(int)w]!=-1)
        return ans[(int)b][(int)w];
    ld x=0;
    if (w==0)
        x=0;
    else if (b==0)
        x=1;
    else if (b==1)
        x=w/(w+b);
    else
    {   
        x+=w/(b+w); // a white
        if (b>=3)
            x+=(b/(b+w))*((b-1)/(b+w-1))*((b-2)/(b+w-2))*dfs(b-3,w); // a black, b black, black run
        x+=(b/(b+w))*((b-1)/(b+w-1))*(w/(b+w-2))*dfs(b-2,w-1); // a black, b black, white run
    }
    ans[(int)b][(int)w]=x;
    return x;
}

int main()
{
    freopen("mouse.in","r",stdin);
    freopen("mouse.out","w",stdout);
    scanf("%d%d",&ww,&bb);
    for (int i=0;i<=bb;i++)
        for (int j=0;j<=ww;j++)
            ans[i][j]=-1.0;
    printf("%.9lf\n",dfs(bb,ww));
    return 0;
}