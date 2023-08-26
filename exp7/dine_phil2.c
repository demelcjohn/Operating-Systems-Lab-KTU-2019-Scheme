#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define THINKING 2
#define HUNGRY 1
#define EATING 0


int n;
sem_t S[100];
pthread_mutex_t mutex;
int state[100];
int phil[100];

void* philosopher(void*);
void take_fork(int);
void put_fork(int);
void test(int);
int left(int);
int right(int);

void main()
{
pthread_t thread_id[100];
pthread_mutex_init(&mutex, NULL);
int i;
printf("Dinning Philosophers Problem\n");
printf("Enter the number of philosophers : ");
scanf("%d",&n);
for (i=0;i<n;i++)
{
  sem_init(&S[i], 0, 0);
  phil[i] = i;
}
for (i=0;i<n;i++)
{
		pthread_create(&thread_id[i], NULL,philosopher, &phil[i]);
		printf("Philosopher %d is thinking\n", i + 1);
}
for (i=0;i<n;i++)
	pthread_join(thread_id[i], NULL);
}

void* philosopher(void* num)
{
int* i = num;
take_fork(*i);
put_fork(*i);

}

void take_fork(int phnum)
{

pthread_mutex_lock(&mutex);
state[phnum] = HUNGRY;
printf("Philosopher %d is Hungry\n", phnum + 1);
test(phnum);

pthread_mutex_unlock(&mutex);
sem_wait(&S[phnum]);

}

void put_fork(int phnum)
{
pthread_mutex_lock(&mutex);
state[phnum] = THINKING;
printf("Philosopher %d putting fork %d and %d down\n",phnum + 1, left(phnum) + 1, phnum + 1);
printf("Philosopher %d is thinking\n", phnum + 1);

test(left(phnum));
test(right(phnum));

pthread_mutex_unlock(&mutex);
}

void test(int phnum)
{
if (state[phnum] == HUNGRY && state[left(phnum)] != EATING && state[right(phnum)] != EATING)
{
	state[phnum] = EATING;
	printf("Philosopher %d takes fork %d and %d\n",phnum + 1, left(phnum) + 1, phnum + 1);
	printf("Philosopher %d is Eating\n", phnum + 1);
	sem_post(&S[phnum]);
	}
}

int left(int phnum)
{
  return (phnum + n-1) % n;
}

int right(int phnum)
{
  return (phnum + 1) % n;
}
