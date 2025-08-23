#include <cstdio>

int _,n,m,k;
bool p[5010][5010];

struct pos
{
    int x,y;
};

pos work(int x,int y,int q)
{
    int b=0,dx=(x==0),dy=(y==0),tx=x,ty=y;
    while (true)
    {
        while (!p[tx][ty])
        {
            if (tx>n)
                return {tx,ty};
            if (ty>n)
                return {tx,ty};
            tx+=dx,ty+=dy;
        }
        b++;
        if (b==q)
            break;
        if (dx==1)
            dx=0,dy=1,ty++;
        else
            dy=0,dx=1,tx++;
    }
    return {tx,ty};
}

int main()
{
    freopen("corridor.in","r",stdin);
    freopen("corridor.out","w",stdout);
    int w,x,y,q,Q;
    scanf("%d%d%d%d",&_,&n,&m,&k);
    while (k--)
    {
        scanf("%d%d",&x,&y);
        p[x][y]=1;
    }
    scanf("%d",&Q);
    while (Q--)
    {
        scanf("%d%d%d",&w,&x,&y);
        if (w==1)
            p[x][y]=1;
        else
        {
            scanf("%d",&q);
            pos t=work(x,y,q);
            printf("%d %d\n",t.x,t.y);
        }
    }
    return 0;
}