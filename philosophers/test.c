//thread
#include <pthread.h> //pthread_create(), pthread_join(), pthread_self()
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//쓰레드에서 사용할 함수
void *t_function(void *data)
{
        int id;
        int i = 0;

        id = *((int *)data);

        while(1)
        {
                //thread 식별자 출력,
                printf("(%lu) %d : %d\n", pthread_self(), id, i);
                i++;
                if(i==5)
                return (void *)i;
                sleep(1);
        }
}

void *t_function2(void *data)
{
        int id;
        int i = 0;

        id = *((int *)data);

        while(1)
        {
                //thread 식별자 출력,
                printf("(%lu) %d : %d\n", pthread_self(), id, i);
                i++;
                if(i==7)
                return (void *)i;
                sleep(1);
        }
}

int main(void)
{
        pthread_t p_thread[2]; //thread ID 저장할 변수 2개
        int thr_id; //thread generation error check
        int status; //thread 종료시 반환하는 값 저장 변수
        int a = 1; //쓰레드 함수 인자
        int b = 2; //쓰레드 함수 인자

        //thread1 generation
        thr_id = pthread_create(&p_thread[0], NULL, t_function2, (void *)&a);
        if(thr_id < 0)
        {
                perror("thread create error : ");
                exit(0);
        }

        //thread2 generation
        thr_id = pthread_create(&p_thread[1], NULL, t_function, (void *)&b);
        if(thr_id < 0)
        {
                perror("thread create error : ");
                exit(0);
        }

        //thread1이 종료될 때까지 main함수 종료를 기다린다. thread1이 종료시 반환하는 값 받는다.
        //thread2가 종료될  때까지 mian함수 종료를 기다린다. thread2가 종료시 반환하는 값 받는다.

		for (int k = 0; k < 2; k++)
		{
			pthread_join(p_thread[k], (void **)&status);
			printf("return thread %d %d\n", k ,status);
		}
        return 0;
}