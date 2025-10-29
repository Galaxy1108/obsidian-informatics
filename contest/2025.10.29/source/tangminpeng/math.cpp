#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 1010
using namespace std;
int n,m;
//int f[N][N],g[N][N];
//solution:diedai
int a[N];
int b[N];
int c[N];
//int flag;
int ans=0;
bool flag=false;
int bid;
inline int gcd(int x,int y)
{
  return x==0?y:gcd(y%x,x);
}
inline void dfs(register int now,register int low,register int A,register int B)
{
	//printf("dfs %d %d %d %d %d\n",now,low,dep,A,B);
			
    
  register int AA,BB,k;
	//if(low>dep)return;
  if(flag&&low>=ans)return;
  if(A==1&&b[B]==0)//the last dont need small
		{a[low]=B;flag=true;for(B=1;B<=low;B++)c[B]=a[B];
			ans=low;/*printf("change %d\n",ans);*/return;}
  
  /*if(dep==2)
		{//printf("beginty %d %d %d\n",B/A,2*now*(B/A),B);
    }*/
  for(now=max(now,B/A);now<=bid&&(!flag||(ans-low+1)*B>=A*now);now++)
		if(A*now>=B){a[low]=now;b[now]=1;
			AA=A*now-B;BB=B*now;k=gcd(AA,BB);
			//printf("choose %d %d %d %d\n",low,AA,BB,k);
      dfs(now+1,low+1,AA/k,BB/k);
			//if(flag)return;
      a[low]=0;b[now]=0;
     }
}/*
inline bool tryer(int dep)
{
	flag=0;
  //dfs(1,1,dep,n,m);//printf("try %d %d\n",dep,flag);
  if(flag)ans=dep;return flag==1;
	}*/
void work()
{
  scanf("%d%d",&n,&m);
  int i,j,k=gcd(n,m);
  n/=k;m/=k;
  if(n==1&&m==1){printf("1\n1\n");return;}//printf("n=%d m=%d\n",n,m);
  for(i=1;i<=30;i++)
		{//if(tryer(i))
			//	break;
			bid=i;dfs(1,1,n,m);
    }
  printf("%d\n",ans);
  for(j=1;j<=ans;j++)
		printf("%d ",c[j]);
}

int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	work();
  fclose(stdin);
  fclose(stdout);
	return 0;
}
