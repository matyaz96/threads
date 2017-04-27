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
    usleep((tid)*1000000*NUM_THREADS);
    cout << "Soy el thread #" << tid << endl;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    int rc;
    long t;
    void* status;

    // Initialize and set thread detached attribute
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(t=0; t<NUM_THREADS; t++){
        // 0 -> OK
        rc = pthread_create(&threads[t], &attr, PTHprint, (void *)t);
        if (rc){
            cout << "ERROR:"<< rc;
            exit(-1);
        }
    }

    // Free attribute and wait for the other threads
    pthread_attr_destroy(&attr);
    for(t=0; t<NUM_THREADS; t++) {
        rc = pthread_join(threads[t], &status);
        if (rc) {
            cout << "ERROR:"<< rc;
            exit(-1);
        }
        cout << "Main: El thread "<< t << " ya termino de ejecutarse" << endl;
    }


    /* Necesario al finalizar la aplicacion */
    cout<< "Main: A punto de terminar" << endl;
    pthread_exit(NULL);
}