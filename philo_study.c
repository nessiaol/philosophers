#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

// creo un nuovo tipo per passare dei dati ai thread
typedef struct _tdata {
    int             index;      // thread index
    int             *comdata;   // dato comune ai thread
    pthread_mutex_t *lock;      // mutex comune ai thread
} tdata;

// prototipi locali
void* tMyThread(void *arg);

// funzione main()
int main(int argc, char* argv[])
{
    int error;

    // init mutex
    pthread_mutex_t lock;
    if ((error = pthread_mutex_init(&lock, NULL)) != 0) {
        printf("%s: non posso creare il mutex (%s)\n", argv[0],  strerror(error));
        return 1;
    }

    // init threads
    pthread_t tid[2];
    tdata     data[2];
    int       comdata = 0;
    for (int i = 0; i < 2; i++) {
        // set data del thread e crea il thread
        data[i].index   = i;
        data[i].comdata = &comdata;
        data[i].lock    = &lock;
        if ((error = pthread_create(&tid[i], NULL, &tMyThread, (void *)&data[i])) != 0)
            printf("%s: non posso creare il thread %d (%s)\n", argv[0], i, strerror(error));
    }

    // join thread e cancella mutex
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);

    // exit
    printf("%s: thread terminati: comdata=%d\n", argv[0], comdata);
    return 0;
}

// thread routine
void* tMyThread(void *arg)
{
    // ottengo i dati del thread con un cast (tdata*) di (void*) arg
    tdata *data = (tdata *)arg;

    // thread loop
    printf("thread %d partito\n", data->index);
    int i = 0;
    for (;;) {
        // lock mutex
        pthread_mutex_lock(data->lock);

        // incrementa comdata
        (*data->comdata)++;

        // unlock mutex
        pthread_mutex_unlock(data->lock);

        // test counter per eventuale uscita dal loop
        if (++i >= 100) {
            // esce dal loop
            break;
        }

        // thread sleep (10 ms)
        usleep(10000);
    }

    // il thread esce
    printf("thread %d finito\n", data->index);
    return NULL;
}
