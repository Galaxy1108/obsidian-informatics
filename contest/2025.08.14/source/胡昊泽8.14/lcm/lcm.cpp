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
long long n = 0 , mod = 0 ;
struct com
{
	__int128 a , b ;
	inline com operator*(const com& y) const
	{
		com ret ;
		ret.a = (a * y.a % mod + 2 * b * y.b % mod) % mod ;
		ret.b = (b * y.a % mod + a * y.b % mod) % mod ;
//		ret.a = (a * y.a + 2 * b * y.b) ;
//		ret.b = (b * y.a + a * y.b) ;
//		这里因为有i所以可以取模（虽然不知道为什么） ，但是lcm还是不能取模 
		return ret ;
	}
	inline void operator*=(const com& y)
	{
		*this = *this * y ;
	}
} ;
//__int128 gcd(__int128 a , __int128 b)
//{
//	return b ? gcd(b , a % b) : a ;
//}
inline __int128 gcd(__int128 a , __int128 b)
{
	__int128 tmp ;
	while(b)
	{
		tmp = b ;
		b = a % b ;
		a = tmp ;
	}
	return a ;
}
//inline __int128 qpow(__int128 a , int k)
//{
//	__int128 ret = 1 ;
//	while(k)
//	{
//		if(k & 1)
//			(ret *= a) %= mod ;
//		(a *= a) %= mod ;
//		k >>= 1 ;
//	}
//	return ret ;
//}
inline __int128 lcm(__int128 a , __int128 b)
{
//	return a * qpow(gcd(a , b) % mod , mod - 2) % mod * b % mod ;
//	lcm在取模后其本身的性质无法保证
	return a / gcd(a , b) * b ;
}
inline void solve()
{
	qcin>>n>>mod ;
	__int128 ans = 0 ;
	com now = {1 , 1} , bas = {1 , 1} ;
	__int128 Lcm = 1 ;
	for(__int128 i = 1 ; i <= n ; ++i , now *= bas)
	{
		Lcm = lcm(Lcm , now.b) ;
//		qcout<<i<<" : f = "<<now.b<<'\n' ;
		(ans += i * (Lcm % mod) % mod) %= mod ;
	}
	qcout<<ans<<'\n' ;
}
int main()
{
	File("lcm") ;
	int T = 0 ;
	qcin>>T ;
	while(T--)
		solve() ;
	return 0 ;
}
