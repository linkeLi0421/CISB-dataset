/*
	x86-64 clang 3.4.1-13.0.0 O0
	x86-64 gcc 4.6.4-11.2 O0
*/

#include <stdio.h>

#define AF_INET		2


struct sockaddr_in {
	int	sin_family;	
	char sin_addr;
};

struct sockaddr {
	int	sa_family;	
	char sa_data[14];	
};

union vxlan_addr {
	struct sockaddr_in sin;
	struct sockaddr sa;
};


int main(){
	union vxlan_addr ipa = {
		.sin.sin_addr = 'a',
		.sa.sa_family = AF_INET
		// .sin.sin_family = AF_INET
	};
    printf("%d\n",ipa.sin.sin_addr);
    return 0;
}