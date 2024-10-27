#include <stdio.h>
#include <string.h>


void readin(char *buffer, int size)
{
    char dataBuffer[32];

    printf ("Enter:");

    fgets(dataBuffer, sizeof (dataBuffer), stdin);
    memcpy (buffer, dataBuffer, size);
    
    return;
}

int main(int argc, const char * argv[]) 
{
    char buffer[16] = {0};
    char magic [64] = "***magic for security***";

    readin (buffer, sizeof (buffer));
    strcat (magic, buffer);

    printf ("magic = %s \r\n", magic);

    return 0;
}




