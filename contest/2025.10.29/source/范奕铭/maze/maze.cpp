#include<bits/stdc++.h>
using namespace std;
int N,M,X,Y;
int a[115][115];
int v[125][125],fx[5]={0,0,0,1,-1},fy[5]={0,1,-1,0,0};
struct dian{
    int x; int y;
    int length=0;
}t[100006];
int cnt=0,minn=1e7,head=1,tail;
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    cin>>N>>M>>X>>Y;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>a[i][j],v[i][j]=1e7;
    tail++; t[tail].x=1; t[tail].y=1; t[tail].length=0;
    while(head<=tail){
        if(t[head].length>minn) break;
        if(t[head].x==X&&t[head].y==Y){
            minn=t[head].length;
            cnt++;
            head++; continue;
        }
        for(int i=1;i<=4;i++){
            int tx=t[head].x+fx[i]; int ty=t[head].y+fy[i];
            if(tx>=1&&tx<=N&&ty>=1&&ty<=N)
                if(a[tx][ty]==0)
                    if(v[tx][ty]==0||v[tx][ty]>=t[head].length+1){
                        tail++; t[tail].x=tx; t[tail].y=ty; t[tail].length=t[head].length+1; v[tx][ty]=t[tail].length;
                    }
        }
        head++;
    }
    cout<<cnt;
    return 0;
}
