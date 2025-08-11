#include <bits/stdc++.h>
using namespace std;
struct node{
	int id,x,y,z;
}a[150005],b[150005],c[150005];
bool cmp1(node a,node b)
{
	return a.x>b.x;
}
bool cmp2(node a,node b)
{
	return a.y>b.y;
}
bool cmp3(node a,node b)
{
	return a.z>b.z;
}
struct st{
	int id,v;
};
int main()
{
//	freopen("w","battle1.in",stdin);
//	freopen("r","battle.out",stdout);
//5
//1 2 3
//1 2 5
//1 2 5
//6 3 5
//2 2 2

	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		a[i].id=i;
		b[i]=a[i];
		c[i]=a[i];
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp2);
	sort(c+1,c+n+1,cmp3);
	if(a[1].x==a[n-1].x||b[1].y==b[n-1].y||c[1].z==c[n-1].z){
		printf("%d",-1);
		return 0;
	}
	if((a[n-2].y==a[n-1].y&&a[n-1].y==a[n].y)||(a[n-2].z==a[n-1].z&&a[n-1].z==a[n].z))
	{
		printf("%d",-1);
		return 0;
	}
	if((b[n-2].x==b[n-1].x&&b[n-1].x==b[n].x)||(b[n-2].z==b[n-1].z&&b[n-1].z==b[n].z))
	{
		printf("%d",-1);
		return 0;
	}
	if((c[n-2].y==c[n-1].y&&c[n-1].y==c[n].y)||(c[n-2].x==c[n-1].x&&c[n-1].x==c[n].x))
	{
		printf("%d",-1);
		return 0;
	}

	int ta=1,tb=1,tc=1;
	int ans=-1;
	while(1)
	{
		if(ta==n&&tb==n||ta==n&&tc==n||tc==n&&tb==n) break;
		cout<<a[ta].id<<" "<<b[tb].id<<" "<<c[tc].id<<"\n";
		while(a[ta].id==b[tb].id)
		{
			ta++,tb++;
			if(ta>=n&&tb>=n||ta>=n&&tc>=n||tc>=n&&tb>=n) break;
		 } 
		while(a[ta].id==c[tc].id) 
		{
			ta++,tc++;
			if(ta>=n&&tb>=n||ta>=n&&tc>=n||tc>=n&&tb>=n) break;
			//cout<<a[ta].id<<" "<<c[tc].id<<"\n";
		}
		while (b[tb].id==c[tb].id) 
		{
			tb++,tc++;
			if(ta>=n&&tb>=n||ta>=n&&tc>=n||tc>=n&&tb>=n) break;
		}
		if(a[ta].x>b[tb].x&&a[ta].x>c[tc].x&&b[tb].y>a[ta].y&&b[tb].y>c[tc].y&&c[tc].z>b[tb].z&&c[tc].z>a[ta].z)
		{
			ans=max(ans,a[ta].x+b[tb].y+c[tc].z);
			break;
		}
		
		while(a[ta].x==b[tb].x)
		{
			tb++;
		}
		while(a[ta].x==c[tc].x)
		{
			tc++;
		}
		while(a[ta].y==b[tb].y)
		{
			ta++;
		}
		while(c[tc].y==b[tb].y)
		{
			tc++;
		}
		while(c[tc].z==b[tb].z)
		{
			tb++;
		}
		while(a[ta].z==c[tc].z)
		{
			ta++;
		}
	}
	
	
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1,k<=n;k++)
			{
				int xx=max(a[i].x,a[j].x);
				
			}
		 } 
	}*/
	
	printf("%d",ans);
	return 0;
 } 
