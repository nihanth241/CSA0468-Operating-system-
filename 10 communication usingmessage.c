#include <stdio.h>
#include <string.h>

struct message
{
    char text[100];
};

int main()
{
    struct message msg;

    printf("Enter Message: ");
    fgets(msg.text, sizeof(msg.text), stdin);

    printf("\nMessage Sent Successfully\n");

    printf("\nMessage Received:\n");
    printf("%s", msg.text);

    return 0;
}