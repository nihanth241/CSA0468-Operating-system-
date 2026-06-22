#include <stdio.h>
#include <pthread.h>
#include <windows.h>

int item = 0;
int max_items = 10;

void *producer(void *arg)
{
    int i;

    for(i = 1; i <= max_items; i++)
    {
        item = i;
        printf("Produced: %d\n", item);
        Sleep(500);
    }

    return NULL;
}

void *consumer(void *arg)
{
    int i;

    for(i = 1; i <= max_items; i++)
    {
        Sleep(600);
        printf("Consumed: %d\n", i);
    }

    return NULL;
}

int main()
{
    pthread_t p, c;

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}