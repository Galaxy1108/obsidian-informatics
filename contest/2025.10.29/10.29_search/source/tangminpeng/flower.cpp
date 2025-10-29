#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
char ch[50][20];
int n;
int a[100];
int b[100];
int flag=0;
inline void dfs(int now,int shu)
{
	register int i;
  while(a[now])now++;
  if(now==shu+shu+1){
		//	for(i=1;i<=shu+shu;i++)
		//printf("%d\n",i);
		flag=1;return;
   }
	for(i=shu;i>=1;i--)
		if(b[i]==0&&a[i+now+1]==0&&i+now+1<=shu+shu)
			{b[i]=1;a[now]=i;a[i+now+1]=i;dfs(now+1,shu);if(flag)return;b[i]=0;a[i+now+1]=0;a[now]=0;}
}
void work()
{
	int l,r,i,flag;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
		scanf("%s",ch[i]);	
	// scanf("%d",&n);
  dfs(1,n);
	/*for(n=3;n<=40;n++){
		printf("n=%d\n",n);
		for(i=1;i<=n+n;i++)a[i]=0;
    for(i=1,l=1,r=2;i<=n;i++)
			{
        if(i&1)
          {a[l]=n-i+1;a[l+n-i+2]=n-i+1;}
        else {a[r]=n-i+1;a[r+n-i+2]=n-i+1;r+=2;}}
		/*for(i=1,l=1,r=n+n,flag=1;i<=n;i++)
		if(n-i+1==n-1)continue;
    else
		if(flag&1){
			a[l]=n-i+1;a[l+n-i+2]=n-i+1;l++;flag^=1;
    }
		else {a[r]=n-i+1;a[r-n+i-2]=n-i+1;r--;flag^=1;}*/
  for(i=1;i<=n+n;i++){
		printf("%s\n",ch[a[i]]);
  }
  //}
}

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	work();
  fclose(stdin);fclose(stdout);
	return 0;
}
