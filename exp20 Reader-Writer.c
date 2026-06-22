#include <stdio.h>
#include <pthread.h>
#include <windows.h>

int data = 0;
pthread_mutex_t mutex;

void *writer(void *arg)
{
    int i;

    for(i = 1; i <= 5; i++)
    {
        pthread_mutex_lock(&mutex);

        data = i;
        printf("Writer writes data: %d\n", data);

        pthread_mutex_unlock(&mutex);

        Sleep(1000);
    }

    return NULL;
}

void *reader(void *arg)
{
    int i;

    for(i = 1; i <= 5; i++)
    {
        Sleep(1200);

        pthread_mutex_lock(&mutex);

        printf("Reader reads data: %d\n", data);

        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main()
{
    pthread_t r, w;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&w, NULL, writer, NULL);
    pthread_create(&r, NULL, reader, NULL);

    pthread_join(w, NULL);
    pthread_join(r, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}