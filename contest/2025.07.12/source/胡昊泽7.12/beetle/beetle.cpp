#include<iostream>
#include<cstring>
#include<cmath>
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
constexpr long long mod = 1e9 + 7 ;
int ST[2500001][22] = {} ;
int val[2500001] = {} ;
int n = 0 , k = 0 ;
int _log2[2500001] = {} ;
inline void build()
{
	for(int i = 1 , x = 0 ; i <= n ; i <<= 1 , ++x)
		for(int j = i ; j < min(n + 1 , i << 1) ; ++j)
			_log2[j] = x ;
	int lim = ceil(log2(n)) ;
	for(int i = 1 ; i <= n ; ++i)
		ST[i][0] = val[i] ;
	for(int j = 1 ; j <= lim ; ++j)
	{
		int pj = 1 << (j - 1) ;
		for(int i = 0 ; i + pj <= n ; ++i)
			ST[i][j] = max(ST[i][j - 1] , ST[i + pj][j - 1]) ;
	}
}
inline int query(int l , int r)
{
	int len = r - l + 1 ;
	int q = _log2[len] ;
	return max(ST[l][q] , ST[r - (1 << q) + 1][q]) ;
}
long long Q[2500005] = {} ;
int head = 0 , tail = 0 ;
long long pow_23[2500001] = {} ;
int main()
{
	File("beetle") ;
	qcin>>n>>k ;
	for(int i = 1 ; i <= n ; ++i)
		qcin>>val[i] ;
	pow_23[0] = 1 ;
	for(int i = 1 ; i <= n ; ++i)
		pow_23[i] = (pow_23[i - 1] * 23) % mod ;
	build() ;
	Q[head = tail = 0] = 0 ;
	long long ans = 0 ;
	int lim = 2e7 ;
	bool flag = (n * k >= lim) ;
	for(int i = 1 ; i <= n ; ++i)
	{
		long long dp = 1e18 ;
		if(tail - head + 1 > k)
			++head ;
		for(int j = head ; j <= tail ; ++j)
			dp = min(dp , Q[j] + query(j + 1 , i)) ;
		Q[++tail] = dp ;
		(ans += (dp % mod * pow_23[n - i]) % mod) %= mod ;
	}
	qcout<<ans<<'\n' ;
	return 0 ;
}
