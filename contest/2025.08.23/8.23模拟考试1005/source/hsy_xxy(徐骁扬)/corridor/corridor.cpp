#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
struct czs{
	int son[2],fa,num;
}s[400010];
int cnt;
struct Spl{
	int rt;
	void show(int x)
	{
		if(x==0) return;
		printf("%d %d %d %d\n",x,s[x].num,s[x].son[0],s[x].son[1]);
		printf("ls:\n");
		show(s[x].son[0]);
		printf("rs:\n");
		show(s[x].son[1]);
		return;
	}
	bool be_lson(int x){return x==s[s[x].fa].son[0];}
	void rotate(int x)
	{
		int y=s[x].fa,z=s[s[x].fa].fa,chk=be_lson(x);
		if(z) s[z].son[!be_lson(y)]=x;s[x].fa=z;
		s[y].son[!chk]=s[x].son[chk],s[s[x].son[chk]].fa=y;
		s[x].son[chk]=y,s[y].fa=x;
		return;
	}
	void Splay(int x,int gl)
	{
		for(int k=s[x].fa;k!=gl;rotate(x),k=s[x].fa)
			if(s[k].fa!=gl) rotate(be_lson(k)==be_lson(x)?x:k);
		if(gl==0) rt=x;
		return;
	}
	int get_bik(int k)
	{
		int con=rt,rem=0;
		while(con)
		{
			if(s[con].num<k) con=s[con].son[1];
			else if(s[con].num==k) break;
			else rem=con,con=s[con].son[0];
		}
		if(con) rem=con;
		return Splay(rem,0),s[rem].num;
	}
	void emp_ri(int x)
	{
		int gl=s[x].fa;
		while(s[x].son[1]) x=s[x].son[1];
		return Splay(x,gl);
	}
	void add_num(int k)
	{
		get_bik(k);
		if(s[rt].son[0])
		{
			emp_ri(s[rt].son[0]);
			s[++cnt].fa=s[rt].son[0];
			s[cnt].num=k;
			s[s[rt].son[0]].son[1]=cnt;
		}
		else
		{
			s[++cnt].fa=rt;
			s[cnt].num=k;
			s[rt].son[0]=cnt;
		}
		return;
	}
};
Spl C[50010],R[50010];
int i,n,m,ty,q,k,op,x,y,tim;
bool dir;
int main()
{
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	ty=Qread(),n=Qread(),m=Qread(),k=Qread();
	for(i=1;i<=n;i++)
	{
		R[i].rt=++cnt;
		s[cnt].num=m+1;
	}
	for(i=1;i<=m;i++)
	{
		C[i].rt=++cnt;
		s[cnt].num=n+1; 
	}
	for(i=1;i<=k;i++)
	{
		x=Qread(),y=Qread();
		R[x].add_num(y);
		C[y].add_num(x);
	}
	q=Qread();
	while(q--)
	{
		op=Qread(),x=Qread(),y=Qread();
		if(op==1)
		{
			R[x].add_num(y);
			C[y].add_num(x);
		}
		else
		{
			tim=Qread();
			dir=(x==0);
			while(tim--)
			{
				if(dir)
				{
					x=C[y].get_bik(x+1);
					if(x==n+1) break;
				}
				else
				{
					y=R[x].get_bik(y+1);
					if(y==m+1) break;
				}
				dir=!dir;
			}
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}