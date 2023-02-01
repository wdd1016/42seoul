# Minitalk

[minitalk notion](https://brassy-plate-60f.notion.site/Minitalk-5577161068d34737abe5517b99826aa0)

# 핵심 포인트

- `signal` `sigemptyset` `sigaddset` `sigaction` `kill` `getpid` `pause` `sleep` `usleep` `exit`
- `client` & `server`
- `PID`
- `UNIX signals`
- `unicode`

# 정리

- **signal 함수**
    
    [https://www.ibm.com/docs/ko/i/7.3?topic=functions-signal-handle-interrupt-signals](https://www.ibm.com/docs/ko/i/7.3?topic=functions-signal-handle-interrupt-signals)
    
    ```c
    **헤더** : **signal.h**
    
    **형태** : **void** ( *signal(**int** sig, **void** (*handler) (**int**)) ) (**int**);
              void (*signal(int,void (*)(int)))(int);
    
    **인수** : **int** sig - 시그널 번호
           **void** (*handler)(**int**) - 시그널을 처리할 핸들
    
    **반환** : **void** *()(**int**) 이전에 설정된 시그널 핸들러
    ```
    
    1. **void** (*handler) (**int**) → int형 하나를 받는 함수이며, 리턴형은 없음
    2. signal(**int** sig, **void** (*handler) (**int**)) → 매개변수로 int와 void함수(포인터)를 받음
    3. **void** ( *signal(**int** sig, **void** (*handler) (**int**)) ) (**int**) → 매개변수가 int형이고 반환형이 void인 함수포인터를 반환함
    
    [선언부 해석에 관한 자세한 설명](https://codingdog.tistory.com/entry/c%EC%96%B8%EC%96%B4-signal-%ED%95%A8%EC%88%98-%EC%84%A0%EC%96%B8%EB%B6%80%EB%A5%BC-%ED%95%B4%EC%84%9D%ED%95%B4-%EB%B4%85%EC%8B%9C%EB%8B%A4)
    
    어떤 시그널이 발생하면 기존 방법으로 처리할지, 아니면 무시할지, 프로그램에서 직접 처리할지를 설정할 수 있습니다.
    
- **UNIX signals**
    
    [https://reakwon.tistory.com/46](https://reakwon.tistory.com/46)
    
    시그널은 소프트웨어적인 interrupt입니다. 컴퓨터 용어에서 **인터럽트라는 것은 하던일 A를 중간이 잠시 멈추고 다른일 B를 하고 난 후 다시 A로 돌아와서 멈춘 부분부터 일을 하는 것**입니다.
    
    **SIGHUP** : 터미널과 연결이 끊겼을 때 발생합니다. 기본적인 처리는 프로세스가 종료되는 것입니다.
    
    **SIGINT** :  `Ctrl + C` 인터럽트가 발생했을때 발생합니다. 기본으로 프로세스가 종료됩니다.
    
    **SIGKILL** : 프로세스를 무조건 종료합니다. 절대 **무시할 수 없으며 제어될 수도 없습니다.**
    
    **SIGSEGV** : 프로세스가 잘못된 메모리를 참조했을 때 발생합니다. 기본 동작은 코어덤프를 남기고 종료합니다.
    
    **SIGSTOP** : 프로세스를 중단시킵니다. 종료한 상태는 아닙니다. 이 신호 역시 **제어될 수 없습니다.**
    
- **sigfillset, sigemptyset, sigaddset, sigdelset**
    
    [https://reakwon.tistory.com/53](https://reakwon.tistory.com/53)
    
    sigfillset, **sigemptyset** : 두 함수는 set라는 집합에서 모든 시그널을 추가하거나 모든 시그널을 제거합니다. 성공시 0, 실패시 -1을 반환합니다.
    
    **sigaddset**, sigdelset : signal을 추가하거나 삭제합니다. 성공시 0, 실패시 -1을 반환합니다.
    
- ****sigaction****
    
    [https://reakwon.tistory.com/215](https://reakwon.tistory.com/215)
    
    UNIX의 **signal함수보다 더 정교한 작업**이 가능한 함수입니다. 이 함수를 알기 위해서는 어느정도 시그널에 대한 기본지식이 있어야합니다. 시그널 집합, 시그널 차단 등의 개념이 나오기 때문입니다.
    
    이 함수를 이용하면 어느 **특정 신호에 관련된 동작을 조회할 수 있고 수정**할 수 있습니다.
    
    **sigaction 함수의 원형**은 이렇습니다.
    
    ```c
    #include <signal.h>
    
    int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
    ```
    
    - **signum** : signum은 시그널 번호를 의미합니다. signal함수의 처음 인자와 같습니다. 이런거 있잖아요. SIGINT, SIGQUIT 같은 시그널 번호입니다. 단, **SIGKILL과 SIGSTOP는 제어불가한 신호** 번호입니다.
    - **act** : sigaction 구조체인 act 인자는 signum에 대해서 어떤 동작을 취할지에 대한 정보를 담고 있습니다. 즉, **시그널에 대한 동작을 수정**하는 정보입니다.
    - **oldact** : 역시 sigaction구조체인데, 이전에 설정된 동작에 대해서 돌려줍니다. 즉, **시그널에 대한 동작을 조회**하는 정보입니다.
    
    **sigaction 구조체**는 이렇습니다.
    
    ```c
    struct sigaction {
       void     (*sa_handler)(int);
       void     (*sa_sigaction)(int, siginfo_t *, void *);
       sigset_t   sa_mask;
       int        sa_flags;
       void     (*sa_restorer)(void);
    };
    ```
    
    - **sa_handler** : 앞서 signum에 대한 동작을 나타내는 함수의 포인터입니다. 설정되지 않으면 기본동작을 의미하는 SIG_DFL입니다.
    - **sa_sigaction** : sa_flags로 SA_SIGINFO를 사용할때 설정할 수 있습니다. 이때 sa_handler 대신 설정하는데요. 신호 처리부(신호를 처리하는 함수)에 두가지 정보를 더 담아서 보냅니다. siginfo_t와 프로세스 문맥의 식별자가 그것입니다.
    - **sa_mask** : 차단할 신호의 집합입니다. sigprocmask를 통해서 특정 신호를 BLOCK 시킬지, 지를 정합니다.
    - **sa_flags** : 신호 옵션들입니다. 아래와 같은 옵션들이 존재합니다.
        
        
        | SA_NOCLDSTOP | signum이 SIGCHLD인 경우 자식 프로세스가 정지되었을때, notification을 받지 않습니다. 자식이 SIGSTOP, SIGTSTP, SIGTTIN, SIGTTOU 신호를 받아 정지되었을때 신호를 안받는다는 덥니다. |  |
        | --- | --- | --- |
        | SA_NOCLDWAIT | signum이 SIGCHLD일때, 자식 프로세스가 종료되었을때 시스템이 좀비프로세스를 만들지 않게 합니다. |  |
        | SA_NODEFER | 신호가 잡혀서 신호 처리 함수가 실행되는 도중에 다시 같은 신호가 발생됐을때, 시스템이 자동으로 차단하지 않습니다. |  |
        | SA_ONSTACK | sigaltstack으로 대체 스택을 선언해두었다면 신호가 대안 스택의 프로세스에 전달됩니다. |  |
        | SA_RESETHAND | 신호 처리 함수에 진입할때 이 신호의 처리 방식을 SIG_DFL로 재설정하고 SA_SIGINFO 플래그를 지웁니다. |  |
        | SA_RESTART | interrupt된 시스템 콜 호출이 자동으로 재시작됩니다. 아래 예에서 보겠습니다. |  |
        | SA_RESTORER | 어플리케이션에서 사용할 의도로 만들어진 flag가 아닙니다. sa_restorer와 관련된 옵션입니다. |  |
        | SA_SIGINFO | 신호 처리부에 추가적인 두가지 정보를 전달합니다. 이때 sa_sigaction함수 포인터를 설정해야합니다. 위의 sa_sigaction 인자에 대한 설명을 참고하세요. |  |
    - **sa_restorer** : **이 필드는 앱 사용 목적으로 만들어진 필드가 아닙니다.** sigreturn과 관련된 필드입니다. 넘어가겠습니다.
- Struct sigaction (sigaction 함수 내에 선언되어있는 내장 struct)
    
    ```c
    #include <signal.h>
    
    int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
    ```
    
    ```c
    struct  sigaction {
    	union __sigaction_u __sigaction_u;  /* signal handler */
    	sigset_t sa_mask;               /* signal mask to apply */
    	int     sa_flags;               /* see signal options below */
    };
    
    typedef unsigned int sigset_t
    
    /* if SA_SIGINFO is set, sa_sigaction is to be used instead of sa_handler. */
    #define sa_handler      __sigaction_u.__sa_handler
    #define sa_sigaction    __sigaction_u.__sa_sigaction
    
    #define SA_ONSTACK      0x0001  /* take signal on signal stack */
    #define SA_RESTART      0x0002  /* restart system on signal return */
    #define SA_RESETHAND    0x0004  /* reset to SIG_DFL when taking signal */
    #define SA_NOCLDSTOP    0x0008  /* do not generate SIGCHLD on child stop */
    #define SA_NODEFER      0x0010  /* don't mask the signal we're delivering */
    #define SA_NOCLDWAIT    0x0020  /* don't keep zombies around */
    #define SA_SIGINFO      0x0040  /* signal handler with SA_SIGINFO args */
    
    union __sigaction_u {
    	void    (*__sa_handler)(int);
    	void    (*__sa_sigaction)(int, struct __siginfo *,
    	    void *);
    }; SA_SIGINFO is set, sa_sigaction is to be used instead of sa_handler
    
    typedef struct __siginfo {
    	int     si_signo;               /* signal number */
    	int     si_errno;               /* errno association */
    	int     si_code;                /* signal code */
    	pid_t   si_pid;                 /* sending process */
    	uid_t   si_uid;                 /* sender's ruid */
    	int     si_status;              /* exit value */
    	void    *si_addr;               /* faulting instruction */
    	union sigval si_value;          /* signal value */
    	long    si_band;                /* band event for SIGPOLL */
    	unsigned long   __pad[7];       /* Reserved for Future Use */
    } siginfo_t;
    
    typedef int pid_t
    typedef unsigned int uid_t
    ```
    
- **kill**
    
    [C언어 kill (시그널 전송 함수)](https://badayak.com/entry/C%EC%96%B8%EC%96%B4-kill-%EC%8B%9C%EA%B7%B8%EB%84%90-%EC%A0%84%EC%86%A1-%ED%95%A8%EC%88%98-kill)
    
    kill() 함수는 쉘에서 프로세스를 죽이는 kill 명령과는 달리 프로세스에 시그널을 전송합니다. 물론, 프로세스에 SIGKILL을 보내면 쉘 명령의 kill과 같은 역활을 합니다.
    
    - 헤더: signal.h
    - 형태: **int** kill(pid_t pid, **int** sig)
    - 인수: pid_t pid
             **int** sig 시그널 번호
    - 반환값 : **int**  0 == 성공
                        1 == 실패
    
    kill() 함수는 특정 프로세스 뿐만 아니라 같은 그룹 ID가 같은 모든 프로세스에게 동시에 시그널을 전송할 수 있으며, 권한 안에 있는 모든 프로세스에게도 시그널을 전송할 수 있습니다.
    
    첫 번째 인수는 pids는 KILL 대상 프로세스 ID, 두 번째 인수 sig는 시그널 번호입니다. pid는 프로세스 ID 값에 따라 아래와 같이 처리가 분류됩니다.
    
    | pid | 의미 |
    | --- | --- |
    | 양수 | 지정한 프로세스 ID에만 시그널을 전송 |
    | 0 | 함수를 호출하는 프로세스와 같은 그룹에 있는 모든 프로세스에 시그널을 전송 |
    | -1 | 함수를 호출하는 프로세스가 전송할 수 있는 권한을 가진 모든 프로세스에 시그널을 전송 |
    | -1 이외의 음수 | 첫 번째 인수 pid 의 절대값 프로세스 그룹에 속하는 모든 프로세스에 시그널을 전송 |
- **getpid**
    
    [C언어 getpid(프로세스 ID 구하기 함수)](https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4-ID-%EA%B5%AC%ED%95%98%EA%B8%B0-%ED%95%A8%EC%88%98-getpid)
    
    - 헤더: sys/types.h,unistd.h
    - 형태: pid_t getpid(**void**)
    - 인수: -
    - 반환: 이 함수는 항상 성공하며 프로세스 ID를 반환합니다.
    
    [getpid()](https://badayak.com/4507) 실행 중인 프로세스 ID를 구합니다.
    
    [getppid()](https://badayak.com/4508) 부모 프로세스의 ID를 구합니다.
    
- **pause**
    
    [C언어 pause (시그널 수신 대기 함수)](https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%EC%8B%9C%EA%B7%B8%EB%84%90%EC%9D%84-%EC%88%98%EC%8B%A0%ED%95%A0-%EB%95%8C%EA%B9%8C%EC%A7%80-%EB%8C%80%EA%B8%B0-%ED%95%A8%EC%88%98-pause)
    
    pause() 함수를 호출하면 시그널을 수신할 때까지 대기 상태로 빠집니다. 어떤 시그널이 발생하기 전까지 대기상태를 유지할 때 유용합니다.
    
    - 헤더: unistd.h
    - 형태: **int** pause(**void**)
    - 인수: -
    - 반환: 항상 -1을 반환하며 errno에는 ERESTARTNOHAND 로 설정됩니다.
- **sleep, usleep**
    
    [https://jhnyang.tistory.com/303](https://jhnyang.tistory.com/303)
    
    sleep에는 첫 글자가 대문자로 시작하는 Sleep함수가 있고 소문자로 시작하는 sleep함수 **두 가지**가 있지만, 리눅스/유닉스에서 지원하는 대기 함수는 sleep으로 단위가 초(second)입니다.
    
    마이크로초 단위도 지원을 해주기 위해 리눅스에서는 usleep 함수를 지원하고 있어요. 헤더는 동일하니 만약 1초보다 세분해서 대기를 걸고 싶으면 sleep대신 usleep을 사용해주면 됩니다. 사용방법은 sleep과 동일합니다. ( 단, 최대값은 1,000,000(1초) )
    
    ```c
    sleep(1) == usleep(1000000) (== Sleep(1000) in windows)
    ```
    
- **PID**
    
    [https://www.ibm.com/docs/en/ztpf/1.1.0.15?topic=process-id](https://www.ibm.com/docs/en/ztpf/1.1.0.15?topic=process-id)
    
    [https://probe29.tistory.com/38](https://probe29.tistory.com/38)
    
    PID 는 Process ID 의 줄임말로 운영체제에서 프로세스를 식별하기 위해 부여하는 번호를 의미한다.
    
    PPID 는 Parent Process ID 의 줄임말로 부모 프로세스의 PID 를 의미한다.
    
    부모 프로세스는 현재 실행 중인 프로세스 (자식 프로세스) 를 시스템 콜을 호출하여 생성한 프로세스를 의미한다.
    
    만약 부모 프로세스가 자식 프로세스보다 일찍 종료되는 경우 자식 프로세스는 고아 프로세스가 되어 PPID 로 init process 의 PID, 1을 가지게 된다.
    
- Unicode 정보,  출력
    
    [C언어 유니코드(unicode)에 write 출력에 대해 알아보기](https://jaeseokim.dev/C/C-%EC%9C%A0%EB%8B%88%EC%BD%94%EB%93%9C(unicode)%EC%97%90_%EB%8C%80%ED%95%B4_%EC%95%8C%EC%95%84%EB%B3%B4%EA%B8%B0(feat.42seoul_ft_printf)/)
    
    기본적으로 vscode의 기본 인코딩은 UTF-8이며, Mac과 리눅스의 기본 인코딩도 UTF-8이다.
    
    ![스크린샷 2023-01-29 오후 6.59.33.png](Minitalk%pictures/first.png)
    
    ![스크린샷 2023-01-29 오후 7.03.59.png](Minitalk%pictures/second.png)
    
    [비트연산](http://www.tcpschool.com/c/c_operator_bitwise)
    
- **삽질의 기억들**
    1. 시그널은 어떻게 주고받으며, 어떠한 방식으로 처리되는지 고민
        - 시그널은 운영체제가 프로그램에 이를 알리는 기법이라고 한다.
        - 시그널이 전송되면 기본적인 설정 혹은 (signal func, sigaction func에 의해)설정된 방법(handler(__sa_sigaction)함수(포인터))에 따라 프로그램은 처리한다.
    2. 시그널 송수신 과정에 대한 고민
        - 클라이언트에서 서버로 시그널이 전해지면, 서버는 클라이언트 PID를 저장하고 답신을 보낸다. 
        클라이언트는 답신을 받고 문자열을 문자 1개씩 buf에 담고 비트연산을 통해 1비트씩 전송한다.
        전송은 클라이언트가 문자비트 보냄→ 서버가 받고 답신보냄 → 클라이언트가 받고 문자비트 보냄 순으로 진행한다.
        - 마지막 `\0` (00000000)이 수신되면 서버는 종료 시그널을 보낸다.
        클라이언트는 종료시그널을 받고 종료한다.

# 자료

[minitalk](https://www.notion.so/minitalk-cd2a1f4d5a2a419ab89aa66ee9888468)

[https://cdn.intra.42.fr/pdf/pdf/35917/en.subject.pdf](https://cdn.intra.42.fr/pdf/pdf/35917/en.subject.pdf)