#include <stdio.h>
#include <stdlib.h>


#if defined NDEBUG
    #define TRACE( format, ... )
#else
    #define TRACE( format, ... )   printf( "%s::%s(%d) " format, __FILE__, __FUNCTION__,  __LINE__, __VA_ARGS__ )
#endif


int main(){
    unsigned var = 0xdeadbeef ;
    TRACE( "var=0x%x", var ) ;
}