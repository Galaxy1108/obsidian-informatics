#include <bits/stdc++.h>
using namespace std;
int n,k,tk1,tk2;
long long f[2010][20],g[2010][20],p[2010][20],q[2010][20];
int fb[2010][20],gb[2010][20];
inline void get_minf(int i,int j,long long num,int id){if(f[i][j]>num) f[i][j]=num,fb[i][j]=id;}
inline void get_ming(int i,int j,long long num,int id){if(g[i][j]>num) g[i][j]=num,gb[i][j]=id;}

vector<pair<int,int> >ans;
inline void con(int n,vector<int> &P,int nd)
{
	for(int i=0;i<n;i++) ans.push_back(make_pair(P[i],nd));
}
void solveg(int n,int k,vector<int> &P);
void solvef(int n,int k,vector<int> &P)
{
	if(n<=1) return;
	if(k==1)
	{
		for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) ans.push_back(make_pair(P[i],P[j]));
		return;
	}
	if(fb[n][k]==-1) solvef(n,k-1,P);
	else if(k==2)
	{
		int b=n/2;
		vector<int> P_;
		for(int i=0;i<b;i++) P_.push_back(P[i]);con(b,P_,P[b]),solvef(b,k,P_);
		vector<int>().swap(P_);
		for(int i=b+1;i<n;i++) P_.push_back(P[i]);con((n-1)/2,P_,P[b]),solvef((n-1)/2,k,P_);
	}
	else
	{
		int b=fb[n][k];
		vector<int> P_;
		for(int i=0;i<b;i++) P_.push_back(P[i]);con(b,P_,P[b]),solvef(b,k,P_);
		vector<int>().swap(P_);
		for(int i=1;i<=b;i++) P_.push_back(P[n-b+i-1]);con(b,P_,P[n-b-1]),solvef(b,k,P_);
		vector<int>().swap(P_);
		for(int i=b;i<=n-b-1;i++) P_.push_back(P[i]);solveg(n-2*b,k,P_);
	}
}
void solveg(int n,int k,vector<int> &P)
{
	if(n<=1) return;
	if(gb[n][k]==-1) solveg(n,k-1,P);
	int b=gb[n][k],tk1=(n-b)/(b-1),tk2=(n-b)%(b-1);

	vector<int> P_,P__;
	P_.push_back(P[0]);
	int fl=0;
	for(int i=b-1-tk2;i;i--)
	{
		vector<int>().swap(P__);
		for(int j=1;j<=tk1;j++) P__.push_back(P[fl+j]);
		con(tk1,P__,P[fl]),con(tk1,P__,P[fl+tk1+1]);
		solvef(tk1,k,P__);
		fl+=tk1+1;
		P_.push_back(P[fl]);
	}
	for(int i=tk2;i;i--)
	{
		vector<int>().swap(P__);
		for(int j=1;j<=tk1+1;j++) P__.push_back(P[fl+j]);
		con(tk1+1,P__,P[fl]),con(tk1+1,P__,P[fl+tk1+2]);
		solvef(tk1+1,k,P__);
		fl+=tk1+2;
		P_.push_back(P[fl]);
	}
	solvef(b,k-2,P_);
}

int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);

	cin>>n>>k;n+=1;
	
	for(int i=2;i<=n;i++)
	for(int j=1;j<=k;j++)
		f[i][j]=g[i][j]=p[i][j]=q[i][j]=0x3f3f3f3f;

	//init k=1
	for(int i=1;i<=n;i++)
	{
		f[i][1]=i*(i-1)/2;
		p[i][1]=f[i][1]+2*i;
		q[i][1]=f[i][1]+i;
	}
	//init k=2
	for(int i=1;i<=n;i++)
	{
		get_minf(i,2,f[i][1],-1);
		get_minf(i,2,q[i/2][2]+q[(i-1)/2][2],i/2);
		p[i][2]=f[i][2]+2*i;
		q[i][2]=f[i][2]+i;
	}
	//init k>=3
	for(int k_=3;k_<=k;k_++)
	{
		f[1][k_]=0;
		p[1][k_]=2,q[1][k_]=1;
		g[1][k_]=0; 
		for(int i=2;i<=n;i++)
		{
			//calc g
			get_ming(i,k_,g[i][k_-1],-1);

			for(int b=2;b<=i;b++)
			{
				tk1=(i-b)/(b-1);tk2=(i-b)%(b-1);
				get_ming(i,k_,f[b][k_-2]+(b-1-tk2)*p[tk1][k_]+tk2*p[tk1+1][k_],b);
			}

			//calc f
			get_minf(i,k_,f[i][k_-1],-1);

			for(int b=1;b+b<=i;b++)
				get_minf(i,k_,g[i-b-b][k_]+2*q[b][k_],b);

			p[i][k_]=f[i][k_]+2*i;
			q[i][k_]=f[i][k_]+i;
		}
	}

	printf("%lld\n",f[n][k]-(n-1));
	vector<int> P;
	for(int i=1;i<=n;i++) P.push_back(i);
	solvef(n,k,P);
	for(pair<int,int> &g:ans)
	{
		if(g.second<g.first) swap(g.first,g.second);
		if(g.second-g.first>1) printf("%d %d\n",g.first-1,g.second-1);
	}
	return 0;
}