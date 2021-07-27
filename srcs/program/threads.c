
#include "../../includes/philo.h"

pthread_t tid[2];
int counter;
//pthread_mutex_t mymutex;
pthread_mutex_t lock;
//valori della struttura sono sballati nel thread, perchè? 


void	*trythis(t_data *data)
{
    pthread_mutex_lock(&lock);
	
	unsigned long i = 0;
    counter += 1;
	// arg = 0;
	
	printf("numero di filosofi nel thread: %d\n", data->number_of_philosophers);
	printf("numero di forchette nel thread: %d\n", data->number_of_forks);
    printf("\n Job %d has started\n", counter);
  
    for (i = 0; i < (0xFFFFFFFF); i++)
        ;
    printf("\n Job %d has finished\n", counter);
	pthread_mutex_unlock(&lock);
    return NULL;
}
  
void	ft_create_threads(t_data *data)
{
    int i = 0;
    int error;
	
	if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        exit(1);
    }
	printf("numero di forchette: %d\n", data->number_of_forks);
    while (i < 2) {
        error = pthread_create(&(tid[i]), NULL, (void *)&trythis, &data);
        if (error != 0)
            printf("\nThread can't be created");
        i++;
    }
  
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);
}


// int N=-1;

// void *PrintHello(t_data *data)
// {
// 	N++;
// 	printf("stampa a caso: %d\n", data->number_of_forks);
// 	printf("\nHello World! N=%d\n", N);
// 	pthread_exit (NULL);
// }

// void	ft_create_threads(t_data *data)
// {
// 	pthread_t *threads;
// 	int rc, t;

// 	printf("stampa a caso: %d\n", data->optional_arg);
// 	t = 0;
// 	while (t < 10)
// 	{
// 		printf("Creating thread %d\n", t);
// 		rc = pthread_create (&threads[t], NULL, PrintHello, data);
// 		if (rc)
// 		{
// 			printf("ERROR; return code from pthread_create() is %d\n",rc);
// 			exit(-1);
// 		}
// 		t++;
// 	}
// 	pthread_exit (NULL);
// }

// void *myThreadFun(t_data *data)
// {
//     sleep(1);
// 	// vargp = 0;
// 	printf("stampa a caso: %d\n", data->optional_arg);
//     printf("Printing GeeksQuiz from Thread \n");
//     return NULL;
// }
   
// void	ft_create_threads(t_data *data)
// {
//     pthread_t thread_id;
// 	printf("stampa a caso: %d\n", data->optional_arg);
//     printf("Before Thread\n");
//     pthread_create(&thread_id, NULL, myThreadFun, NULL);
//     pthread_join(thread_id, NULL);
//     printf("After Thread\n");
//     exit(0);
// }