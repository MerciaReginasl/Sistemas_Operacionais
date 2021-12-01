#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

const clock_t MAXDELAY = 2000000;
const char *FIRST = "first thread";
const char *SECOND = "second thread";

void delay(clock_t ticks) { /* a "busy" delay */
	clock_t start = clock();
	do
		; while (clock() < start + ticks);
}

void * adjustX(void *n)
{  
	int i = (int)n;
	int x = 50;
	while (1)   /* loop forever */
	{
		printf("%s: %i\n", i == 1 ? FIRST : SECOND, x);
		x += i;
		delay(rand()%MAXDELAY);
	}
	return(n);
}

main()
{  int a;
	srand(time(NULL));
	pthread_t  up_thread, dn_thread;

	pthread_attr_t *attr;  /* thread attribute variable */
	attr=0;  

	printf("creating threads:\n");
	pthread_create(&up_thread,attr, adjustX, (void *)1);
	pthread_create(&dn_thread,attr, adjustX, (void *)-1);

	while (1) /* loop forever */
	{ ;} 
}
