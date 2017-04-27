#include <pthread.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

#define NUM_THREADS	5

using namespace std;

void *PTHprint(void *threadid)
{
    long tid;
    tid = (long) threadid;
    //usleep((5-tid)*1000000);
    cout << "Soy el thread #" << tid << endl;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
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