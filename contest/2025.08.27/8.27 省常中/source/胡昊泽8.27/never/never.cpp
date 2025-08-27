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
//inline void solve()
//{
//	long long pos = 0 , S = 0 , T = 0 , x = 0 , y = 0 , n = 0 ;
//	qcin>>n>>S>>T>>x>>y ;
//	pos = S ;
//	long long now = 0 ;
//	while(true)
//	{
//		if(now == n)
//			break ;
//		if(pos >= T)
//		{
//			if(now + (pos - T) / x + 1 > n)
//				pos -= x * (n - now) , now = n ;
//			else
//				now += (pos - T) / x + 1 , pos -= x * ((pos - T) / x + 1) ;
//		}
//		else
//		{
//			if(now + ((T - pos) % y ? (T - pos) / y + 1 : (T - pos) / y) > n)
//				pos += y * (n - now) , now = n ;
//			else
//				now += ((T - pos) % y ? (T - pos) / y + 1 : (T - pos) / y) , pos += y * ((T - pos) % y ? (T - pos) / y + 1 : (T - pos) / y) ;
//		}
//	}
//	qcout<<pos<<'\n' ;
//}
long long n = 0 , S = 0 , lim = 0 , x = 0 , y = 0 ;
//long long get(long long pos , long long st)
//{
//	if(st == 1)
//		return pos < lim ? pos + y : pos - x ;
//	return get(get(pos , st / 2) , st - st / 2) ;
//}
long long B = 0 ;
long long get(long long pos , long long st)
{
	if(st <= B)
	{
		long long now = 0 ;
		while(now < st)
		{
			pos = pos < lim ? pos + y : pos - x ;
			++now ;
		}
		return pos ;
	}
	return get(get(pos , st / 2) , st - st / 2) ;
}
inline void solve()
{
	qcin>>n>>S>>lim>>x>>y ;
	B = sqrt(n) ;
	if(x > 1e4 && y > 1e4)
	{
		qcout<<get(S , n)<<'\n' ;
		return ;
	}
	long long now = 0 , pos = S ;
	while(true)
	{
		if(now == n)
			break ;
		if(pos >= lim)
		{
			if(now + (pos - lim) / x + 1 > n)
				pos -= x * (n - now) , now = n ;
			else
				now += (pos - lim) / x + 1 , pos -= x * ((pos - lim) / x + 1) ;
		}
		else
		{
			if(now + ((lim - pos) % y ? (lim - pos) / y + 1 : (lim - pos) / y) > n)
				pos += y * (n - now) , now = n ;
			else
				now += ((lim - pos) % y ? (lim - pos) / y + 1 : (lim - pos) / y) , pos += y * ((lim - pos) % y ? (lim - pos) / y + 1 : (lim - pos) / y) ;
		}
	}
	qcout<<pos<<'\n' ;
	return ;
}
int main()
{
	File("never") ;
	int T = 0 ;
	qcin>>T ;
	while(T--)
		solve() ;
	return 0 ;
}
