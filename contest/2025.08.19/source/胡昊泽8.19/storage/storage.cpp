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
long long x[1000005] = {} , p[1000005] = {} , c[1000005] = {} , s[1000005] = {} ;
long long dp[1000005] = {} ;
int n = 0 ;
inline double X(int j)
{
	return p[j] ;
}
inline double Y(int j)
{
	return dp[j] + s[j] ;
}
inline double slope(int i , int j)
{
	return (Y(i) - Y(j)) / (X(i) - X(j)) ;
}
int h = 1 , t = 0 ;
int Q[1000005] = {} ;
int main()
{
	File("storage") ;
	qcin>>n ;
	for(int i = 1 ; i <= n ; ++i)
		qcin>>x[i]>>p[i]>>c[i] , s[i] = s[i - 1] + x[i] * p[i] , p[i] += p[i - 1] ;
	Q[++t] = 0 ;
	int j = 0 ;
	for(int i = 1 ; i <= n ; ++i)
	{
//		dp[i] = 0x3f3f3f3f3f3f3f3f ;
//		for(int j = 0 ; j < i ; ++j)
//			dp[i] = min(dp[i] , dp[j] + x[i] * (p[i] - p[j]) - (s[i] - s[j]) + c[i]) ;
//		if(p[i] - p[i - 1] == 0)
//			dp[i] = min(dp[i] , dp[i - 1]) ;
//		O(n^2)暴力
		while(h < t && slope(Q[h] , Q[h + 1]) <= x[i])
			++h ;
		j = Q[h] ;
		dp[i] = dp[j] + x[i] * (p[i] - p[j]) - (s[i] - s[j]) + c[i] ;
		if(p[i] - p[i - 1] == 0)
			dp[i] = min(dp[i] , dp[i - 1]) ;
		while(h < t && slope(Q[t - 1] , Q[t]) >= slope(Q[t - 1] , i))
			--t ;
		Q[++t] = i ;
//		O(n)单调队列斜率优化
    }
	qcout<<dp[n]<<'\n' ;
	return 0 ;
}
