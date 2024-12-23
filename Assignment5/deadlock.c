#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *function1();
void *function2();
pthread_mutex_t res_a;
pthread_mutex_t res_b;

int main()
{
	pthread_mutex_init(&res_a, NULL);
	pthread_mutex_init(&res_b, NULL);
	pthread_t one, two;

	pthread_create(&one, NULL, function1, NULL);
	pthread_create(&two, NULL, function2, NULL);
	pthread_join(one, NULL);
	pthread_join(two, NULL);

	printf("Thread joined\n");
}
void *function1()
{
	pthread_mutex_lock(&res_a);\
	printf("Thread ONE acquired res_a\n");
	sleep(1);

	pthread_mutex_lock(&res_b);
	printf("Thread ONE aqcuired res_b\n");

	pthread_mutex_unlock(&res_a);
	printf("Thread ONE released res_a\n");

	pthread_mutex_unlock(&res_b);
	printf("Threaed ONE released res_b\n");

}

void *function2()
{
	pthread_mutex_lock(&res_a);
	printf("Thread TWO acquired res_a\n");
	sleep(1);

	pthread_mutex_lock(&res_b);
	printf("Thread TWO acquired res_b\n");

	pthread_mutex_unlock(&res_a);
	printf("Threaed TWO released res_a\n");

	pthread_mutex_unlock(&res_b);
	printf("Thread TWO released res_b\n");
}
