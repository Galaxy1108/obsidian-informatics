#include <bits/stdc++.h>
#define int long long
using namespace std;
int w,b;
__int128 jc[1005];
__int128 c[1005][1005];
signed main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	cin>>w>>b;
	//�趨ǰw���ǰ�ɫ����b���Ǻ�ɫ 
	__int128 wk=0;
	jc[0]=1;
	for(int i=1;i<=w+b;i++)jc[i]=jc[i-1]*i;
	for(int i=0;i<=w+b;i++)c[i][0]=1;
	for(int i=1;i<=w+b;i++)
	{ 
		for(int j=1;j<=i;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
	for(int i=1;i<=w+b;i+=3)//�ȱ�֤���� //��һ���� 
	{
		//��������֣�ֻҪ�Ǵ���i�Ķ����ԣ�С��i��֮�У�����%3==2�Ķ����� 
		__int128 sum=w+b-i+(i-1)/3;
		if(sum<w-1)continue;
		//w������
		wk+=c[sum][w-1]*jc[w];
	}
	printf("%.9f",(double)wk/jc[w+b]*jc[b]);
	return 0;
} 
