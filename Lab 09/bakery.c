#include "pthread.h" /*Importing the thread library */
#include "stdio.h"
#include "unistd.h" /*Importing POSIX Operating System API library*/
#include "string.h"
#define MEMBAR __sync_synchronize() /* memory barrier instruction*/
#define THREAD_COUNT 50
volatile int num[THREAD_COUNT]; /*volatile prevents the compiler from applying any optimizations.*/
volatile int selecting[THREAD_COUNT];
volatile int res;

void lock_thread(int thread) {
    // Before getting the ticket number
    //"selecting" variable is set  true
    selecting[thread] = 1;
    MEMBAR;
    // Memory barrier applied
    int max_num = 0;
    // Finding Maximum ticket value among current threads
    for (int i = 0; i < THREAD_COUNT; ++i)
    {
        int ticket = num[i];
        max_num = ticket > max_num ? ticket : max_num;
    }
    // Allotting new ticket value as maximum+ 1
    num[thread] = max_num + 1;
    MEMBAR;
    selecting[thread] = 0;
    MEMBAR;
    //ENTRY Section starts
    for (int other = 0; other < THREAD_COUNT; ++other)
    {
        // Applying the bakery algorithm conditions
        while (selecting[other])
        {
        }
        MEMBAR;
        while (num[other] != 0 && (num[other] < num[thread] || (num[other] == num[thread] && other < thread)))
        {
        }
    }
}
// EXIT Section
void unlock_thread(int thread)
{
    MEMBAR;
    num[thread] = 0;
}
// CRITICAL Section
void use_res(int thread)
{

    if (res != 0)
    {
        printf("The Resource was acquired by %d, but is still in-use by %d!\n",      thread, res);
    }
    res = thread;
    printf("%d is using resource...\n", thread);

    MEMBAR;
    //sleep(2);  //for the sake of running the program faster
    res = 0;
}

//Simplified function to show the implementation
void *thread_body(void *arg)
{

    long thread = (long)arg;
    lock_thread(thread);
    use_res(thread);
    unlock_thread(thread);
    return NULL;
}

int main(int argc, char **argv)
{

    memset((void *)num, 0, sizeof(num));
    memset((void *)selecting, 0, sizeof(selecting));
    res = 0;

    // Declaring the thread variables
    pthread_t threads[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; ++i)
    {
        // Creating a new thread with the function
        //"thread_body" as its thread routine
        pthread_create(&threads[i], NULL, &thread_body, (void *)((long)i));
    }
    for (int i = 0; i < THREAD_COUNT; ++i)
    {
        // Reaping the resources used by
        // all threads once their task is completed.
        pthread_join(threads[i], NULL);
    }
    return 0;
}
