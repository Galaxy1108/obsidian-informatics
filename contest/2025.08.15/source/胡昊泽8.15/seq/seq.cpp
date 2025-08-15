#include<iostream>
#include<cstring>
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
#define mod (998244353)
int a[1000005] = {} , b[1000005] = {} ;
long long dp[1000005] = {} ;
// dp[i]表示a数组中以i为下标的数字开头的本质不同的子序列数
int use[100005] = {} ;
int cnt[1005][1005] = {} ;
int maxx = 0 ;
int n = 0 , m = 0 ;
inline bool check(int i)
{
	for(int j = 1 ; j <= i ; ++j)
		if(use[b[j]] < cnt[i][b[j]])
			return false ;
	return true ;
}
int main()
{
	File("seq") ;
	qcin>>n ;
	for(int i = 1 ; i <= n ; ++i)
		qcin>>a[i] , maxx = max(maxx , a[i]) ;
	qcin>>m ;
	for(int i = 1 ; i <= m ; ++i)
		qcin>>b[i] ;
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= i ; ++j)
			++cnt[i][b[j]] ;
	for(int i = n ; i ; --i)
	{
		for(int j = 1  ; j <= maxx ; ++j)
			use[j] = false ;
		dp[i] = 1 ;
		for(int j = i + 1 ; j <= n ; ++j)
		{
			if(use[a[j]])
				continue ;
			(dp[i] += dp[j]) %= mod ;
			use[a[j]] = true ;
		}
	}
//	for(int i = 1 ; i <= n ; ++i)
//		qcout<<dp[i]<<' ' ;
//	qcout<<'\n' ;
	long long ans = 0 ;
	for(int i = 0 ; i < m ; ++i)
	{
		int pos = 0 ;
		for(int j = 1 ; j <= maxx ; ++j)
			use[j] = 0 ;
		while(pos <= n && !check(i))
			++use[a[++pos]] ;
		if(pos > n)
			continue ;
		(++ans) %= mod ;
		// b本身的前缀也要算上 
		for(int j = 1 ; j <= maxx ; ++j)
			use[j] = 0 ;
		for(int k = pos + 1 ; k <= n ; ++k)
		{
			if(a[k] < b[i + 1] && !use[a[k]])
			{
				(ans += dp[k]) %= mod ;
				use[a[k]] = true ;
			}
		}
	}
//	(++ans) %= mod ;
// 上面记录前缀时已经记录了一个空串，ans直接就是排名 
	qcout<<ans<<'\n' ;
	return 0 ;
}
