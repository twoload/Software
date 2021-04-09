    #include <pthread.h>  
    #include <stdio.h>  
    #include <unistd.h>  
    #include <stdlib.h>  
    #include <signal.h>  
    #include <errno.h>  
      
    void *t_function(void *data)  
    {  
            char a[100000];  
            int num = *((int *)data);  
            struct timeval tm;  
      
      
            pthread_detach(pthread_self());  
      
            printf("Thread Start\n");  
      
            tm.tv_sec = 3;  
            tm.tv_usec = 0;  
            select(0, NULL, NULL, NULL, &tm);  
      
            printf("Thread end\n");  
    }  
      
    int main()  
    {  
            pthread_t p_thread;  
            int thr_id;  
            int status;  
            int a = 100;  
      
            printf("Before Thread\n");   
            thr_id = pthread_create(&p_thread, NULL, t_function, (void *)&a);  
            if (thr_id < 0)  
            {  
                    perror("thread create error : ");  
                    exit(0);  
            }  
      
            for ( ; ; ) {  
                    struct timeval tm;  
                    tm.tv_sec = 0;  
                    tm.tv_usec = 500000;  
                    select(0, NULL, NULL, NULL, &tm);  
      
                    status = pthread_kill(p_thread, 0);  
                    if ( status == ESRCH ) {  
                            printf("Thread ID[%d] not exist..\n", p_thread);  
                            return 0;  
                    } else if ( status == EINVAL ) {  
                            printf("Thread ID[%d] is yet alive\n", p_thread);  
                    }  else {  
                            printf("Thread ID[%d] is yet alive\n", p_thread);  
                    }  
            }  
      
            return 0;  
    }  
