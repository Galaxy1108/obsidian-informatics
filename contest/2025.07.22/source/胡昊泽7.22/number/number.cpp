#include<iostream>
#include<cstring>
//#include<set>
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
		inline void read(char& c)
		{
			char tmp = getchar() ;
			while(tmp == ' ' || tmp == '\n')
				tmp = getchar() ;
			c = tmp ;
		}
		#define sb(ch) (ch == ' ' || ch == '\n')
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
int n = 0 , m = 0 ;
int a[300005] = {} ;
long long b[300005] = {} ;
long long ans = 0 ;
//multiset<int> num[2] , nxt_num[2] ;
//long long sum_max = 0 , sum_min = 0 ;
//int num_max = 0 , num_min = 1 ;
void dfs(int now , long long sum)
{
	if(now == m + 1)
	{
		ans = max(ans , sum) ;
		return ;
	}
	for(int i = 1 ; i <= n ; ++i)
	{
		b[i] = a[now] - b[i] ;
		dfs(now + 1 , sum + b[i] * 2 - a[now]) ;
		b[i] = a[now] - b[i] ;
	}
}
inline void solve()
{
	qcin>>n>>m ;
	for(int i = 1 ; i <= m ; ++i)
		qcin>>a[i] ;
//	num[0].clear() , num[1].clear() ;
//	for(int i = 1 ; i <= n ; ++i)
//		num[0].insert(0) , num[1].insert(0) ;
//	sum_max = 0 , sum_min = 0 ;
//	num_max = 0 , num_min = 1 ;
//	for(int i = 1 ; i <= m ; ++i)
//	{
//		auto it_max_max = --num[num_max].end() ;
//		auto it_max_min = num[num_max].begin() ;
//		auto it_min_min = num[num_min].begin() ;
//		auto it_min_max = --num[num_min].end() ;
//		long long nxt_max = max(sum_max - *it_max_min * 2 + a[i] , sum_min - *it_min_min * 2 + a[i]) ;
//		long long nxt_min = min(sum_max - *it_max_max * 2 + a[i] , sum_min - *it_min_max * 2 + a[i]) ;
//		if(nxt_max == sum_min - *it_min_min * 2 + a[i])
//		{
//			nxt_num[num_max] = num[num_min] ;
//			auto it = nxt_num[num_max].begin() ;
//			int nw = a[i] - *it ;
//			nxt_num[num_max].erase(it) ;
//			nxt_num[num_max].insert(nw) ;
//		}
//		else
//		{
//			nxt_num[num_max] = num[num_max] ;
//			auto it = nxt_num[num_max].begin() ;
//			int nw = a[i] - *it ;
//			nxt_num[num_max].erase(it) ;
//			nxt_num[num_max].insert(nw) ;
//		}
//		if(nxt_min == sum_max - *it_max_max * 2 + a[i])
//		{
//			nxt_num[num_min] = num[num_max] ;
//			auto it = --nxt_num[num_min].end() ;
//			int nw = a[i] - *it ;
//			nxt_num[num_min].erase(it) ;
//			nxt_num[num_min].insert(nw) ;
//		}
//		else
//		{
//			nxt_num[num_min] = num[num_min] ;
//			auto it = --nxt_num[num_min].end() ;
//			int nw = a[i] - *it ;
//			nxt_num[num_min].erase(it) ;
//			nxt_num[num_min].insert(nw) ;
//		}
//		sum_max = nxt_max , sum_min = nxt_min ;
//		num[num_max] = nxt_num[num_max] , num[num_min] = nxt_num[num_min] ;
//	}
//	qcout<<sum_max<<'\n' ;
	ans = 0 ;
	dfs(1 , 0) ;
	qcout<<ans<<'\n' ;
	return ;
}
int main()
{
	File("number") ;
	int T = 0 ;
	qcin>>T ;
	while(T--)
		solve() ;
	return 0 ;
}
