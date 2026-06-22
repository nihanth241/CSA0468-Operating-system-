#include <stdio.h>

int main()
{
    int n = 5;
    int i;

    for(i = 0; i < n; i++)
    {
        printf("Philosopher %d is Thinking\n", i + 1);

        printf("Philosopher %d takes Fork %d and Fork %d\n",
               i + 1, i + 1, ((i + 1) % n) + 1);

        printf("Philosopher %d is Eating\n", i + 1);

        printf("Philosopher %d puts down Fork %d and Fork %d\n",
               i + 1, i + 1, ((i + 1) % n) + 1);
    }

    return 0;
}