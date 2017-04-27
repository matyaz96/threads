#include <pthread.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

#define NUM_THREADS	5

using namespace std;
vector<string> message;

void *PTHprint(void *threadid)
{
    long tid;
    tid = (long) threadid;
    cout << message[tid] <<endl;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    message.push_back("Thread 1");
    message.push_back("Thread 2");
    message.push_back("Thread 3");
    message.push_back("Thread 4");
    message.push_back("Thread 5");
    for(t=0; t<NUM_THREADS; t++){
        // 0 -> OK
        rc = pthread_create(&threads[t], NULL, PTHprint, (void *)t);
        if (rc){
            cout << "ERROR:"<< rc;
            exit(-1);
        }
    }

    /* Necesario al finalizar la aplicacion */
    pthread_exit(NULL);
}