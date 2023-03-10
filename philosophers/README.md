# Philosophers

#include <pthread.h>

[Philosophers](https://brassy-plate-60f.notion.site/Philosophers-344f249d74594b5faa7b7bff819558b0)

# 핵심 포인트

- **Process & Thread**
- **Mutex & Semaphore**
- **POSIX (P**ortable **O**perating **S**ystem **I**nterface**)**
- **사용 함수들 (Not Familiar)**
**pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock, gettimeofday, usleep**
- **보너스 추가 함수들 (New)
fork, kill, exit, waitpid, sem_open, sem_close, sem_unlink, sem_post, sem_wait**

# 정리

- **Process**
    
    [https://ko.wikipedia.org/wiki/프로세스](https://ko.wikipedia.org/wiki/%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4)
    
    [https://bowbowbow.tistory.com/16](https://bowbowbow.tistory.com/16)
    
    프로세스와 프로그램의 `차이`는 정말 명확합니다. `프로그램`자체는 생명이 없습니다. 프로그램은 보조 기억장치(하드디스크, SSD)에 존재하며 실행되기를 기다리는 명령어(코드)와 정적인 데이터의 묶음입니다. 이 프로그램의 명령어와 정적 데이터가 메모리에 `적재`되면 생명이 있는 `프로세스`가 됩니다.
    
    즉 `프로세스란 실행 중인 프로그램`입니다.
    
- **Thread**
    
    [http://www.tcpschool.com/java/java_thread_concept](http://www.tcpschool.com/java/java_thread_concept)
    
    [**https://goodgid.github.io/What-is-Thread/**](https://goodgid.github.io/What-is-Thread/)
    
    스레드(thread)란 프로세스(process) 내에서 실제로 작업을 수행하는 주체를 의미합니다.
    
    - 하나의 프로세스를 구성하는 쓰레드들은 프로세스에 할당된 메모리, 자원 등을 공유한다.
    - 각 쓰레드별로 **자신만의** **스택**과 **레지스터**를 가진다.
    - 쓰레드는 프로세스의 메모리, 자원(Heap, Static, Code)등을 공유하므로 커널의 도움없이 **상호간에 통신**이 가능하다.
    - 스택은 함수 호출 시 전달되는 인자, 되돌아갈 주소값 및 함수 내에서 선언하는 변수 등을 저장하기 위해 사용되는 메모리 공간이므로 **스택 메모리 공간**이 **독립적**이라는 것은 **독립적인 함수 호출**이 가능하다는 것이고, 이는 **독립적인 실행 흐름**이 가능하게 한다.
- **Mutex**
    
    [https://heeonii.tistory.com/14](https://heeonii.tistory.com/14)
    
    상호 배제(**Mut**ual **Ex**clusion)의 줄임말. 보통 ‘뮤텍스’ 라고 이야기한다.
    
    **동기화 대상이 하나이다.**
    
    한 프로세스에 의해 소유될 수 있는 Key를 기반으로 한 상호 배제 기법이고 Key에 해당하는 어떤 객체(Object)가 있으며, 이 객체를 소유한 스레드/프로세스만이 공유자원에 접근할 수 있습니다.
    
    다중 프로세스들의 공유 리소스에 대한 접근을 조율하기 위해 동기화(Synchronization) 또는 락(Lock)을 사용함으로써 뮤텍스 객체를 두 스레드가 동시에 사용할 수 없습니다.
    
- **Semaphore**
    
    **동기화 대상이 하나 이상이다.**
    
    사용하고 있는 스레드/프로세스의 수를 공통으로 관리하는 하나의 값을 이용해 상호배제를 달성합니다.
    
    공유 자원에 접근할 수 있는 프로세스의 최대 허용치만큼 동시에 사용자가 접근할 수 있으며, 각 프로세스는 세마포어의 값을 확인하고 변경할 수 있습니다.
    
    자원을 사용하지 않는 상태가 될 때, 대기하던 프로세스가 즉시 자원을 사용하게되고, 이미 다른 프로세스에 의해 사용중이라는 사실을 알게 되면 재시도 전에 일정시간 대기해야 합니다. 일반적으로 비교적 긴 시간을 확보하는 리소스에 대해 사용하게 됩니다.
    
    [https://www.joinc.co.kr/w/Site/system_programing/IPC/semaphores](https://www.joinc.co.kr/w/Site/system_programing/IPC/semaphores)
    
- **Race condition, Data race**
    
    [https://velog.io/@xiniha/Race-Condition과-Data-Race-알아보기](https://velog.io/@xiniha/Race-Condition%EA%B3%BC-Data-Race-%EC%95%8C%EC%95%84%EB%B3%B4%EA%B8%B0)
    
- ****Pthread API 레퍼런스****
    
    [https://www.joinc.co.kr/w/Site/Thread/Beginning/PthreadApiReference](https://www.joinc.co.kr/w/Site/Thread/Beginning/PthreadApiReference)
    
    [https://sourceware.org/pthreads-win32/manual/index.html](https://sourceware.org/pthreads-win32/manual/index.html)
    
- **External functions (Mandatory)**
    - **gettimeofday**
        
        ```c
        #include <sys/time.h>
        
        int gettimeofday(struct timeval *tv, struct timezone *tz);
        
        첫번째 인자인 tv는 현재 시스템 시간을 저장하기 위한 구조체로 다음과 같이 정의되어 있다.
        struct timeval
        {
            long tv_sec;       // 초
            long tv_usec;      // 마이크로초
        }
        
        현재 timezone 구조체는 사용되지 않고 있으며, 앞으로도 지원되지 않을 것이다. 간혹 커널 소스등에서 이 필드가 사용되는 경우가 있는데, 모든 경우에 버그로 판단되어서 무시한다. 복잡하게 생각할 필요 없이 tz은 NULL을 사용하도록 한다.
        
        gettimeofday()은 time(2)와 매우 비슷하지만 마이크로초 단위의 시간 까지 되돌려준다. 현재는 time(2)를 대신해서 쓰이고 있으며, 가능한 time(2)대신 이 함수를 사용하는 걸 권장한다.
        
        성공하면 0 실패하면 -1을 리턴한다.
        ```
        
        [https://www.joinc.co.kr/w/man/2/gettimeofday](https://www.joinc.co.kr/w/man/2/gettimeofday)
        
        [https://man7.org/linux/man-pages/man2/settimeofday.2.html](https://man7.org/linux/man-pages/man2/settimeofday.2.html)
        
    - **pthread_create**
        
        ```c
        #include <pthread.h>
        
        int  pthread_create(pthread_t  *thread, pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
        
        pthread_create는 새로운 쓰레드를 생성한다. 새로운 쓰레드는 start_routine 함수를 arg 아규먼트로 실행시키면서 생성된다. 생성된 쓰레드는 pthread_exit(3) 을 호출하거나 또는 start_routine 에서 return 할경우 제거된다.
        
        attr 아규먼트는 쓰레드와 관련된 특성을 지정하기 위한용도로 사용된다. 이에 대한 내용은 pthread_attr_init(3) 을 참고해야 한다. attr 을 NULL 로 할경우 기본 특성으로 지정된다. 리눅스에서의 쓰레드는 joinable 과 non real-time 스케쥴 정책을 기본특성으로 한다.
        
        성공할경우 쓰레드식별자인 thread에 쓰레드 식별번호를 저장하고, 0을 리턴한다. 실패했을경우 0이 아닌 에러코드 값을 리턴한다.
        
        함수포인터의 인자의 함수시작 부분
        void *start_routine(void *arg) {
        }
        ```
        
        - **pthread_attr_init()**
            
            **`pthread_attr_init()`** 함수는 pthread 속성 객체(**`pthread_attr_t`**)를 초기화하는 함수입니다.
            
            ```c
            Detach state
            Scope
            Inherit scheduler 
            Scheduling policy 
            Scheduling priority 
            Guard size
            Stack address 
            Stack size
            ```
            
            pthread 속성 객체는 pthread 라이브러리를 사용하여 새로운 쓰레드를 생성할 때 사용됩니다. 쓰레드를 생성할 때 쓰레드의 동작을 제어하는 다양한 속성을 설정할 수 있습니다. 예를 들어, 쓰레드의 우선순위, 스택 크기, 스케줄링 정책 등을 설정할 수 있습니다.
            
            **`pthread_attr_init()`** 함수는 이러한 속성을 초기화하기 위해 사용됩니다. 이 함수를 호출하면, **`pthread_attr_t`** 구조체는 기본값으로 초기화됩니다. 이 구조체는 다양한 속성을 설정하는데 사용됩니다.
            
            pthread 속성 객체를 초기화한 후, **`pthread_attr_setXXX()`** 함수를 사용하여 원하는 속성을 설정할 수 있습니다. 예를 들어, **`pthread_attr_setstacksize()`** 함수를 사용하여 스택 크기를 설정할 수 있습니다.
            
            쓰레드를 생성할 때 이러한 설정된 속성 객체를 전달하여 원하는 쓰레드 동작을 지정할 수 있습니다.
            
        
        [https://www.joinc.co.kr/w/man/3/pthread_create](https://www.joinc.co.kr/w/man/3/pthread_create)
        
        [https://man7.org/linux/man-pages/man3/pthread_create.3.html](https://man7.org/linux/man-pages/man3/pthread_create.3.html)
        
    - **pthread_detach**
        
        ```c
        #include <pthread.h>
        
        int pthread_detach(pthread_t th);
        
        쓰레드 식별자 th를 가지는 쓰레드를 메인쓰레드에서 분리 시킨다. 이것은 th를 가지는 쓰레드가 종료되는 즉시 쓰레드의 모든 자원을 되돌려(free)줄 것을 보증한다. detach상태가 아닐경우 쓰레드가 종료한다고 하더라도 pthread_join(3)을 호출하지 않는 한 자원을 되돌려주지 않는다.
        
        pthread_detach()함수를 호출하는 외에도 pthread_create()시 pthread_attr_t에 detachstate를 지정해 줌으로써 detach상태로 생성할 수 도 있다. pthread_attr_t는 pthread_attr_init(3)함수를 이용해서 변경할 수 있다.
        
        쓰레드가 detach상태로 되었다면 해당 쓰레드에 대한 pthread_join()호출은 실패한다.
        
        성공하면 0을, 실패하면 0이 아닌 값을 리턴한다.
        ```
        
        [https://www.joinc.co.kr/w/man/3/pthread_detach](https://www.joinc.co.kr/w/man/3/pthread_detach)
        
        [https://wariua.github.io/man-pages-ko/pthread_detach(3)/](https://wariua.github.io/man-pages-ko/pthread_detach%283%29/)
        
    - **pthread_join**
        
        ```c
        #include <pthread.h>
        
        int pthread_join(pthread_t th, void **retval);
        
        pthread_join 는 실별번호 th 로 시작된 쓰레드가 종료되는걸 기다린다. 스레드가 이미 종료했으면 pthread_join()이 즉시 반환한다. 이러한 쓰레드의 종료는 pthread_exit(3)로 종료되거나 혹은 리턴되는 경우 발생한다.
        
        만약 retval값이 NULL 이 아니라면, pthread_join()은 대상 스레드의 종료 상태(즉 대상 스레드가 pthread_exit(3)에 준 값)를 retval이 가리키는 위치로 복사한다. 대상 스레드가 취소됐으면 retval이 가리키는 위치에 PTHREAD_CANCELED가 들어간다.
        
        th 식별번호를 가지는 쓰레드가 join 되기 위해서는 반드시 joinable 상태의 쓰레드로 작동하고 있어야지만 한다. 만약 기다리는 쓰레드가 pthread_detach(3) 함수를 통해서 detached 상태가 되었거나 혹은 pthread_create(3)로 실행될때 PTHREAD_CREATE_DETACHED 특성으로 실행되었다면 join 으로 기다릴수 없게 된다.
        
        joinable 쓰레드가 종료되면, 종료된다고 하더라도 즉시 메모리 자원등이 해제 되지 않는다. pthread_join 함수를 만나야지만 자원이 해제된다. 그럼으로 모든 joinable 쓰레드에 대해서는 반드시 pthread_join 을 호출해주어야 한다. 그렇지 않을경우 메모리 누수가 발생할것이다.
        
        성공할경우 쓰레드식별자인 th에 쓰레드 식별번호를 저장하고, 0을 리턴한다. 실패했을경우 0 이 아닌 에러코드 값을 리턴한다.
        ```
        
        [https://www.joinc.co.kr/w/man/3/pthread_join](https://www.joinc.co.kr/w/man/3/pthread_join)
        
        [https://wariua.github.io/man-pages-ko/pthread_join(3)](https://wariua.github.io/man-pages-ko/pthread_join%283%29/)
        
        [https://man7.org/linux/man-pages/man3/pthread_join.3.html](https://man7.org/linux/man-pages/man3/pthread_join.3.html)
        
    - **pthread_mutex_init**
        
        ```c
        #include <pthread.h>
        
        int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutex_attr *attr);
        
        뮤텍스(mutex)는 쓰레드가 공유하는 데이터 영역을 보호하기 위해서 사용되는 도구이다. pthread_mutex_init는 뮤텍스 객체를 초기화 시키기 위해서 사용한다.
        
        첫번째 인자인 mutex는 초기화 시킬 mutex객체이다. 초기화 시킬 때 뮤텍스의 특징을 정의할 수 있는데, 이는 두번째 인자인 attr를 통해서 이루어진다. 기본 뮤텍스 특징을 사용하길 원한다면 NULL을 이용하면 된다.
        
        뮤텍스는 "fast", "recurise", "error checking"의 3가지 종류중 하나를 선택할 수 있으며, 기본적으로 "fast"가 사용된다.
        (각각의 종류에 대한 설명 : https://2net.co.uk/tutorial/mutex_mutandis)
        
        성공할경우 0을 실패했을경우에는 -1을 반환하며, 적당한 errno 값을 설정한다.
        
        동적으로 초기화하려면 pthread_mutex_init 함수를 사용하면되고, 정적으로 할당된 뮤텍스를 초기화하려면 PTHREAD_MUTEX_INITIALIZER 상수를 이용해서 초기화합니다.
        
        pthread_mutex_t lock = PTHREAD_MUTX_INITIALIZER;
        
        pthread_mutex_t는 뮤텍스의 특징을 결정하기 위해서 사용한다. PTHREAD_MUTEX_INITIALIZER(fast mutex)와 PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP(recursive mutexe), PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP(mutx 에러 체크용)의 3가지 상수가 준비되어 있다. 이중 하나를 선택하면 된다.
        ```
        
        [https://www.joinc.co.kr/w/man/3/pthread_mutex_init](https://www.joinc.co.kr/w/man/3/pthread_mutex_init)
        
        [https://docs.oracle.com/cd/E86824_01/html/E54766/pthread-mutex-init-3c.html](https://docs.oracle.com/cd/E86824_01/html/E54766/pthread-mutex-init-3c.html)
        
        [https://www.ibm.com/docs/en/i/7.3?topic=ssw_ibm_i_73/apis/users_61.html](https://www.ibm.com/docs/en/i/7.3?topic=ssw_ibm_i_73/apis/users_61.html)
        
    - **pthread_mutex_destroy**
        
        ```c
        #include <pthread.h>
        
        int pthread_mutex_destroy(pthread_mutex_t *mutex);
        
        pthread_mutex_destroy() 함수는 mutex가 가리키는 뮤텍스 객체를 파기한다. 그 뮤텍스 객체를 초기화 안 된 상태로 만드는 효과가 있다. 구현 시 pthread_mutex_destroy()에서 mutex가 가리키는 객체를 비유효 값으로 설정하도록 할 수도 있다.
        
        리눅스에서 쓰레드는 뮤텍스 객체와 별개로 되어 있다. 그러므로 쓰레드가 종료되었다고 하더라도 뮤텍스 객체는 여전히 남아 있게 된다. 이 함수를 호출해야지만 뮤텍스 객체가 삭제 된다.
        
        파기된 뮤텍스 객체를 pthread_mutex_init()으로 다시 초기화 할 수 있다. 파기된 객체를 그 외 방식으로 참조하는 결과는 규정되어 있지 않다.
        
        성공하면 pthread_mutex_destroy() 함수는 0을 반환합니다. 그렇지 않으면 오류를 나타내기 위해 오류 번호가 반환됩니다.
        
        The implementation has detected an attempt to destroy the object referenced by mutex while it is locked or referenced (for example, while being used in a pthread_cond_timedwait() or pthread_cond_wait()) by another thread.
        ```
        
        [https://man7.org/linux/man-pages/man3/pthread_mutex_destroy.3p.html](https://man7.org/linux/man-pages/man3/pthread_mutex_destroy.3p.html)
        
        [https://pubs.opengroup.org/onlinepubs/007904875/functions/pthread_mutex_destroy.html](https://pubs.opengroup.org/onlinepubs/007904875/functions/pthread_mutex_destroy.html)
        
    - **pthread_mutex_lock & pthread_mutex_unlock**
        
        ```c
        #include <pthread.h>
        
        int pthread_mutex_lock(pthread_mutex_t *mutex);
        int pthread_mutex_unlock(pthread_mutex_t *mutex);
        
        pthread_mutex_lock()는 (임계영역에 진입하기 위함)뮤텍스 잠금을 요청한다. 만약 뮤텍스의 최근 상태가 unlocked라면 쓰레드는 잠금을 얻고 임계영역에 진입하게 되고 리턴한다. 다른 쓰레드가 뮤텍스 잠금을 얻은 상태라면 잠금을 얻을 수 있을 때까지 기다리게 된다.
        
        pthread_mutex_unlock()는 뮤텍스잠금을 되돌려준다. 만약 fast 뮤텍스라면 pthread_mutex_unlock()는 언제나 unlocked 상태를 되돌려준다. recursive 뮤텍스라면 잠겨있는 뮤텍스의 수를 감소시키고 이 수가 0이 된다면 뮤텍스잠금을 되돌려주게 된다.
        
        성공했다면 0, 실패했다면 0이 아닌 수를 리턴하고 errno를 설정한다.
        ```
        
        [https://www.joinc.co.kr/w/man/3/pthread_mutex_lock](https://www.joinc.co.kr/w/man/3/pthread_mutex_lock)
        
        [https://wariua.github.io/man-pages-ko/pthread_mutex_lock(3)/](https://wariua.github.io/man-pages-ko/pthread_mutex_lock%283%29/)
        
- **External functions (Bonus)**
    - **fork**
        
        ```c
        #include <unistd.h>
        
        pid_t fork(void);
        
        성공할경우 자식 프로세스의 PID가 부모에게 리턴되며, 자식에게는 0이 리턴된다. 실패할경우에는 -1 이 리턴되며, 절적한 errno 값이 설정된다.
        
        fork는 자식프로세스를 만들기 위해서 사용되는 프로세스 생성기이다. fork 에 의해 생성된 자식 프로세스는 자신만의 PID 를가지게 되며, PPID는 부모프로세스의 PID를 가지게 된다. 그밖에 PGID, SID 를 상속받으며, 파일지시자, 시그널등을 상속받는다. 단 파일잠금(lock)와 시그널 팬딩은 상속받지 않는다.
        
        리눅스에서 fork 는 copy-on-write 를 이용해서 수행된다. 쓰레드 방식에 비해서 부모프로세스의 페이지 테이블을 복사하고 자식 프로세스에 대한 task 구조체를 만들기 위한 시간과 메모리의 소비가 크다는 단점이 있다.
        ```
        
        [https://www.joinc.co.kr/w/man/2/fork](https://www.joinc.co.kr/w/man/2/fork)
        
        [https://code-lab1.tistory.com/39](https://code-lab1.tistory.com/39)
        
        [https://velog.io/@t1won/Unix-fork](https://velog.io/@t1won/Unix-fork)
        
        [https://man7.org/linux/man-pages/man2/fork.2.html](https://man7.org/linux/man-pages/man2/fork.2.html)
        
    - **kill**
        
        ```c
        #include <sys/types.h>
        #include <signal.h>
        
        int kill(pid_t pid, int sig);
        
        kill(2) 시스템콜(:12)은 특정 프로세스나 프로세스 그룹에 시그널을 보내기 위해서 사용한다.
        
        pid 가 양수이면, sig 시그널을 pid 로 보낸다.
        pid 가 0이면 현재 프로세스가 속한 프로세스 그룹의 모든 프로세스에게 sig 시그널을 보낸다.
        pid 가 -1 이면, 1번 프로세스를 제외한 모든 프로세스에서 sig 시그널을 보낸다.
        pid 가 -1 보다 작으면, -pid 프로세스(:12)가 포함된 모든 그룹(:12)의 프로세스(:12)에게 sig 시그널을 보낸다.
        
        sig가 0이면 어떤 시그널(:12)도 보내지 않지만, 에러 검사는 할수 있다.
        
        시그널의 종류는 Unix(:12) 시스템마다 조금씩 다를수 있다. 자신의 Unix 시스템에서 사용할수 있는 시그널 목록은 kill(1) 쉘 명령어를 이용해서 확인할수 있다.
        
        [root@localhost test]# kill -l
         1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL
         5) SIGTRAP      6) SIGABRT      7) SIGBUS       8) SIGFPE
         9) SIGKILL     10) SIGUSR1     11) SIGSEGV     12) SIGUSR2
        13) SIGPIPE     14) SIGALRM     15) SIGTERM     17) SIGCHLD
        18) SIGCONT     19) SIGSTOP     20) SIGTSTP     21) SIGTTIN
        22) SIGTTOU     23) SIGURG      24) SIGXCPU     25) SIGXFSZ
        ...
        
        성공할경우 0을 실패했을경우에는 -1을 반환하며, 적당한 errno(:12) 값을 설정한다.
        ```
        
        [https://www.joinc.co.kr/w/man/2/kill](https://www.joinc.co.kr/w/man/2/kill)
        
        [https://www.lesstif.com/system-admin/unix-linux-kill-12943674.html](https://www.lesstif.com/system-admin/unix-linux-kill-12943674.html)
        
        [https://ko.wikipedia.org/wiki/Kill_(명령어)](https://ko.wikipedia.org/wiki/Kill_(%EB%AA%85%EB%A0%B9%EC%96%B4))
        
        [https://man7.org/linux/man-pages/man2/kill.2.html](https://man7.org/linux/man-pages/man2/kill.2.html)
        
    - **exit**
        
        [https://www.joinc.co.kr/w/man/3/exit](https://www.joinc.co.kr/w/man/3/exit)
        
    - **waitpid**
        
        ```c
        #include <sys/types.h>
        #include <sys/wait.h>
         
        pid_t waitpid(pid_t pid, int *stat_loc, int options);
        ```
        
        waitpid 함수는 인수로 주어진 pid 번호의 자식프로세스가 종료되거나, 시그널 함수를 호출하는 신호가전달될때까지 waitpid 호출한 영역에서 일시 중지 된다.
        
        만일 pid로 지정된 자식이 waitpid 함수 호출전에 이미 종료되었다면, 함수는 즉시 리턴하고 자식프로세스는 "좀비프로세스"로 남는다.
        
        pid < -1 : 프로세서 그룹 ID가 pid 의 절대값과 같은 자식 프로세스를 기다린다.
        pid  == -1 : 임의의 자식프로세스를 기다린다. 이것은 wait(2) 와 동일하다.
        pid == 0 : 프로세스 그룹 ID가 호출 프로세스의 ID와 같은 자식프로세스를 기다린다.
        pid > 0 : 프로세스 ID가 pid 의 값과 같은 자식 프로세스를 기다린다.
        
        The options argument is constructed from the bitwise-inclusive OR of zero or more of the following flags, defined in the <sys/wait.h> header
        
        **WNOHANG** : The waitpid() function shall not suspend execution of the calling thread if status is not immediately available for one of the child processes specified by pid. **(종료한 자식이 없으면 즉시 반환한다.)**
        **WUNTRACED** : The status of any child processes specified by pid that are stopped, and whose status has not yet been reported since they stopped, shall also be reported to the requesting process. (**자식이 정지한(하지만 [ptrace(2)](https://wariua.github.io/man-pages-ko/ptrace(2)/)추적 대상은 아닌) 경우에 반환한다.** 정지했으면서 추적 대상인 자식의 상태는 이 옵션을 지정하지 않아도 제공된다.)
        **WCONTINUED** : The waitpid() function shall report the status of any continued child process specified by pid whose status has not been reported since it continued from a job control stop. **(정지했던 자식이 SIGCONT 전달로 재개된 경우에도 반환한다.)**
        
        종료된 자식 프로세스의 ID는 에러일때 -1반환 하고, 만일 WNOHANG 가 사용되고 어떤 자식도 이용할수 없다면 0을 반환한다.
        
        [https://www.joinc.co.kr/w/man/2/waitpid](https://www.joinc.co.kr/w/man/2/waitpid)
        
        [https://wariua.github.io/man-pages-ko/waitpid(2)/](https://wariua.github.io/man-pages-ko/waitpid%282%29/)
        
        [https://man7.org/linux/man-pages/man3/wait.3p.html](https://man7.org/linux/man-pages/man3/wait.3p.html)
        
        [https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=skssim&logNo=121258721](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=skssim&logNo=121258721)
        
    - **sem_open ( ↔ sem_init)**
        
        ```c
        #include <fcntl.h>           /* For O_* constants */
        #include <sys/stat.h>        /* For mode constants */
        #include <semaphore.h>
        
        sem_t *sem_open(const char *name, int oflag);
        sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value);
        
        oflag 인자는 호출의 동작을 제어하는 플래그를 지정합니다.
        oflag에 O_CREAT가 지정되고, 세마포어가 아직 존재하지 않으면 세마포어가 생성됩니다.
        세마포어의 소유자(사용자 ID)는 호출 프로세스의 유효 사용자 ID로 설정되고, 그룹 소유권(그룹 ID)은 호출하는 프로세스의 호출 프로세스의 유효 그룹 ID로 설정됩니다.
        O_CREAT 와 O_EXCL이 모두 oflag에 지정되어 있으면, 지정된 이름의 세마포어가 이미 존재할 경우 오류가 반환됩니다.
        O_CREAT가 oflag에 지정되면 두 개의 추가 인수를 제공해야 합니다.
        그 중 하나인 mode 인자는 새 세마포어에 새 세마포어에 배치할 권한을 지정합니다.
        S_IRWXR : 그룹 접근, S_IRWXO : 타인 접근, S_IRWXU : 개인 접근
        또한, value 인자는 새 세마포어의 초기 값을 지정합니다. 세마포어 초기 값 0 보다 큰 양수여야 하며, unlock된 세마포어의 수를 의미한다. 이 값은 SEM_VALUE_MAX를 초과할 수 없다.
        
        성공하면 sem_open()은 새 세마포어의 주소를 반환합니다. 이 주소는 다른 세마포어 관련 함수를 호출할 때 사용됩니다. 에러가 발생하면 sem_open()은 errno가 설정되어 오류를 나타냅니다.
        
        이름 있는 세마포어는 항상 /dev/sem 경로에 생성된다.
        ```
        
        세마포어는 "익명 세마포어 (unnamed-)"와 "이름 있는 세마포어 (named-)"가 있다.
        익명 세마포어는 sem_init로 만들고, 이름 있는 세마포어는 sem_open으로 만든다.
        
        `sem_open()`은 세마포어 디스크립터를 반환하는데, 이는 `sem_wait()`, `sem_trywait()`
        , `sem_post()`를 활용하는 데 사용할 수 있다. 디스크립터는 `sem_close()`를 호출할 때까지 사용가능하다. 세마포어를 언링크하려면 `sem_unlink()`를 호출하면 된다. 모든 프로세스가 세마포어를 언링크하면, 세마포어는 파괴된다.
        
        [https://www.joinc.co.kr/w/Site/system_programing/IPC/semaphores](https://www.joinc.co.kr/w/Site/system_programing/IPC/semaphores)
        
        [https://man7.org/linux/man-pages/man3/sem_open.3.html](https://man7.org/linux/man-pages/man3/sem_open.3.html)
        
        [https://yechoi.tistory.com/55](https://yechoi.tistory.com/55)
        
    - **sem_close**
        
        ```c
        #include <semaphore.h>
        
        int sem_close(sem_t *sem);
        
        sem_close 서브루틴은 sem 매개변수로 표시된 이름 지정된 세마포어를 사용하여 호출 프로세스가 완료되었음을 표시합니다. 이름이 지정되지 않은 세마포어 ( sem_init에 의해 작성됨) 에 대해 sem_close 를 호출하면 오류가 리턴됩니다. sem_close 서브루틴은 시스템이 할당한 시스템 자원을 sem_open 서브루틴에 대한 후속 호출에서 재사용할 수 있도록 합니다. 프로세스가 sem이 가리키는 세마포어의 후속 사용을 시도하는 경우 오류가 리턴됩니다. sem_unlink 서브루틴 호출로 세마포어가 제거되지 않은 경우, sem_close 서브루틴은 세마포어의 상태에 영향을 주지 않습니다. O_CREAT 플래그가 설정된 sem_open 에 대한 최근 호출 이후에 이름 매개변수에 대해 sem_unlink 서브루틴이 성공적으로 호출된 경우, 세마포어를 열었던 모든 프로세스가 이를 닫으면 세마포어에 더 이상 액세스할 수 없습니다.
        
        성공적으로 완료되면 0이 리턴됩니다. 그렇지 않으면 -1이 리턴되고 오류를 표시하도록 errno 가 설정됩니다.
        ```
        
        [https://www.ibm.com/docs/ko/aix/7.3?topic=s-sem-close-subroutine](https://www.ibm.com/docs/ko/aix/7.3?topic=s-sem-close-subroutine)
        
        [https://man7.org/linux/man-pages/man3/sem_close.3.html](https://man7.org/linux/man-pages/man3/sem_close.3.html)
        
    - **sem_unlink**
        
        ```c
        #include <semaphore.h>
        
        int sem_unlink(const char *name);
        
        sem_unlink() removes the named semaphore referred to by name.
        The semaphore name is removed immediately.  The semaphore is destroyed once all other processes that have the semaphore open close it.
        
        On success sem_unlink() returns 0; on error, -1 is returned, with errno set to indicate the error.
        
        sem_unlink 서브루틴은 name문자열로 이름 지정된 세마포어를 제거합니다.
        
        name 으로 이름 지정된 세마포어가 현재 다른 프로세스에서 참조되는 경우, sem_unlink 는 세마포어의 상태에 영향을 주지 않습니다. sem_unlink 가 호출될 때 하나 이상의 프로세스에 세마포어가 열려 있는 경우, 세마포어에 대한 모든 참조가 sem_close, _exit에 대한 호출에 의해 삭제될 때까지 세마포어의 파기가 연기됩니다. 또는 exec. sem_open 을 호출하여 세마포어를 다시 작성하거나 다시 연결하면 sem_unlink 가 호출된 후에 새 세마포어가 참조됩니다.
        
        sem_unlink 서브루틴은 모든 참조가 손상될 때까지 차단하지 않으며 즉시 리턴합니다.
        ```
        
        [https://man7.org/linux/man-pages/man3/sem_unlink.3.html](https://man7.org/linux/man-pages/man3/sem_unlink.3.html)
        
        [https://www.ibm.com/docs/ko/aix/7.3?topic=s-sem-unlink-subroutine](https://www.ibm.com/docs/ko/aix/7.3?topic=s-sem-unlink-subroutine)
        
    - **sem_close, sem_unlink relation**
        
        ```c
        The sem_close() function closes a named semaphore that was previously opened by a thread of the current process using sem_open() or sem_open_np().
        
        The sem_close() function frees system resources associated with the semaphore on behalf of the process. Using a semaphore after it has been closed will result in an error. A semaphore should be closed when it is no longer used.
        
        If a sem_unlink() was performed previously for the semaphore and the current process holds the last reference to the semaphore, then the named semaphore will be deleted and removed from the system.
        ```
        
        - `sem_close` is associated with the semaphore and its count
            - Semaphore's reference count would be decremented when called
            - Even when count drops to zero semaphore is still kept alive
            - Another process can `sem_open` with same *name*, restoring the count back to `1` (or greater with subsequent `sem_open`s)
        - `sem_unlink` is associated with a semaphore's *name*
            - Name is no longer *taken* when called; name is relinquished
            - Semaphores still open (i.e. without `sem_close` calls) are kept alive until ref. count drops to zero
            - When count drops to zero an unlinked semaphore is destroyed
            - If a process `sem_open`s with the same, now-unliked name, it'd get a completely *new* (different) semaphore
        
        Though a semaphore associated with a name is `sem_close`d, the semaphore lives and name stays taken until it's `sem_unlink`ed.
        
    - **sem_wait**
        
        ```c
        #include <semaphore.h>
        
        int sem_wait(sem_t *sem);
        int sem_trywait(sem_t *sem);
        int sem_timedwait(sem_t *restrict sem, const struct timespec *restrict abs_timeout);
        
        sem_wait() decrements (locks) the semaphore pointed to by sem. If the semaphore's value is greater than zero, then the decrement proceeds, and the function returns, immediately.  If the semaphore currently has the value zero, then the call blocks until either it becomes possible to perform the decrement (i.e., the semaphore value rises above zero), or a signal handler interrupts the call.
        
        All of these functions return 0 on success; on error, the value of the semaphore is left unchanged, -1 is returned, and errno is set to indicate the error.
        
        세마포어의 P역할을 한다.
        
        즉, 세마포어를 하나 감소시키는 역할을 하고 세마포어가 0일 경우에는 1이상이 될 때까지 스레드는 대기 상태에 있는다.
        
        0이 아닐 경우에는 대기상태에서 빠져나와 세마포어를 또 1 감소시킨다.
        ```
        
        [https://man7.org/linux/man-pages/man3/sem_wait.3.html](https://man7.org/linux/man-pages/man3/sem_wait.3.html)
        
    - **sem_post**
        
        ```c
        #include <semaphore.h>
        
        int sem_post(sem_t *sem);
        
        sem_post() increments (unlocks) the semaphore pointed to by sem. If the semaphore's value consequently becomes greater than zero, then another process or thread blocked in a sem_wait(3) call will be woken up and proceed to lock the semaphore.
        
        sem_post() returns 0 on success; on error, the value of the semaphore is left unchanged, -1 is returned, and errno is set to indicate the error.
        ```
        
        [https://man7.org/linux/man-pages/man3/sem_post.3.html](https://man7.org/linux/man-pages/man3/sem_post.3.html)
        
- **삽질들**
    
    pthread_join을 while문을 돌리면 Thread number 순서대로 끝나는걸 확인하고 다음스레드를 찾아봄
    
    먹고 죽어버린다. → 먹는시간을 측정하고 바로 죽는걸 테스트하는데, 뮤텍스사이에 연산이 많던가 컴이 느려서이다.
    
    → 오래오래 버티도록 하자 (./philo 200 410 200 200) (./philo 5 650 200 100)
    
    출력뮤텍스는 모든 출력에 걸어야 순서를 보장한다.
    
    모든 경쟁적 상황(쓰레드분리후 쓰기가 1번이라도 포함된 경우)에 뮤텍스를 걸어야 data race를 방지하라는 서브젝트 목표를 달성할수있다.
    
    BONUS → 프로세스는 절대로 메모리를 공유하지 않는다 ㅠㅠ
    
- **유용한 사이트**
    
    [https://nafuka11.github.io/philosophers-visualizer/](https://nafuka11.github.io/philosophers-visualizer/)
    
    https://github.com/MichelleJiam/LazyPhilosophersTester
    
    https://github.com/newlinuxbot/Philosphers-42Project-Tester
    
    https://github.com/nesvoboda/socrates
    
    https://github.com/lienardale/alientest_philosopher
    

# 자료

[Philosophers](https://brassy-plate-60f.notion.site/Philosophers-344f249d74594b5faa7b7bff819558b0)