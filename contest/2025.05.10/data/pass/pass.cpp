#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#define vci vector<int> 
#define vcs vector<string> 
#define PII pair<int,int> 
#define PIII pair<int,PII> 
#define pb push_back
#define mp make_pair
#define FF first
#define SS second
#define ST begin()
#define ED end()
#define sqr(x) ((x)*(x))
using namespace std;

typedef long long ll;

const int N=55;
const int Q=100000;

struct point {int x,y;} a[N],b[N];

int n;
int q[Q],v[N],pre[N];
double cp,cs;
double f[N];

double dis(point a,point b) {return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
int Dis(point a,point b) {return sqr(a.x-b.x)+sqr(a.y-b.y);}
point operator-(point a,point b) {return (point){a.x-b.x,a.y-b.y};}
double operator*(point a,point b) {return a.x*b.x+a.y*b.y;}
double operator/(point a,point b) {return a.x*b.y-b.x*a.y;}

double getdr(point p,point q)
{
  double ret=1e100;
  for (int i=0;i<n;++i)
    ret<?=min(dis(p,b[i]),dis(q,b[i]));
  return ret/(ret+1);
}

double cal1(int i,int j)
{
  double dr=getdr(a[i],a[j]),ls=dis(a[i],a[j]);
  return cp*(1-sqr(ls/150))*dr;
}

double cal2(int i,int j)
{
  double dr=getdr(a[i],b[j]),ls=dis(a[i],b[j]);
  return pow(cs*dr,log(ls));
}

struct BasketballStrategy
{
  double scoreProbability(vcs A,vcs B,double C,double D)
  {
//    cout<<sqrt(-1)<<endl;
    cp=C;cs=D;
    n=A.size();
    for (int i=0;i<n;++i)
    {
      stringstream I1(A[i]);
      I1>>a[i].x>>a[i].y;
      stringstream I2(B[i]);
      I2>>b[i].x>>b[i].y; 
    }
//    cout<<cal1(0,4)<<endl;
    b[n].x=50;b[n].y=0;
    memset(f,0,sizeof f);
    f[0]=v[0]=1;
    int st=0,ed=0;
    for (;st<=ed;++st)
    {
      int i=q[st];
      for (int j=0;j<n;++j)
      {
        double w=cal1(i,j);
        if (f[i]*w>f[j])
        {
          f[j]=f[i]*w;pre[j]=i;
          if (!v[j])
          {
            v[j]=1;q[++ed]=j;
          }
        }
      }
      v[i]=0;
    }
    double ans=0;
    for (int i=0;i<n;++i)
    {
      double w=cal2(i,n);
//      cout<<f[i]<<' '<<w<<' '<<f[i]*w<<' '<<pre[i]<<endl;
      ans>?=w*f[i];
    }
    return ans;
  }
};

void work(int T)
{
  stringstream S;
  S<<T;
  string I,O;
  I="pass"+S.str()+".in";
  O="pass"+S.str()+".out";
  freopen(I.c_str(),"r",stdin);
  freopen(O.c_str(),"w",stdout);

  ios_base::sync_with_stdio(0);
  int n;
  double cp,cs;
  cin>>n>>cp>>cs;
  vcs A,B;
  for (int i=0;i<n;++i)
  {
    int x,y;
    cin>>x>>y;
    stringstream X;
    X<<x<<' '<<y;
    A.pb(X.str());
  }
  for (int i=0;i<n;++i)
  {
    int x,y;
    cin>>x>>y;
    stringstream X;
    X<<x<<' '<<y;
    B.pb(X.str());
  }
  BasketballStrategy o;
  printf("%.6lf\n",o.scoreProbability(A,B,cp,cs));
  fclose(stdin);
  fclose(stdout);
}

int main()
{
  for (int i=0;i<20;++i)
    work(i);
  return 0;
}
