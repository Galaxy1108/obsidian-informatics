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
int dp[55][205][505] = {} ;
int a[205] = {} ;
int n = 0 , m = 0 , s = 0 ;
inline int qpow(int a , int k)
{
	int ret = 1 ;
	while(k)
	{
		if(k & 1)
			(ret *= a) %= 2 ;
		(a *= a) %= 2 ;
		k >>= 1 ;
	}
	return ret ;
}
inline void solve()
{
	qcin>>m>>s>>n ;
	for(int i = 1 ; i <= n ; ++i)
		qcin>>a[i] ;
	memset(dp , 0 , sizeof dp) ;
	for(int i = 1 ; i <= m ; ++i)
		dp[1][i][a[1] * i] = 1 ;
	for(int i = 1 ; i <= n ; ++i)
		dp[i][0][0] = 1 ;
	for(int i = 2 ; i <= n ; ++i)
		for(int sum = 1 ; sum <= s ; ++sum)
			for(int k = 1 ; k <= m ; ++k)
				for(int now = 0 ; now <= k && now * a[i] <= sum ; ++now)
//					(dp[i][k][sum] += dp[i - 1][k - now][sum - now * a[i]]) %= 2 ;
//					dp[i][k][sum] += dp[i - 1][k - now][sum - now * a[i]] * qpow(k - now + 1 , now) ;
					(dp[i][k][sum] += dp[i - 1][k - now][sum - now * a[i]] * qpow(k - now + 1 , now) % 2) %= 2 ;
	qcout<<dp[n][m][s]<<'\n' ;
}
int main()
{
	File("give") ;
	int T = 0 ;
	qcin>>T ;
	while(T--)
		solve() ;
	return 0 ;
}
