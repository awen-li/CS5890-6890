#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int arry_data[] = {1,1,2,2};
void* thread_a(void* in) {
    int a  = 0;
    int rd = rand()%10;
    while (a < 10)
    {
        arry_data[0] += 1;
        arry_data[1] += 2;

        if (a == rd) arry_data[3] = 0;
        a++;
    }
    return NULL;
}

void* thread_b(void* in) {
    int b = 0;
    while (b < 10)
    {
        arry_data[2] += 1;
        arry_data[3] += 2;
        b++;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    srand(time(NULL));
   
    pthread_create(&thread1, NULL, thread_a, NULL);   
    pthread_create(&thread2, NULL, thread_b, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf ("thread_a: [0]%d [1]%d \r\n", arry_data[0], arry_data[1]);   
    printf ("thread_b: [2]%d [3]%d \r\n", arry_data[2], arry_data[3]);
    return 0;
}




