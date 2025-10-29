// <maze.cpp> - Wed Sep 28 08:11:30 2016
// This file is created by XuYike's black technology automatically.
// Copyright (C) 2015 ChangJun High School, Inc.
// I don't know what this program is.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long lol;
int gi(){
    int res=0,fh=1;char ch=getchar();
    while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
    if(ch=='-')fh=-1,ch=getchar();
    while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
    return fh*res;
}
const int N=20;
const int INF=1e9;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
bool mp[N][N];
int n,m,dis[N][N],cnt[N][N];
queue <pair<int,int> >q;
inline bool check(int x,int y){return x&&y&&x<=n&&y<=m&&!mp[x][y];}
int main(){
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    n=gi(),m=gi();int X=gi(),Y=gi();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)mp[i][j]=gi();
    if(mp[1][1]||mp[X][Y]){putchar('0');return 0;}
    dis[1][1]=cnt[1][1]=1;
    q.push(make_pair(1,1));
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;q.pop();
        if(x==X&&y==Y){printf("%d",cnt[x][y]);return 0;}
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(!check(a,b))continue;
            if(!dis[a][b]){dis[a][b]=dis[x][y]+1;q.push(make_pair(a,b));}
            if(dis[a][b]==dis[x][y]+1)cnt[a][b]+=cnt[x][y];
        }
    }
    putchar('0');
    return 0;
}
