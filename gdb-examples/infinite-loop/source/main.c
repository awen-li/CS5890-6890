#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned readin()
{
    unsigned rd = 0;

    printf (">>>enter:");
    scanf ("%u", &rd);
    
    return rd;
}

int main(int argc, const char * argv[]) 
{
    char magic [64] = "***magic for security***";
    
    srand(time(NULL));
    
    unsigned ret = readin () + rand()%4;
    ret = (ret%2)*2 + 1;

    printf ("%u\r\n", ret);
    while (ret > 0)
    {
        unsigned index = ret%sizeof (magic);
        magic [index] = '*';

        ret = ret - 2;
    }

    printf ("%s\r\n", magic);

    return 0;
}




