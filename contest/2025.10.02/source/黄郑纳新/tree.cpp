# include <iostream> 

# include <cstring> 

# include <algorithm>

# include <string>

# include <cmath>

# include <queue>

# include <stack>

# include <list>

# include <windows.h>

# include <bits/stdc++.h>

#define int long long

const long inf = 2e5 + 10 ;

int id , op , n , u [ inf ] , v [ inf ] , w [ inf ] ;

int Q , l , r , k ;

inline int solve ( int l , int r , int k , int lstans ,int testop )
 
{
	
	lstans %= 19260817 ; 
	 
	if ( testop ) {  
	 
	l ^= lstans; 
	
	l = (l % n + n) % n + 1 ; 
	  
	r ^= lstans; r = (r % n + n) % n + 1 ;
	   
	if ( l > r ) std :: swap ( l, r ) ;   
	
	k ^= lstans ;    
	
	k = ( k % std :: min ( r - l + 1 , ( int ) 100 ) ) + 1 ;
	  
	} 
	
	return k ;
	
}

inline void in1 ( ) 

{
	
	std :: cin >> id >> op >> n ;
	
	for ( int i = 1 ; i < n ; i  ++ ) 
	
	{
		
		std :: cin >> u [ i ] >> v [ i ] >> w[ i ] ;
		
	} 
	
	return ;
	
}

inline void in2 ( ) 

{
	
	std :: cin >> Q ;
	
	for ( int i = 1 ; i <= Q ; i++ ) 
	
	{
		
		std :: cin >> l >> r >> k ;
		
		std :: cout << solve ( l , r , k , rand ( ) * rand ( ) , rand ( ) * rand ( ) ) ;
		
		printf ( " \n " ) ;
		
	}
	
	return ;
	
}

signed main ( ) 

{
	
	std :: ios :: sync_with_stdio ( 0 ) ;
	
	std :: cin . tie ( 0 ) ;
	
	std :: cout . tie ( 0 ) ;
	
	freopen ( " tree.in " , " r " , stdin ) ;
	
	freopen ( " tree.out " , " w " , stdout ) ;
	
	in1 ( ) ;
	
	in2 ( ) ;
	
	fclose ( stdin ) ;
	
	fclose ( stdout ) ;
	
	return 0 ;
	
}


