#include <bits/stdc++.h>
#define int long long
#define N 3005
using namespace std;
int n,m,p;
//int f[2*N][N];
void qp(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=(res*a)%p;
		a=(a*a)%p;
		b>>=1;
	}
	cout<<res;
}
signed main()
{
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	cin>>n>>m>>p;
//	for(int j=0;j<=n;j++)f[0][j]=1;
//	for(int i=1;i<=2*m;i++)//�����ǲ���1��ż���ǲ���2 
//	{
//		if(i&1)//ע�Ȿ��ʣ��Ӧ����1 
//		{
//			//�Ӻ���ȡһ��//
//			for(int j=0;j<n;j++)
//			{
//				f[i][j]=(f[i-1][j+1]+f[i-1][j])%p;//�����ȡ�ڻ�ȡ��ת�� 
//			}
//		}
//		else
//		{
//			//��λ���ȡ���ټ���
//			f[i][0]=f[i-1][0];
//			for(int j=1;j<=n;j++)
//			{
//				//ȡ������ע�⵽��һ��״̬j����Ϊn-1 
//				f[i][j]=(f[i-1][j-1]+f[i-1][j])%p;//����ܹ���������κ�������Ҫô����Ҫô���� 
////				//ȡ������
////				f[i][j]=f[i][j]+;//ƾ�ռӺڻ��//����õ�����ĺھͼ�һ���׽�����//��֮//��κ���������Ȼ��������� ��ò�Ʋ��ùܣ��� 
//			}
//		}
//	}
//	int ans=0;
//	for(int j=0;j<=n;j++)ans=(ans+f[2*m][j])%p;
//	cout<<ans;
	qp(2,min(m+n,2*m));
	return 0;
}
