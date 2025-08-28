#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std ;
#define File(s) freopen(s".in" , "r" , stdin) , freopen(s".out" , "w" , stdout)
namespace IO
{
	#define isdigit(ch) (ch >= '0' && ch <= '9')
	#define SIZE (1 << 16)
	namespace Read
	{
		char buf[SIZE] , *_now = buf , *_end = buf ;
		inline char getchar()
		{
			if(_now == _end)
			{
				_now = _end = buf ;
				_end += fread(buf , 1 , SIZE , stdin) ;
				if(_now == _end)
					return EOF ;
			}
			return *(_now++) ;
		}
		template<typename T>
		inline void read(T& w)
		{
			w = 0 ;
			short f = 1 ;
			char ch = getchar() ;
			while(!isdigit(ch))
			{
				if(ch == '-')
					f = -1 ;
				ch = getchar() ;
			}
			while(isdigit(ch))
				w = (w << 1) + (w << 3) + (ch ^ 48) , ch = getchar() ;
			w *= f ;
		}
		#define sb(ch) (ch == ' ' || ch == '\n' || ch == '\r')
		inline void read(char& c)
		{
			char tmp = getchar() ;
			while(sb(tmp))
				tmp = getchar() ;
			c = tmp ;
		}
		inline void read(char* s)
		{
			char ch = getchar() ;
			while(sb(ch) && ch != EOF)
				ch = getchar() ;
			int len = 0 ;
			while(!sb(ch) && ch != EOF)
				s[len++] = ch , ch = getchar() ;
			s[len] = '\0' ;
		}
		inline void read(string& s)
		{
			s.clear() ;
			char ch = getchar() ;
			while(sb(ch) && ch != EOF)
				ch = getchar() ;
			while(!sb(ch) && ch != EOF)
				s.push_back(ch) , ch = getchar() ;
		}
		class qistream
		{
			public:
			template<typename T>
			inline qistream& operator>>(T& a)
			{
				read(a) ;
				return *this ;
			}
			inline qistream& operator>>(char* s)
			{
				read(s) ;
				return *this ;
			}
		} qcin ;
	}
	namespace Write
	{
		#define SIZE (1 << 16)
		char buf[SIZE] , *p = buf ;
		inline void flush()
		{
			fwrite(buf , 1 , p - buf , stdout) ;
			p = buf ;
		}
		inline void putchar(char ch)
		{
			if(p == buf + SIZE)
				flush() ;
			*p = ch ;
			++p ;
		}
		class Flush{public:~Flush(){flush() ;};}_;
		template<typename T>
		inline void write(T x)
		{
			char st[50] ;
			int len = 0 ;
			if(x < 0)
				putchar('-') , x = -x ;
			do
			{
				st[++len] = x % 10 + '0' ;
				x /= 10 ;
			} while(x) ;
			while(len)
				putchar(st[len--]) ;
		}
		inline void write(char c)
		{
			putchar(c) ;
		}
		inline void write(const char* s)
		{
			int siz = strlen(s) ;
			for(int i = 0 ; i < siz ; ++i)
				putchar(s[i]) ;
		}
		inline void write(char* s)
		{
			int siz = strlen(s) ;
			for(int i = 0 ; i < siz ; ++i)
				putchar(s[i]) ;
		}
		inline void write(string& s)
		{
			int siz = s.size() ;
			for(int i = 0 ; i < siz ; ++i)
				putchar(s[i]) ;
		}
		class qostream
		{
			public:
			template<typename T>
			inline qostream& operator<<(T x)
			{
				write(x) ;
				return *this ;
			}
			inline qostream& operator<<(const char* s)
			{
				write(s) ;
				return *this ;
			}
		} qcout ;
	}
	using Read::qcin ;
	using Write::qcout ;
}
using namespace IO ;
// 对于同一段区间而言，如果开始所拥有的钱越多，那么显然最后的钱也是单调不降的
// 所以对于一段区间而言，其最终的钱数与开始的钱数所成关系是一个分段函数
// 考虑线段树暴力维护该分段函数
// 直接求出左儿子每一段对应的末状态钱数，双指针维护其对应的右儿子的段
// 对于一段区间，其段数就是其区间长度的级别，合并时可用双指针做到线性
// 查询时遍维护当前钱数v，二分找到v对应的段求然后出这个区间结束后的新的钱数
#define pii pair<int , int>
using namespace std ;
constexpr int inf = 998244353 ;
int n = 0 , m = 0 , a[500005] = {} ;
vector<pii> tree[500005 << 2] ;
#define mid (curl + curr >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)
void pushup(int now)
{
    int pos = 0 ;
	for(int i = 0 ; i < tree[ls].size() ; ++i)
	{
        int l = tree[ls][i].first , r = (i == tree[ls].size() - 1 ? inf : tree[ls][i + 1].first - 1) ;
        int del = tree[ls][i].second ;
        int vl = l + del , vr = r + del ;
        while(pos < tree[rs].size() - 1 && tree[rs][pos + 1].first <= vr)
		{
			tree[now].emplace_back(l , del + tree[rs][pos].second) , l = tree[rs][pos + 1].first - del ;
            ++pos ;
        }
		tree[now].emplace_back(l , del + tree[rs][pos].second) ;
    }
}
void build(int now , int curl = 1 , int curr = n)
{
    if(curl == curr)
	{
		if(a[curl] > 0)
			tree[now].emplace_back(0 , 1) ;
        tree[now].emplace_back(a[curl] , 0) ;
        tree[now].emplace_back(a[curl] + 1 , -1) ;
        return ;
    }
    build(ls , curl , mid) ;
	build(rs , mid + 1 , curr) ;
    pushup(now) ;
}
int query(int now , int l , int r , int v , int curl = 1 , int curr = n)
{
    if(l <= curl && r >= curr)
	{
        int pos = upper_bound(tree[now].begin() , tree[now].end() , make_pair(v , inf)) - tree[now].begin() - 1 ;
        return v + tree[now][pos].second ;
    }
    int ans = v ;
    if(l <= mid)
		ans = query(ls , l , r , ans , curl , mid) ;
    if(r > mid)
		ans = query(rs , l , r , ans , mid + 1 , curr) ;
    return ans ;
}
int main()
{
	File("thief") ;
	qcin>>n>>m ;
    for(int i = 1 ; i <= n ; ++i)
    	qcin>>a[i] ;
    build(1) ;
    int x = 0 , y = 0 , v = 0 ;
    while(m--)
	{
        qcin>>x>>y>>v ;
        qcout<<query(1 , x , y , v)<<'\n' ;
    }
    return 0 ;
}
