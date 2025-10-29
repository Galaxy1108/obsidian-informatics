// <math.cpp> - Wed Sep 28 08:11:30 2016
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
int D;
lol ans[100],ANS[100];
void tf(lol &a,lol &b){
    lol k=__gcd(a,b);
    a/=k;b/=k;
}
bool src(lol a,lol b,int d){
    if(d++==D){
        if(a)return 0;
        if(!ANS[D]||ans[D]<ANS[D])for(int i=1;i<=D;i++)ANS[i]=ans[i];
        return 1;
    }
    bool r=0;
    ans[d]=max(ans[d-1]+1,(b-1)/a+1);
    for(;;ans[d]++){
        if((D-d+1)*b<a*ans[d])break;
        lol na=a*ans[d]-b,nb=b*ans[d];
        tf(na,nb);
        r|=src(na,nb,d);
    }
    return r;
}
int main(){
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
	lol a=gi(),b=gi();
    tf(a,b);
    for(ans[0]=0;b>a*ans[0]+a;ans[0]++);
    for(D=1;;D++)
        if(src(a,b,0)){
            printf("%d\n",D);
            for(int i=1;i<=D;i++)printf("%lld ",ANS[i]);
            return 0;
        }
}
