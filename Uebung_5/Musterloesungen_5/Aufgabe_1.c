#include <stdio.h>

int main (void) {
	char c = 'T', d = 'S';
	char *p1 = &c;
	char *p2 = &d;
	char *p3 ;

	p3 = &d;
	printf("%c", *p3);
	p3 = p1;
	printf("%c", *p3);

	*p1 = *p2;
	printf("%c", *p1);
}
