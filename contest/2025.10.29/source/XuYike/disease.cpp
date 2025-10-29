// <disease.cpp> - Wed Sep 28 09:11:47 2016
// This file is created by XuYike's black technology automatically.
// Copyright (C) 2015 ChangJun High School, Inc.
// I don't know what this program is.

#include <iostream>
#include <vector>
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
const int MAXN=310;
const int MAXM=610;
const int INF=1e9;
int bt,b[MAXN],next[MAXM],to[MAXM];
inline void add(int x,int y){
    next[++bt]=b[x];b[x]=bt;to[bt]=y;
    next[++bt]=b[y];b[y]=bt;to[bt]=x;
}
int ans=INF,now=1;
int n,f[MAXN];
bool e[MAXN],p[MAXN];
void pfs(int x){
    for(int i=b[x];i;i=next[i]){
        if(to[i]==f[x])continue;
        f[to[i]]=x;
        pfs(to[i]);
    }
}
int t,q[100010];
void dfs(){
    int pos=t+1;
    for(int i=2;i<=n;i++)
        if(!e[i]&&!p[i]&&e[f[i]])q[++t]=i;
    if(now+t-pos>=ans){t=pos-1;return;}
    if(t<pos){ans=now;return;}
    for(int i=pos;i<=t;i++)e[q[i]]=1,now++;
    for(int i=pos;i<=t;i++){
        now--;e[q[i]]=0;p[q[i]]=1;
        dfs();
        now++;e[q[i]]=1;p[q[i]]=0;
    }
    for(int i=pos;i<=t;i++)e[q[i]]=0,now--;
    t=pos-1;
}
int main(){
    freopen("disease.in","r",stdin);
    freopen("disease.out","w",stdout);
    n=gi();gi();
    for(int i=1;i<n;i++)add(gi(),gi());
    pfs(1);
    e[1]=1;
    dfs();
    printf("%d",ans);
    return 0;
}
