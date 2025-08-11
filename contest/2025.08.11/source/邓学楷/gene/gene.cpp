#include <cstdio>

const int N=1000000;
int n,l,r,s[N+10];

bool check(int x,int y)
{
	if (s[x]==s[y])
		return 0;
	for (int i=y-1;i>0;i--)
		if (i!=x && s[i]==s[x])
			return 0;
	for (int i=x+1;i<=n;i++)
		if (i!=y && s[i]==s[y])
			return 0;
	return 1;
}

int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	scanf("%d%d%d",&n,&l,&r);
	for (int i=1;i<=n;i++)
		scanf("%d",s+i);
	for (int len=l-r+3;len<=n;len++)
		for (int i=r-len+2;i<l;i++)
		{
			if (check(i,i+len-1))
			{
				printf("%d\n",len);
				return 0;
			}
		} 
	printf("-1\n");
	return 0;
}
