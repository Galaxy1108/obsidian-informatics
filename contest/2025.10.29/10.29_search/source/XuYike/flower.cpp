// <flower.cpp> - Wed Sep 28 08:11:30 2016
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
const int MAXN=100001;
const int INF=1e9;
int n,a[90];
bool us[45];
char name[45][20];
void dfs(int x){
    if(x>n<<1){
        for(int i=1;i<=n<<1;i++)printf("%s\n",name[a[i]]);
        exit(0);
    }
    if(a[x]){dfs(x+1);return;}
    for(int i=n;i;i--){
        if(us[i])continue;
        if(a[x+i+1])continue;
        a[x]=a[x+i+1]=i;us[i]=1;
        dfs(x+1);
        a[x]=a[x+i+1]=0;us[i]=0;
    }
}
int main(){
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    n=gi();
    for(int i=1;i<=n;i++)scanf("%s",name[i]);
    dfs(1);
    return 0;
}
