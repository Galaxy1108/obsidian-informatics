#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct Person{
    int h,id;
    bool operator<(const Person&rhs) const{
        if (h!=rhs.h) return h < rhs.h;
        return id < rhs.id;
    }
}P[55];
int n,ans;
int main()
{
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        P[i].id = i;
        scanf("%d",&P[i].h);
    }
    sort(P+1,P+n+1);
    for (int i=1;i<=n;i++)
        ans += abs(P[i].id - i);
    printf("%d",ans);
    return 0;
}