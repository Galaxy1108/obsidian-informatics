#include <cstdio>
#include <vector>
#include <algorithm>
using vi=std::vector<int>;

int n;

struct pmt
{
    vi dat;
    int len;
    pmt(int x):len(x){dat.resize(x);}
    pmt operator *(pmt oth)
    {
        pmt ans(len);
        for (int i=1;i<=len;i++)
            ans.dat[i-1]=oth.dat[dat[i-1]-1];
        return ans;
    }
    bool operator ==(pmt oth)
    {
        return dat==oth.dat;
    }
    pmt rev()
    {
        pmt ans(len);
        for (int i=1;i<=len;i++)
            ans.dat[dat[i-1]-1]=i;
        return ans;
    }
    void get()
    {
        for (int i=0;i<len;i++)
            scanf("%d",&dat[i]);
    }
    void output(const char txt[]="")
    {
        printf("%s",txt);
        for (int i=0;i<len;i++)
            printf("%d ",dat[i]);
        putchar('\n');
    }
};

int main()
{
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    scanf("%d",&n);
    pmt p(n),q(n),h(n);
    p.get(),q.get();
    for (int i=1;i<=n;i++)
        h.dat[i-1]=i;
    do
    {
        if (h*p*h.rev()==q)
        {
            h.output("YES\n");
            return 0;
        }
    } while (std::next_permutation(h.dat.begin(),h.dat.end()));
    puts("NO");
    return 0;
}