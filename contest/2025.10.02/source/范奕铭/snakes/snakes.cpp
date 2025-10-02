#include<bits/stdc++.h>
using namespace std;
struct dph
{
	long long hao=0;
	long long zhi=0;
	bool operator<(const dph x)const
	{
		if(zhi==x.zhi)
		{
			return hao>x.hao;
		}
		return zhi>x.zhi;
	}//小根堆 
}a[1000600];
struct dph1
{
	long long hao;
	long long zhi=0;
	bool operator<(const dph1 x)const
	{
		if(zhi==x.zhi)
		{
			return hao<x.hao;
		}
		return zhi<x.zhi;
	}
}b[1000600];//大根堆 
int c[1000600];
priority_queue<dph>p;//小 
priority_queue<dph1>q;//大 
int T;
int n1;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	cin>>n1;
	for(int i=1;i<=n1;i++)
	{
		cin>>a[i].zhi;
		a[i].hao=i;
		b[i].zhi=a[i].zhi;
		b[i].hao=i;
		p.push(a[i]);
		q.push(b[i]);
	}
/*	for(int i=1;i<=n1;i++)
	{
		cout<<p.top().hao<<" "<<p.top().zhi<<" ";
		p.pop();
	}
		for(int i=1;i<=n1;i++)
	{
		cout<<q.top().hao<<" "<<q.top().zhi<<" ";
		q.pop();
	}*/
	int cnt=0;
	while(1>0)
	{
		long long dph2=p.top().zhi;
		long long dph3=p.top().hao;
		long long dph4=q.top().zhi;
		long long dph5=q.top().hao;
		if(dph2>dph4)
		{
			cout<<n1-cnt<<endl;
			break;
		}
		if(dph2==dph4&&dph3==dph5)
		{
			cout<<n1-cnt<<endl;
			break;
		}
		p.pop();
		q.pop();
		long long dph6=dph4-dph2;
		if(dph6<p.top().zhi)
		{
			cout<<n1-cnt<<endl;
			break;
		}
		if(dph6==p.top().zhi&&dph5<p.top().hao)
		{
			cout<<n1-cnt<<endl;
			break;
		}
		dph s;
		s.hao=dph5;
		s.zhi=dph6;
		p.push(s);
		dph1 w;
		w.hao=dph5;
		w.zhi=dph6;
		q.push(w);
		cnt++;
	}
	for(int i=2;i<=T;i++)
	{
		int n;
		cin>>n;
	//	cout<<n;
		for(int j=1;j<=n;j++)
		{
			int x,y;
			cin>>x>>y;
			a[x].zhi=y;
			b[x].zhi=y;
		//	cout<<a[x].hao<<" "<<a[x].zhi<<" ";
		}
	/*	for(int j=1;j<=n;j++)
		{
			cout<<a[j].hao<<" "<<a[j].zhi<<" ";
		}*/
		while(q.size())
		{
			q.pop();
		}
		while(p.size())
		{
			p.pop();
		}
		for(int j=1;j<=n;j++)
		{
			q.push(b[j]);
			p.push(a[j]);
		}
		cnt=0;
		while(1>0)
		{
			long long dph2=p.top().zhi;
			long long dph3=p.top().hao;
			long long dph4=q.top().zhi;
			long long dph5=q.top().hao;
		//	cout<<dph3<<" "<<dph2<<" "<<dph5<<" "<<dph4<<endl;
		/*	if(q.size()==1||p.size()==1)
			{
			//	cout<<"dui"<<" ";
				cout<<n1-cnt<<endl;
				break;
			}*/
			if(dph2>dph4)
			{
		//		cout<<"shu"<<" ";
				cout<<n1-cnt<<endl;
				break;
			}
			if(dph2==dph4&&dph3==dph5)
			{
		//		cout<<"fan"<<" ";
				cout<<n1-cnt<<endl;
				break;
			}
			p.pop();
			q.pop();
		//	cout<<p.top().hao<<" "<<p.top().zhi;
			if(p.top().zhi==dph4&&p.top().hao==dph5)
			{
				while(p.size())
				{
					p.pop();
				}
			}
			long long dph6=dph4-dph2;
			if(p.size())
			{
				if(dph6<p.top().zhi)
				{
				//	cout<<p.top().zhi<<" ";
					cout<<n1-cnt<<endl;
					break;
				}
				if(dph6==p.top().zhi&&dph5<p.top().hao)
				{
				//	cout<<"af"<<" ";
					cout<<n1-cnt<<endl;
					break;
				}
			}
			dph s;
			s.hao=dph5;
			s.zhi=dph6;
			p.push(s);
			dph1 w;
			w.hao=dph5;
			w.zhi=dph6;
			q.push(w);
			cnt++;
		}
	}
	return 0;
}
