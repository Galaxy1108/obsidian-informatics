#include <cstdio>

const int p[15]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096};
const int sp[15]={1,2,5,11,23,47,95,191,383,767,1535,3071,6143};
int m,n,del[2000];

void print_dots(int l)
{
	int cur=p[l-1];
	for (int i=0;i<sp[m-l];i++)
		putchar(' ');
	for (int d=0;d<p[l-1];d++)
	{
		if (del[cur])
		{
			putchar(' ');
			del[cur*2]=1;
			del[cur*2+1]=1;
		}
		else
			putchar('o');
		cur++;
		if (d!=p[l-1]-1)
		{
			for (int i=0;i<sp[m-l+1];i++)
				putchar(' ');
		}
	}
	putchar('\n');
}

void print_slash(int l)
{
	int w=sp[m-l],s=1,cur;
	for (int i=0;i<sp[m-l-1];i++)
	{
		cur=p[l-1];
		for (int j=0;j<w-(s+1)/2;j++)
			putchar(' ');
		for (int x=0;x<p[l-1];x++)
		{
			if (del[cur*2])
				putchar(' ');
			else
				putchar('/');
			for (int j=0;j<s;j++)
				putchar(' ');
			if (del[cur*2+1])
				putchar(' ');
			else
				putchar('\\');
			cur++;
			if (x!=p[l-1]-1)
			{
				for (int j=0;j<sp[m-l+1]-s-1;j++)
					putchar(' ');
			}
		}
		s+=2;
		putchar('\n');
	}
}

void print_last_row()
{
	int cur=p[m-1];
	for (int i=0;i<p[m-2];i++)
	{
		if (del[cur])
			putchar(' ');
		else
			putchar('o');
		cur++;
		for (int j=0;j<3;j++)
			putchar(' ');
		if (del[cur])
			putchar(' ');
		else
			putchar('o');
		cur++;
		if (i!=p[m-2]-1)
			putchar(' ');
	}
	putchar('\n');
}

int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	int x,y;
	scanf("%d%d",&m,&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		del[p[x-1]+y-1]=1;
	}
	for (int l=1;l<m;l++)
	{
		print_dots(l);
		print_slash(l);
	}
	print_last_row();
	return 0;
} 
