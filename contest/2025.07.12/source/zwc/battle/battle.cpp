#include<bits/stdc++.h> 
using namespace std;
//#define int long long
#define lb(x) (x&(-x))
#define ls(x) t[x].ls
#define rs(x) t[x].rs
#define pii pair<int,int>
#define mpr make_pair
const int N=1.5e5+5,inf=1e9;

int read(){
	int ans=0;
	char c=getchar();
	bool f=0;
	for(;!isdigit(c);c=getchar())if(c=='-')f=1;
	for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
	return f?-ans:ans;
}

void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10|48);
}
bool x;
int n,t[N],vn,ans,tot,mx;
int ymi[N],zmx[N];
struct node{
    int x,y,z;
    bool operator<(const node &n1)const{
        return x<n1.x;
    }
}a[N];
vector<int> nums;
unordered_map<int,int> ma;

void add(int x,int v){
    ///cout<<" /add x:"<<x<<endl;
    while(x<=vn){
        t[x]=max(t[x],v);
        x+=lb(x);
    }
}

int sum(int x){
    //cout<<" /sum x:"<<x<<endl;
    int ans=-inf;
    while(x){
        ans=max(ans,t[x]);
        x-=lb(x);
    }
    return ans;
}


signed main(){
    freopen("battle.in","r",stdin);
    freopen("battle.out","w",stdout);
    n=read();ans=-inf;
    nums.push_back(0);
    for(int i=1;i<=n;++i){
        a[i].x=read();a[i].y=read();a[i].z=read();t[i]=-inf;
        nums.push_back(a[i].y);mx=max(mx,max(a[i].x,max(a[i].y,a[i].z)));
    }
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    vn=nums.size()-1;
    for(int i=1;i<=vn;++i){
        ma[nums[i]]=i;
    }
    sort(a+1,a+n+1);
    if(n<=4000){
        for(int i=2,j=1;i<=n;++i){
            //cout<<" i:"<<i<<" j:"<<j<<" x:"<<a[i].x<<" y:"<<a[i].y<<" z:"<<a[i].z<<endl;
            while(j<=n&&a[j].x<a[i].x){
                //cout<<" j:"<<j<<" y:"<<a[j].y<<endl;
                add(ma[a[j].y],a[j].z);
                ++j;
            }
            for(int k=1;k<=j;++k){
                if(a[k].y>a[i].y){
                    int v=sum(ma[a[k].y]-1);
                    //cout<<" i:"<<i<<" k:"<<k<<" y:"<<a[k].y<<" v:"<<v<<endl;
                    if(v>max(a[x].z,a[k].z))ans=max(ans,v+a[i].x+a[k].y);
                }
            }
        }
        if(ans<0){
            puts("-1");return 0;
        }
        print(ans);putchar('\n');
    }
    else if(mx<=4000){
        for(int i=1;i<=mx;++i)ymi[i]=inf,zmx[i]=-inf;
        for(int i=2,j=1;i<=n;++i){
            while(j<=n&&a[j].x<a[i].x){
                for(int k=a[j].y;k<=mx;++k)zmx[k]=max(zmx[k],a[j].z);
                ymi[a[j].y]=min(ymi[a[j].y],a[j].z);
                ++j;
            }
            for(int k=a[i].y+1;k<=mx;++k){
                int v=zmx[k];
                if(v>ymi[k]){
                    //cout<<" i:"<<i<<" x:"<<a[i].x<<" y:"<<k<<" z:"<<v<<endl;
                    ans=max(ans,v+a[i].x+k);
                }
            }
        }
        if(ans<0){
            puts("-1");return 0;
        }
        print(ans);putchar('\n');
    }
    else puts("-1");
    return 0;
}