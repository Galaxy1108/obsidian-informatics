#include<bits/stdc++.h>
using namespace std;
const int N=1<<11;
char ch[6*N][3*N];
int m,n,cnt[20],a,b;
int h[100],num[100];
struct POS
{
	int x,y;
}pos[N][N];
void build(int x,int y,int lev)
{
	pos[m-lev+1][++cnt[m-lev+1]]={x,y};
	//cout<<"��"<<x<<' '<<y<<"�Ϸ���o"<<endl;
	ch[x][y]='o';if(lev==1) return ;
	int numm=num[lev]-num[lev-1];
	for(int i=1;i<=numm;i++) 
	{
		//cout<<"��"<<x-i<<' '<<y+i<<"�Ϸ���/"<<endl;
		//cout<<"��"<<x+i<<' '<<y+i<<"�Ϸ���\\"<<endl;
		ch[x-i][y+i]='/';
		ch[x+i][y+i]='\\';
	}
	build(x-numm-1,y+numm+1,lev-1);
	build(x+numm+1,y+numm+1,lev-1);
}
void del(int x,int y,int lev)
{
	//cout<<"��"<<x<<' '<<y<<"��ɾ��";
	if(b%2==0)
	{
		for(int i=1;i<=num[lev+1]-num[lev];i++)
			ch[x-i][y-i]=' ';
	}
	else
	{
		for(int i=1;i<=num[lev+1]-num[lev];i++)
			ch[x+i][y-i]=' ';
	}
	ch[x][y]=' ';if(lev==1) return ;
	int numm=num[lev]-num[lev-1];
	for(int i=1;i<=numm;i++) 
	{
		//cout<<"��"<<x-i<<' '<<y+i<<"�Ϸ���/";
		//cout<<"��"<<x+i<<' '<<y+i<<"�Ϸ���\\";
		ch[x-i][y+i]=' ';
		ch[x+i][y+i]=' ';
	}
	del(x-numm-1,y+numm+1,lev-1);
	del(x+numm+1,y+numm+1,lev-1);
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	cin>>m>>n;
	h[1]=1;
	h[2]=3;
	for(int i=3;i<=15;i++) h[i]=2*h[i-1];//ÿһ��ĸ߶� 
	num[1]=0;
	for(int i=2;i<=15;i++) num[i]=h[i]-i;//ÿһ��/\��������ǰ׺��
	//cout<<endl;
	build(h[m],1,m); 
	//cout<<endl;
	//for(int i=1;i<=h[m];i++,cout<<endl)
	//	for(int j=1;j<=h[m]*2-1;j++)
		//	if(!ch[j][i]) cout<<' ';
	//		else cout<<ch[j][i];
	while(n--)
	{
		cin>>a>>b;
		del(pos[a][b].x,pos[a][b].y,m-a+1);
	}
	for(int i=1;i<=h[m];i++,cout<<endl)
		for(int j=1;j<=h[m]*2-1;j++)
			if(!ch[j][i]) cout<<' ';
			else cout<<ch[j][i];
	return 0;
}
 
