#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;

const int M=998244353;
int n,m,a[1000010],ans;
vi b;
map<vi,bool> mp;

void parse(int x)
{
    vector<int> t;
    for (int i=1;i<=n;i++)
    {
        if (x&1)
            t.push_back(a[i]);
        x>>=1;
    }
    if (!mp[t])
    {
        mp[t]=1;
        if (t<b)
            ans++,ans%=M;
    }
}

int main()
{
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    int x;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        b.push_back(x);
    }
    for (int i=1;i<(1<<(n+1));i++)
        parse(i);
    printf("%d\n",ans);
    return 0;
}
