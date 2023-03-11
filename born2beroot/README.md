# Born2beroot Rocky Linux

[born2beroot notion](https://brassy-plate-60f.notion.site/Born2beroot-Rocky-Linux-4b0aef6d787e4310bd7a047fa5ce620e)

# 핵심 포인트

- 설치 (파티션을 중심으로)
- SSH, Firewall, Port Forwarding
- Cron

# 정리

- LVM
    
    **물리적 볼륨 / PV (Physical Volume), 물리적 확장 / PE (Physical Extent)**
    
    **볼륨 그룹 / VG (Volume Group), 논리적 볼륨 / LV (Logical Volume)**
    
    [https://greencloud33.tistory.com/41](https://greencloud33.tistory.com/41)
    
- 설치 및 파티션 설정
    
    [https://rockylinux.org/ko/download](https://rockylinux.org/ko/download) 에서 (x86_64, minimal) 다운로드 (록키리눅스 text install mode에서는 custom 파티션 분할을 지원하지 않는다. 따라서 minimal설치를 하되, normal install mode를 사용하여야 한다. → 설치된 리눅스 환경이 CLI이면 된다.)
    
    Software Selection : minimal, KDUMP : disabled, hostname : _____42
    
    - Installation Destination (파티션 세팅 포함, 전체 과정 스크린샷을 통한 정리)
        
        ![Screen Shot 2023-01-04 at 4.48.05 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.48.05_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.11.28 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.11.28_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.48.38 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.48.38_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.49.13 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.49.13_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.16.06 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.16.06_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.51.07 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.51.07_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.54.18 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.54.18_PM.png)
        
        임의의 파티션 sda2, sda3를 standard 파티션으로 생성한다. (이렇게 해야만 확장파티션을 통한 논리파티션을 sda5로 고정시킬 수 있다.)
        
        ![Screen Shot 2023-01-04 at 4.54.52 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.54.52_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.55.04 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.55.04_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.55.43 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.55.43_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.55.50 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.55.50_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.56.03 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.56.03_PM.png)
        
        볼륨그룹 설정 (Encrypt → 나중에 비밀번호 사용)
        
        ![Screen Shot 2023-01-04 at 4.56.27 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.56.27_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.56.40 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.56.40_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.57.06 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.57.06_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.57.20 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.57.20_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.57.33 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.57.33_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.58.00 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.58.00_PM.png)
        
        /srv 같이 나와있지 않은 마운트포인트는 직접 입력하면된다.
        
        ![Screen Shot 2023-01-04 at 4.58.21 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.58.21_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.58.34 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.58.34_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.58.57 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.58.57_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.59.15 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.59.15_PM.png)
        
        ![Screen Shot 2023-01-04 at 4.59.35 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.59.35_PM.png)
        
        /var/log는 name이 var_log로 되어있는데, var-log로 변경해야지 최종적으로 원하는 LVMGroup-var—log로 저장이된다.
        
        ![Screen Shot 2023-01-04 at 4.59.57 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_4.59.57_PM.png)
        
        VG의 LUKS비밀번호 설정
        
        ![Screen Shot 2023-01-04 at 5.00.16 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.00.16_PM.png)
        
        ![Screen Shot 2023-01-04 at 5.00.26 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.00.26_PM.png)
        
        파티션 생성 종료 후 KDUMP 비활성화
        
        ![Screen Shot 2023-01-04 at 5.00.34 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.00.34_PM.png)
        
        호스트 네임설정
        
        ![Screen Shot 2023-01-04 at 5.00.58 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.00.58_PM.png)
        
        루트 패스워드 설정
        
        ![Screen Shot 2023-01-04 at 5.01.24 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.01.24_PM.png)
        
        확인 후 Begin install
        
        ![Screen Shot 2023-01-04 at 5.01.34 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.01.34_PM.png)
        
        1차적인 설치 완료 후 모습
        
        ![Screen Shot 2023-01-04 at 5.11.09 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.11.09_PM.png)
        
        sda2, sda3은 쓸데없는 파티션이므로 삭제를 해야한다.
        
        일단 해당 마운트포인트를 UNMOUNT진행
        
        ![Screen Shot 2023-01-04 at 5.11.38 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.11.38_PM.png)
        
        fdisk를 통해 sda2, sda3 삭제
        
        ![Screen Shot 2023-01-04 at 5.12.02 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.12.02_PM.png)
        
        ![Screen Shot 2023-01-04 at 5.12.45 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.12.45_PM.png)
        
        하고 나면 재부팅할때마다 에러가 발생한다.
        
        ![Screen Shot 2023-01-04 at 5.15.10 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.15.10_PM.png)
        
        문제를 해결하기 위해 /etc/fstab 을 수정하면 된다.
        
        ![Screen Shot 2023-01-04 at 5.15.44 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.15.44_PM.png)
        
        ![Screen Shot 2023-01-04 at 5.15.55 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.15.55_PM.png)
        
        /home/aaa와 /home/bbb의 내용을 지운다.
        
        ![Screen Shot 2023-01-04 at 5.16.19 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_5.16.19_PM.png)
        
        저장하면 설치 완료
        
    
    설치 완료 후 모습
    
    ![Screen Shot 2023-01-05 at 8.38.09 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-05_at_8.38.09_PM.png)
    
- [X.org](http://X.org)? KDUMP?
    - X.org
        
        [https://wiki.gentoo.org/wiki/Xorg/Guide/ko](https://wiki.gentoo.org/wiki/Xorg/Guide/ko)
        
        리눅스에서 새로 접하는 가장 놀라운 점 중에 하나는 그래픽 사용자 인터페이스가 시스템에서 실행하는 프로그램의 일부일 뿐이라는 사실입니다. 그래픽 환경은 리눅스 커널 또는 다른 시스템의 내부로서의 일부가 "아닙니다". 즉, 그래픽 환경 인터페이스(GUI)는 워크스테이션에서 그래픽 기능을 가능케 해주는 강력한 도구입니다.
        
        [X.org](http://www.x.org/) 프로젝트는 자유롭게 재배포 가능한 X11 오픈소스 구현 시스템으로 만들었습니다. 오픈소스 X11 기반 데스크톱의 하부입니다.
        
        Xorg에서는 하드웨어와 여러분이 실행하려는 그래픽 소프트웨어사이의 인터페이스를 제공합니다. 이에 견주어 Xorg는 완전한 네트워크 지향 기능을 갖추고 있으며, 다른 머신에서 보고있는동안 하나의 시스템에서 프로그램을 실행할 수 있음을 의미합니다.
        
    - KDUMP?
        
        [https://tech.osci.kr/2014/03/22/리눅스-kdump에-대한-이해/](https://tech.osci.kr/2014/03/22/%eb%a6%ac%eb%88%85%ec%8a%a4-kdump%ec%97%90-%eb%8c%80%ed%95%9c-%ec%9d%b4%ed%95%b4/)
        
        kdump는 kexec를 바탕으로 한 “커널 크래쉬 덤핑 메카니즘” 입니다. 이는 커널 패닉이 발생 하였을때, 시스템의 메모리 상태를 vmcore 라는 파일 형태로 생성하는 작업입니다.
        
        윈도우에 블루스크린이 있는것처럼 리눅스에도 커널패닉이라는 것이 존재합니다. 데스크탑같은 경우는 그냥 재부팅 해버리거나 포맷해버리면 그만이지만, 서버와 같은 경우는 장애가 발생했을 때 재부팅을 하는것도 리스크가 있는 작업이고, 장애가 발생했을 때 그 원인을 찾아내서 같은 장애가 나타나지 않도록 하는 것이 중요합니다. 그 원인을 찾을 수 있는 실마리를 제공하는 것이 vmcore 라는 코어 파일이며, 코어파일을 생성하는 것이 kdump라고 생각하면 됩니다.
        
        [https://ko.wikipedia.org/wiki/Kdump](https://ko.wikipedia.org/wiki/Kdump)
        
        ![Kdump.svg](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/420px-Kdump.png)
        
- SELinux (Security-Enhanced Linux)
    
    관리자가 시스템 액세스 권한을 효과적으로 제어할 수 있게 하는 [Linux® 시스템](https://www.redhat.com/ko/topics/linux/what-is-linux)용 [보안](https://www.redhat.com/ko/topics/security) 아키텍처입니다. 
    
    SELinux는 시스템의 [애플리케이션](https://www.redhat.com/ko/resources/openshift-service-on-aws-overview), 프로세스, 파일에 대한 액세스 제어를 정의합니다. 주체로 알려진 [애플리케이션](https://www.redhat.com/ko/resources/accelerate-application-development-datasheet)이나 프로세스가 파일과 같은 객체에 대한 액세스를 요청하는 경우, SELinux는 주체와 객체에 해 권한이 캐시되는 AVC(Access Vector Cashe)를 확인합니다.
    
    동작모드는 enforce, permissive, disable 세 가지 모드가 있으며 RHEL/CentOS 를 설치하면 default 로 enforce mode 로 동작하며 SELinux 의 rule 에 어긋나는 operation 은 거부된다.
    
    [https://www.lesstif.com/system-admin/centos-selinux-6979732.html](https://www.lesstif.com/system-admin/centos-selinux-6979732.html)
    
    ```c
    SELinux 모드 확인
    sestatus
    
    SELinux 설정 파일 열기
    vi /etc/selinux/config
    
    SELinux 동작모드 변경
    vi /etc/selinux/config 내의 SELINUX=disabled를 수정, 재부팅 (영구)
    setenforce 0 (임시)
    ```
    
- apt와 aptitude, dnf와 yum
    - **Apt** : Advanced Packaging Tool
        
        소프트웨어의 설치와 제거를 처리하는 패키지 관리 툴이다. 초기에는 .deb 패키지를 관리하기 위해 만들었지만 현재는 rpm 패키지 매니저와도 호환된다.
        
        apt는 그래픽 인터페이스 없이 명령어로 사용한다.
        
        설치할 패키지 명을 입력하면, '/etc/apt/sources.list'에 지정된 소스 목록에서 해당 패키지 + 종속성 목록과 함께 찾아 자동으로 설치한다. 그렇기 때문에 어떤 패키지를 설치할 때 종속성 문제를 걱정하지 않아도 된다.
        
        또 굉장히 유연해서 사용자가 직접 새로운 소스 목록을 추가하거나 시스템이 업그레이드 되도 해당 패키지를 업데이트 하지 않게 해 현재 버전을 계속 사용하는 등의 작업을 할 수 있다.
        
    - **Aptitude**
        
        Aptitude는 사용자 인터페이스를 추가해 사용자가 대화형으로 패키지를 검색해 설치, 제거할 수 있는 high-level 패키지 관리 도구다. 데비안을 위해 만들어졌지만 rpm 기반 패키지까지 확장된다.
        
        그리고 텍스트 기반 대화형 인터페이스와 비대화형 command line 모드에서도 작동한다.
        
        [https://velog.io/@joonpark/aptitude-vs-apt](https://velog.io/@joonpark/aptitude-vs-apt)
        
    - Apt와 Aptitude의 차이점
        
        Aptitude가 더 방대하고 apt-get, apt-cache를 포함한 기능들을 포함한다.
        
        apt-get이 패키지 설치, 업그레이드, 시스템 업그레이드, 종속성 검사 등을 한다면, aptitude는 이보다 더 많은 일을 할 수 있다. 설치된 패키지 목록, 패키지를 자동 또는 수동으로 설치하도록 표시, 업그레이드에 사용할 수 없는 패키지 보관 등이 있다.
        
    - dnf와 yum
        
        dnf는 yum의 단점인 느린속도와 과다한 메모리 사용, 의존성 결정 느림 문제를 개선한 패키지 관리자
        
        yum에 비해 성능 효율이 좋아 속도면에서 우수
        
        외부 라이브러리인 libsolv를 이용하여 의존성 문제를 해결
        
        API 문서가 공식적으로 제공
        
        C, C++, Python으로 작성되었고 여러 확장 시스템을 지원
        
        기존 yum의 명령어 그대로 사용가능
        
        yum 최신 배포판에서도 계속 사용은 가능하다고 하니 dnf를 모른다고 해도
        
        패키지 관리에 큰 문제는 없을 것 같다.
        
- Port, Firewall
    
    ```c
    netstat -tnlp : TCP 중에서(t), Listening상태[열린포트]인 애들만(l), 
    상세정보까지(p), 10진수 숫자로(n) 표기한다.
    
    ss -tunlp
    ss는 새로운 netstat입니다. 일부 netstat 기능이 없지만 TCP 상태를 더 많이 노출하고 속도가 약간 더 빠릅니다.
    명령 옵션은 대부분 동일하므로 netstat에서 ss로 전환하는 것은 어렵지 않습니다.
    
    netstat 설치
    yum install net-tools
    
    상대방의 포트가 열려 있는지 확인
    nc -z 호스트주소 포트
    ```
    
    - chrony service, 삭제 방법
        
        **[chrony](https://chrony.tuxfamily.org/)는 NTP(Network Time Protocol) 을 구현한 server/client 로 기존 리눅스의 ntpd 를 대체합니다.**
        
        **특히 RedHat Enterprise Linux 8 부터는 기본 NTP 제품으로 채택되었습니다.**
        
        ```c
        삭제 방법
        dnf remove chrony
        ```
        
    
    ```c
    방화벽 포트 추가
    firewall-cmd --zone=public --add-port=PortNumber/tcp --permanent
    
    방화벽 포트 삭제
    firewall-cmd --zone=public --remove-port=PortNumber/tcp --permanent
    
    방화벽 재시작 (변경 내용 적용)
    firewall-cmd --reload
    
    추가한 설정 조회하기
    firewall-cmd --list-all
    ```
    
- SSH
    
    **SSH**(**S**ecure **Sh**ell)는 원격지 호스트 컴퓨터에 접속하기 위해 사용되는 인터넷 프로토콜이다. 뜻 그대로 보안 셸이다. 기본 포트는 22번이다. 우리가 원하는 4242포트로 변경해야 한다.
    
    ```c
    ssh 설치
    yum -y install openssh-server openssh-clients openssh-askpass
    
    network 재시작
    systemctl restart NetworkManager.service
    
    ssh 설정파일 수정(/etc/ssh/sshd_config 파일)
    #Port 22 ==> Port 22 : 이 부분 주석 해제 및 수정
    #PermitRootLogin yes -> PermitRootLogin no (root 로그인 차단)
    // LoginGraceTime : 사용자 인증을 요청받을 수 있는 최대 시간
    // MaxAuthTries : 계정 당 최대 연결 시도 횟수
    // MaxSessions : SSH 연결을 허용할 최대 클라이언트 수
    
    **Selinux 작동시 추가 할것**
    semanage port -a -t ssh_port_t -p tcp 4242
    // semanage port -d -t ssh_port_t -p tcp 22 
    // -> 불가 (Port tcp/22 is defined in policy, cannot be deleted)
    // -> selinux defalut policy 변경 요구, 굳이 실익이 없음 (방화벽 존재)
    
    ssh 서비스 구동
    systemctl start sshd.service
    
    방화벽 포트 허용 (permanent)
    firewall-cmd --zone=public --add-port=4242/tcp --permanent
    firewall-cmd --reload
    
    ssh 포트 확인
    semanage port -l | grep ssh
    
    sshd 재시작
    systemctl restart sshd.service
    -> error (Job for sshd.service failed ~) : selinux Permissive로 전환 (후에 다시 enforcing 으로)
    
    열린 포트 확인
    netstat -tulpn | grep LISTEN
    firewall-cmd --list-all
    
    ```
    
    - ssh 설정파일 수정 스크린샷
        
        ![Screen Shot 2023-01-02 at 9.41.36 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-02_at_9.41.36_PM.png)
        
    - [https://velog.io/@pearpearb/42서울-Born2berootSSH와-포트포워딩](https://velog.io/@pearpearb/42%EC%84%9C%EC%9A%B8-Born2berootSSH%EC%99%80-%ED%8F%AC%ED%8A%B8%ED%8F%AC%EC%9B%8C%EB%94%A9)
        
        사용자(Client)가 키를 생성하면 공개키(public key)와 개인키(private key)가 만들어진다. 공개키를 통신하고자 하는 컴퓨터(Server)에 복사하여 저장한다.
        
        1. 클라이언트가 통신하고자 하는 서버에 요청을 보낸다.
        2. 응답을 하는 서버가 저장하고 있던 공개키를 보낸다.
        3. 클라이언트는 해당 공개키가 자신의 개인키와 한 쌍의 키가 맞는 지 검사한다.(클라이언트에서 자물쇠와 키를 만들어 키를 서버에 보내고, 통신하고자 할 때 다시 그 키가 자물쇠에 맞는 지 확인하는 것이라고 이해하면 쉽다.)
        4. 한 쌍의 키가 맞는 것이 증명되면 드디어 두 컴퓨터 사이에 암호화된 채널이 생성된다.
    - **가상환경에서 네트워크 주소와 실제 네트워크 주소가 다르기 때문에** 포트포워드로 연결해주어야한다.  (아래에 설명)
    
    ```c
    Mac에서 연결
    ssh username@ip -p portnumber (ssh juyojeon@localhost -p 7777)
    
    상위 shell로 탈출 (없으면 로그아웃)
    exit
    ctrl + d
    ```
    
    - ssh 접속 Error(WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED) 처리
        
        [https://visu4l.tistory.com/entry/ssh-원격-접속-에러WARNING-REMOTE-HOST-IDENTIFICATION-HAS-CHANGED](https://visu4l.tistory.com/entry/ssh-%EC%9B%90%EA%B2%A9-%EC%A0%91%EC%86%8D-%EC%97%90%EB%9F%ACWARNING-REMOTE-HOST-IDENTIFICATION-HAS-CHANGED)
        
        ssh 최초접속시에 A와 B에서 서로간에 인증 과정을 하는데.. B는 새로 설치되었으니 B는 상관없지만 A는 예전B에  IP로 인증이 되어있는 상태에서 B로 로그인을 하면 로그인시에 예전에 IP로 인증했던 정보를 가지고 B로 로그인을 하려고 하지만 B는 인증정보가 없기때문에 위와 같은 현상이 나타난다.
        
        /.ssh/known_hosts 를 수정하면 된다.
        
    
- Port Forwarding
    
    포트포워딩(Port Forwarding)은 특정한 포트로 들어오는 데이터 패킷을 다른 포트로 바꿔서 다시 전송해주는 작업을 하는 것이다. 네트워크와 원격 기기 사이를 직접적으로 연결하는 경우에 유용하다.
    
    **가상환경에서 네트워크 주소와 실제 네트워크 주소가 다르기 때문에** 포트포워드로 연결해주어야한다. 그렇게 클러스터의 네트워크와 내 가상머신의 네트워크를 연결하여, 클러스터 터미널에서 가상머신을 사용할 수 있다. ([https://cjwoov.tistory.com/3](https://cjwoov.tistory.com/3)) 혹은 **호스트 네트워크를 설정**하면된다.
    
    VirtualBox → setting → Network → advanced → port forwarding
    
    - `HOST IP`: 127.0.0.1(localhost, 자기 자신) 또는 `ifconfig | grep inet`의 값
    - `GuestIP`: 가상머신에서의 `hostname -I`의 값
    - `HOST PORT`: 7777 (임의로 설정해줌)
    - `GUEST PORT`: 4242 (앞서 가상머신에서 허용해 준 포트번호)
    
- su & su - & sudo & sudo -s / sudo su
    
    리눅스에는 **다중 유저 접속 시스템**으로써 동시에 여러 사용자들이 접속할 수 있습니다. 그리고 이는 어떤 서비스를 위한 서버의 기능으로 작동하기 때문에 각각의 유저들에 대한 **권한(**읽기, 쓰기, 실행 등)의 범위 관리가 매우 중요합니다.
    
    리눅스에서 최고의 권한을 가지고 있는 계정은 **슈퍼 유저 / Root** 입니다.
    Root 계정은 리눅스 상의 모든 명령을 실행할 수 있고 이 권한이 있을 때만 실행이 가능한 프로그램들도 있습니다. 때문에 리눅스 유저들은 Root의 권한을 빌려야 하는 순간들이 필요하기에 이를 가능하게 하는게 **su** 명령어입니다.
    
    **su 명령어**는 현재의 사용자를 로그아웃하지 않고 바로 **다른 사용자의 계정으로 전환하는 명령어**입니다. 전환 시에 대상 계정의 패스워드를 요구합니다.
    
    **su 명령어**는 **현재 계정이 가진 환경변수 설정들을 그대로 유지**한채로 **대상 계정으로 전환**합니다.
    
    **su - 명령어** 또한 단순히 su만 썼을 때와 큰 차이는 없어보입니다. 전환 시에 대상 계정의 패스워드를 요구하는 것도 같습니다. 다만 **su - 명령어**는 su 명령어와 달리 **전환할 계정의 환경변수 설정들을 불러옵니다.** **완벽하게 전환**된다고 할 수 있습니다.
    
    **sudo 명령어**는 일반 사용자가 슈퍼 유저 / root의 권한을 잠시 빌려서 명령을 실행하게 하는 명령어입니다.
    
    **sudo 명령어**는 **root 권한을 빌려서 실행하는 명령어 한번만 그 권한으로 실행**합니다. 단순히 권한을 잠시 빌리는 것이기 때문에 이력(log)가 남는 작업을 했을 때, 빌려온 root 권한이 아닌 해당 사용자의 계정이 남습니다.
    
    sudo 명령어를 아무나 사용하는 것은 문제가 되기 때문에 /etc/sudoers 그룹에 사용자의 계정이 등록되어 있어야 사용할 수 있습니다.
    
    **sudo -s 또는 sudo su 명령어**는 **root 계정의 권한을 반영구적으로 빌리고 root로 로그인한 상태의 쉘을 사용**할 수 있습니다.
    
    **su root** & **su - root** 와의 차이점은
    비밀번호 요구의 차이 (**su**의 경우 변환하는 계정의 비밀번호 요구, **sudo**는 현재 계정의 비밀번호 요구)
    **sudo log**의 유무
    
    sudo su로 root를 전환하게 됬을 때, **home 디렉토리가 /root 로 설정**됩니다.
    이는 환경변수 설정들을 root 계정의 상태로 **완전히 전환**합니다.
    sudo -s는 root를 전환하게 됬을 때, **home 디렉토리가 사용자의 홈 디렉토리**로 설정됩니다. 이는 현재 계정의 환경변수들이 **유지된 채**로 환경변수들을 root로 넘길 뿐입니다.
    
    [https://youngswooyoung.tistory.com/57](https://youngswooyoung.tistory.com/57)
    
- 계정관리
    - ****사용자 추가 : #**** useradd [옵션] 계정이름 ex) useradd -d test
        - d : 홈디렉토리를 지정
        - g : 그룹을 지정해서 사용자를 생성한다. 해당그룹이 존재하는 상태에만 가능
        - G : 기본그룹이외에 추가로 지정그룹에 속하게 한다.
        - c : 사용자에 대한 설명을 추가한다.
        - s : 사용자 쉘을 지정하여 생성
        - D : /etc/default/useradd에 설정된 유저추가에 대한 기본설정을 보여준다.
        
        ex) # useradd -g group1 test2 : group1에 test2계정을 만든다. group1을 미리 만들어 놓는다.
        
    - ****사용자 삭제 :**** # userdel [옵션] 계정이름 ex) userdel -rf test
        - f : 강제 삭제
        - r : 계정 삭제 시 모든 정보 삭제
        - 계정 삭제시 -rf 로 주로 사용
    - ****그룹 관리****
        
        ****그룹 생성 :**** # groupadd [옵션] 그룹이름
        
        - g [GID] : GID번호를 정해서 그룹생성
        - r : 0~500 사이의 GID 설정
        
        ****그룹 삭제 :**** # groupdel 그룹이름
        
        **그룹 관리** : # gpasswd 옵션
        
        - a user : 특정 그룹에 새로운 그룹멤버를 추가함. (gpasswd -a user groupname)
        - d user : 특정 그룹에서 지정한 그룹멤버를 제거함.
        - r : 특정 그룹의 패스워드를 제거함
        - R : 특정 그룹에 접근을 제한함
        - A user, ... : 특정 그룹의 그룹관리자를 설정함
        - M user, ... : 특정 그룹의 그룹멤버를 새로 설정함.
        
        ****그룹 수정 : #**** groupmod [옵션] 그룹이름
        
        - -n, new_group_name : 그룹명을 변경할때 사용합니다.
        
        **그룹 조회** : cat /etc/group
        
    - password 관리
        
        [https://webisfree.com/2018-04-19/리눅스(linux)-사용자-패스워드-변경-방법](https://webisfree.com/2018-04-19/%EB%A6%AC%EB%88%85%EC%8A%A4(linux)-%EC%82%AC%EC%9A%A9%EC%9E%90-%ED%8C%A8%EC%8A%A4%EC%9B%8C%EB%93%9C-%EB%B3%80%EA%B2%BD-%EB%B0%A9%EB%B2%95)
        
    - ****유저 정보조회, 모든 사용자 확인****
        
        ****유저 정보조회 : #**** id [옵션] 계정이름
        
        - g : 기본그룹의 GID 출력
        - G : 사용자가 속한 모든 그룹의 GID 출력
        - u : 사용자의 UID 출력
        - n : 위의 옵션과 함께 사용하며 이름도 함께 출력
        - # groups 계정이름 ( ex) # groups juyojeon) → user : user의 groups 출력
        
         ****모든 사용자 확인 :****  # cat /etc/passwd | grep bash
        
        • 형식은 ( ID/패스워드:UID:GID:설명:홈디렉토리:쉘 ) 이다.
        
    - ****사용자 정보수정 :**** # usermod [옵션] 계정이름
        - c : 사용자의 설명을 수정
        - d : 홈디렉토리를 변경
        - m : 홈디렉토리 변경시 파일을 옮긴다.
        - e : 계정종료일 변경
        - s : 기본 쉘 변경
        - u : UID변경
        - g : 기본 그룹 변경
        - G : 추가 그룹 변경
        - l : 사용자명 변경
        - L : 사용자 패스워드 LOCK (로그인 불가)
        - U : 패스워드 LOCK을 해제한다.
    - [https://devmg.tistory.com/83](https://devmg.tistory.com/83)
- Sudo 관리
    
    sudo 명령을 사용하면 기본적으로 루트 사용자로 프로그램을 실행할 수 있습니다. 이를 user에 추가하기 위해서는 두가지 방안을 동시에 적용해야 합니다. (기본적으로 wheel그룹은 sudo그룹이므로 1번만 적용해도 괜찮지만, 해당내용에 sudo그룹을 만들어야 하므로 2번도 수정하여야한다.)
    
    ![Screen Shot 2023-01-04 at 7.48.19 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-04_at_7.48.19_PM.png)
    
    1. 사용자를 "wheel" 그룹에 추가합니다. 이 그룹의 구성원은 sudo를 통해 모든 명령을 실행할 수 있으며 sudo를 사용할 때 암호로 자신을 인증하라는 메시지를 표시합니다.
    
    ```c
    usermod -aG wheel username
    ```
    
    1. 사용자 및 그룹의 sudo 권한은 /etc/sudoers 파일에 구성됩니다. 사용자를 이 파일에 추가하면 명령에 대한 사용자 지정 액세스 권한을 부여하고 사용자에 대한 사용자 지정 보안 정책을 구성할 수 있습니다.
    
    ```c
    visudo 명령어를 이용 or chmod변환을 통해 /etc/sudoers 파일을 편집한다.
    visudo
    
    /etc/sudoers
    userid      ALL=(ALL)    ALL : user에게 sudo 권한 제공
    %group    ALL=(ALL)    NOPASSWD: ALL
    : group맴버에게 sudo 권한 제공, password 입력없이 sudo 사용
    
    기본적으로 /etc/sudoers에서는 다음과 같은 설정
    root    ALL=(ALL)       ALL
    %wheel   ALL=(ALL)       ALL
    
    아래와 같이 바꾸자
    root    ALL=(ALL)       ALL
    %sudo   ALL=(ALL)       ALL
    ```
    
- Hostname 명령어
    
    호스트명을 확인하거나 설정하는 리눅스 명령어
    
    재부팅하면 원상복구되므로 주의해야 한다. (**[리눅스 호스트명 변경](https://zetawiki.com/wiki/%EB%A6%AC%EB%88%85%EC%8A%A4_%ED%98%B8%EC%8A%A4%ED%8A%B8%EB%AA%85_%EB%B3%80%EA%B2%BD)** 참조)
    
    **hostnamectl set-hostname 변경할이름 : 영구적으로 변경된다.**
    
    - a, --alias : 알리아스(alias)명 출력
    - d, --domain : 도메인명 출력
    - F, --file 파일명 : 지정한 파일에서 호스트명 설정
    - f, --fqdn, --long : [FQDN(Fully Qualified Domain Name)](https://itwiki.kr/index.php?title=FQDN&action=edit&redlink=1) 출력
    - h, --help : 사용법 출력
    - i, --ip : 호스트의 IP 주소를 출력한다.
    - n, --node : DECnet 노드(node)명을 출력한다.
    - s, --short : 짧은 형식의 호스트명을 출력한다. FQDN 정보에서 첫 번째 점(dot)까지 출력
    - V, --version : 버전 정보 출력
    - v, --verbose : 호스트 설정이나 호스트명을 자세히 출력
    - y, --yp, --nis : NIS 도메인명을 출력 또한 지정한 파일에서 NIS 도메인 이름을 설정
- Password 규정
    
    ```c
    /etc/login.defs (기존에 있던 계정에는 적용 안됨)
    
    PASS_MAX_DAYS : 최대 사용 기간, 30으로 설정
    PASS_MIN_DAYS : 비밀번호 변경 후 수정이 가능한 최소 경과일 수, 2로 설정
    PASS_WARN_AGE : Number of days warning given before a password expires, 7로 설정
    
    chage 명령어 (해당 계정만 적용) https://tragramming.tistory.com/87
    -l : 지정한 계정의 정보를 보여준다.
    -d : 최근 패스워드를 바꾼 날을 수정한다. 날짜로 지정할 경우에는 'YYYY-MM-DD' 형식을 따르고, 숫자로 지정할 경우 1970년 1월 1일부터의 경과일 수를 지정해 준다.
    -E : 계정의 만료일을 설정한다. 날짜로 지정할 경우에는 'YYYY-MM-DD' 형식을 따르고, 숫자로 지정할 경우 1970년 1월 1일부터의 경과일 수를 지정해 준다.
    -m : 패스워드 변경일로부터 최소 며칠이 경과해야 다른 패스워드로 변경할 수 있는지를 설정한다. 즉, 패스워드 최소 의무 사용일 수를 지정하는 옵션.
    -M : 패스워드 최종 변경일로부터 패스워드 변경 없이 사용할 수 있는 최대 일수 설정한다.
    -W : 패스워드 만료 며칠 전부터 사용자에게 경고 메시지를 보낼지를 설정한다.
    ```
    
    ```c
    /etc/security/pwquality.conf (기존에 있던 계정 적용 OK)
    
    difok : 이전 패스워드에는 없고 새 패스워드에만 있는 문자 개수, 7로 설정
    minlen : 새 패스워드의 허용 가능한 최소 크기, 10으로 설정
    dcredit : 새 패스워드에서 숫자로 얻을 수 있는 최대 점수. 0보다 작다면, 새 패스워드에서 숫자 최소 개수, -1으로 설정
    ucredit : 새 패스워드에서 대문자로 얻을 수 있는 최대 점수. 0보다 작다면, 새 패스워드에서 대문자 최소 개수, -1으로 설정
    lcredit : 새 패스워드에서 소문자로 얻을 수 있는 최대 점수. 0보다 작다면, 새 패스워드에서 소문자 최소 개수, -1으로 설정
    maxrepeat : 새 패스워드에서 연달아 나오는 같은 문자의 최대 개수. 값이 0이면 검사를 하지 않는다.
    3으로 설정 (3개 초과일 경우 error)
    usercheck : 0이 아니면 (다소 변경한) 패스워드에 사용자 이름이 어떤 형태로 포함돼 있는지 검사. 사용자 이름이 3글자보다 짧으면 수행하지 않는다. (기본값은 1)
    enforce_for_root : 패스워드를 바꾸려고 하는 사용자가 root인 경우에도 검사 실패 시 오류를 반환한다. 기본적으로 이 옵션이 꺼져 있는데, 실패한 검사에 대한 메시지는 찍지만 어쨌든 root는 패스워드를 바꿀 수 있다는 뜻이다. 참고로 root에게는 이전 패스워드를 묻지 않으므로 이전 패스워드와 새 패스워드를 비교하는 검사를 수행하지 않는다.
    
    https://wariua.github.io/man-pages-ko/pwquality.conf%285%29/
    ```
    
- Sudo 규정
    
    ```c
    visudo
    
    sudo를 사용할 수 있는 경로(명령어)를 제한하기 (보안경로설정, bin폴더에 있는 명령어만 실행가능)
    Defaults  secure_path = /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
    
    sudo 비밀번호 입력 시도 제한
    Defaults	passwd_tries = 3
    
    sudo 비밀번호 오류 시, 사용자 지정 메세지 출력
    Defaults	badpass_message = "ㅋwrong sudo password"
    
    sudo 입력 로그 저장
    Defaults	log_input
    sudo 출력 로그 저장
    Defaults	log_output
    
    로그파일 저장위치 설정
    Defaults	iolog_dir = "/var/log/sudo/"
    
    TTY 사용자 로그인 세션에서만 sudo 활성화 (ex) ssh name@localhost sudo command 차단)
    Defaults	requiretty
    
    https://kiki-100.tistory.com/122
    ```
    
- TTY
    
    콘솔, 터미널, tty는 서로 깊은 연관을 갖고 있는데 본래 이것들은 컴퓨터와 상호작용을 위한 장비를 뜻한다.
    
    - 유래
        
        과거 컴퓨터는 대학과 기업이 소유한 거대한 다중 사용자 시스템이였다.
        
        기계 자체는 일반 사용자가 방문하지 않는 안전한 방에 있었다.
        
        ![images_ginee_park_post_630fd7b0-c3a8-44c3-9dd4-b418f38989db_image.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/images_ginee_park_post_630fd7b0-c3a8-44c3-9dd4-b418f38989db_image.png)
        
        **대신 위 사진과 같이 저렴한 텔레타이프(TTY)를 터미널로 사용했다.**
        
        텔레타이프(TTY)는 주로 전신에서 타이핑된 메시지를 주고받는 데 사용되었지만, **정보를 컴퓨터에 입력하고 컴퓨터에서 정보를 가져오는 데**에도 사용할 수 있다.
        
        **많은 텔레타이프가 하나의 Unix 컴퓨터에 연결**됐다.모든 사용자는 자신의 텔레타이프 앞에 앉아 자신의 사용자 이름과 비밀번호로 Unix에 로그인했다.
        
        따라서 **Unix는 최초의 다중 사용자 운영 체제**가 되었고 ASR33은 최초의 Unix 터미널이 되었다.이러한 유래로 **TTY**라는 약어는 일반적으로 **Unix/Linux에서 터미널을 나타내는 데 사용**된다고 한다.
        
        컴퓨터를 조작할 때 사용하는 입출력 장치를 콘솔이라고 하고 명령조작에 사용하는 애플리케이션이나 OS자체를 콘솔 또는 콘솔애플리케이션이라고 하는데 보통 많은 사람들이 콘솔이라고 부른다. 또한 우리가 많이 사용하는 cmd도 콘솔이고 사용하는 터미널도 콘솔이다.
        
        리눅스 환경은 기본적으로 **TTY(Teletypewriter)** 위에 그러져 있다.
        
    - /dev (device)
        
        **￫ TTY (일반 CLI 콘솔)**
        
        **￫ TTYs (시리얼 tty)**
        
        **￫ PTS (기본 xwindows를 위한 가상 콘솔)**
        
        **￫ PTY ( 외부의 원격 접속을 위한 가상 콘솔)**
        
    
    터미널에서 **tty**라는 명령어를 실행해보면 **현재 커널과 연결된 가상 터미널 장치 이름을 확인**할 수 있다.
    
    **TTY**도 콘솔의 한 종류로 Ctrl-Alt-F1 ~ F6 키조합으로 사용할수있는 OS 에서 제공하는 가상콘솔 이다. 실제 물리적인 장치가 연결된것이 아니기 때문에 커널에서 터미널을 emulation 한다. Line discipline, TTY driver 의 기능은 위와같고 마찬가지로 백그라운드 getty 프로세스에의해 login prompt 가 제공됩니다. /dev/tty[번호] 파일이 사용된다. TTY화면간 이동은 ALT+F1~F6이며 GUI환경 복귀는 ALT+F7이다.
    
    오늘날의 **터미널은 GUI에서 실행되는 이전 물리적 터미널의 소프트웨어 표현**이다.사용자가 명령을 입력하고 텍스트를 인쇄할 수 있는 **인터페이스를 제공**한다.
    
    **Linux 서버에 SSH로 연결할 때 로컬 컴퓨터에서 실행하고 명령을 입력하는 프로그램은 터미널이다.**
    
    만약 보안 툴인 selinux 를 'encforce'로써 작동하여 사용하고 있다면 사용자도 다른 tty로 접근이 불가할 뿐만이 아니라 다른 pts, pty에 외부에서의 접근이 불가 하다. 
    
    사용자도 tty를 사용하기 위해서는 selinux를 'permissive'로 정책을 바꿔줘야 한다.
    
- Cron, Wall
    - **Cron** : A scheduler or timer that automatically starts a job, program, task.
        
        데몬: 멀티태스킹 운영 체제에서 데몬은 사용자가 직접적으로 제어하지 않고, 백그라운드에서 돌면서 여러 작업을 하는 프로그램 (크론은 데몬이다.)
        
        크론은 기본적으로 백그라운드에서 작동한다. 따라서 echo나 printf명령어등은 사용하고있는 터미널에 출력되지 않으며, 이를 해결하기 위해 **wall**명령어를 사용하여야 한다.
        
        **cron**디먼은 모든 쉘에 대해 디폴트 환경을 제공하며 다음을 정의합니다. HOME, LOGNAME, SHELL(=/usr/bin/sh), PATH(=/usr/bin).
        
    - **wall : wall** 명령은 로그인한 모든 사용자에게 메시지를 기록(전송)합니다.
        
        wall [flag] ****[ *Message*]
        
        *Message* 매개변수가 지정되지 않는 경우, wall ****명령은 EOF(파일 끝) 문자에 도달할 때까지 표준 입력에서 메시지를 읽습니다. 그러면 로그인한 모든 사용자에게 메시지가 전송됩니다.
        
    - **crontab** 명령은 cron 작업을 제출, 편집, 나열 또는 제거합니다.
        - **crontab** [[ [-e](https://www.ibm.com/docs/ko/aix/7.2?topic=c-crontab-command#crontab__row-d3e136024) | [-l](https://www.ibm.com/docs/ko/aix/7.2?topic=c-crontab-command#crontab__row-d3e136047) | [-r](https://www.ibm.com/docs/ko/aix/7.2?topic=c-crontab-command#crontab__row-d3e136058) | [-v](https://www.ibm.com/docs/ko/aix/7.2?topic=c-crontab-command#crontab__row-d3e136072) ] [user name] | *File*]] - 플래그 설명
            
            **-e** : 사용자의 **crontab** 파일 사본을 편집하거나 유효한 *UserName*에 대한 **crontab** 파일이 없을 경우 빈 파일을 작성하여 편집합니다. 편집이 완료되면 파일은 사용자의 **crontab** 파일과 같은 **crontab** 디렉토리로 복사됩니다.
            
            **-l :** 사용자의 **crontab** 파일을 나열합니다.
            
            **-r : crontab** 디렉토리에서 사용자의**crontab** 파일을 제거합니다.
            
            **-v** : 사용자의 cron 작업의 상태를 나열합니다.**
            
        - **crontab** 파일에는 각 cron 작업에 대한 항목이 있습니다. 항목은 줄 바꾸기 문자로 분리됩니다. 각 **crontab** 파일 항목은 다음 양식에서 공백 또는 탭으로 분리된 여섯 개의 필드를 포함합니다.
            
            [minute] [hour] [day_of_month] [month] [weekday] [command]
            
            각 필드에 대해 값을 지정해야 합니다. *command* 필드를 제외한 이들 필드는 다음을 포함할 수 있습니다.
            
            - 지정된 범위의 숫자. 5월에 명령을 실행하려면, **월** 필드에 5를 지정하십시오.
            - 포함 범위를 나타내며, 대시로 구분된 두 개의 숫자. 화요일부터 금요일까지 **cron** 작업을 실행하려면, **weekday** 필드에 2-5를 입력하십시오.
            - 쉼표로 분리된 숫자 리스트. 1월의 첫 날과 마지막 날에 명령을 실행하려면, **일** 필드에 1,31을 지정합니다.
            - 대시로 분리된 두 개의 숫자 조합은 경계를 포함하는 범위를 나타내고, 쉼표로 분리된 숫자 리스트를 함께 사용할 수 있습니다. 1월의 1일, 10일에서 16일, 마지막 날에 명령을 실행하려면 day_of_month 필드에 1,10-16,31을 지정합니다. 위의 두 개 점도 함께 사용할 수 있습니다.
            - *****(별표)는 모든 허용된 값을 의미합니다.
        - **/etc/crontab**을 통해서도 수정 가능
            
            [minute] [hour] [day_of_month] [month] [weekday] [username] [command]
            
        
        ex) 30 6 * * * /usr/bin/calendar : 매일 6시 30분에 **calendar**명령을 실행
        
        ex) */10 * * * * /home/monitoring.sh | wall : 10분마다 sh실행 및 메세지 전송
        
- Simple script (**monitoring.sh**)
    - 출력할 내용
        
        - The architecture of your operating system and its kernel version. 
        
        - 운영체제와 커널의 버전에 대한 구조 
        
        - The number of physical processors 
        
        - 물리 프로세서들의 수 
        
        - The number of virtual processors. 
        
        - 가상 프로세서들의 수 
        
        - The current available RAM on your server and its utilization rate as a percentage. 
        
        - 현재 서버에서 사용가능한 RAM과 백분율로 표현된 사용률. 
        
        - The current available memory on your server and its utilization rate as a percentage. 
        
        - 현재 서버에서 사용가능한 memory와 백분율로 표현된 사용률. 
        
        - The current utilization rate of your processors as a percentage. 
        
        - 백분율로 표현된 프로세서들의 현재 사용률. 
        
        - The date and time of the last reboot. 
        
        - 마지막으로 재시작된 날짜와 시간. 
        
        - Whether LVM is active or not. 
        
        - LVM의 활성화 여부. 
        
        - The number of active connections. 
        
        - 활성화된 연결들의 개수. 
        
        - The number of users using the server. 
        
        - 서버를 사용하고 있는 유저의 수. 
        
        - The IPv4 address of your server and its MAC (Media Access Control) address. 
        
        - 서버의 IPv4 주소와 MAC 주소. 
        
        - The number of commands executed with the sudo program 
        
        - sudo 프로그램으로 실행된 명령의 수.
        
    - 운영체제와 커널의 버전에 대한 구조 : uname -a
        
        [https://www.joinc.co.kr/w/man/1/uname](https://www.joinc.co.kr/w/man/1/uname)
        
        지정된 시스템 정보를 출력한다. 옵션이 없을 경우 **-s** 옵션과 같은 결과를 보여준다.
        
        **-a, --all** : 모든 정보를 보여준다. 아래의 모든 옵션을 사용한 것과 동일한 효과
        
    - physical CPU, vCPU
        
        vCPU = 코어당 스레드 X 소켓당 코어 X 소켓 
        
        → lscpu | grep -E '^CPU\(s\):' | awk '{print $2}’
        
        physical CPU = 소켓당 코어 X 소켓
        
        ```
        예시
        
        $ lscpu | grep -E '^Thread|^Core|^Socket|^CPU\('
        CPU(s):                32
        Thread(s) per core:    2
        Core(s) per socket:    8
        Socket(s):             2
        
        lscpu | grep -E '^CPU\(s\):' | rev | cut -d ' ' -f1 | rev = 32
        
        lscpu | grep -E '^Core|^Socket' | rev | cut -d ' ' -f1 | rev | awk 'BEGIN {mul = 1} {mul *= $1} END {print mul}' = 16
        ```
        
        [https://unix.stackexchange.com/questions/218074/how-to-know-number-of-cores-of-a-system-in-linux](https://unix.stackexchange.com/questions/218074/how-to-know-number-of-cores-of-a-system-in-linux)
        
    - **free** [옵션] 명령어
        
        커널에서 사용하는 버퍼와 캐시뿐만 아니라 시스템에서 사용 가능한 물리적 메모리와 스왑 메모리의 총량을 표시합니다. 또한, free 명령어는 /proc/meminfo 의 정보를 가져와 분석하여 수집된다.
        
        free 명령어를 실행하게 되면 물리 메모리와 스왑 메모리에 대해 각 컬럼에 대한 값들이 나오게 된다.
        
        ```bash
                      total     used     free   shared  buff/cache   available
        Mem:         498684    80788   304432     4540      113464      400244
        Swap:       2097148        0   097148
        ```
        
        - **[total]**설치된 총 메모리의 크기 (/proc/meminfo 의 MemTotal 및 SwapTotal)
        - **[used]**사용중인 메모리 크기 또는 사용중인 스왑 메모리 크기 (total - free - buffers - cache 으로 계산)
        - **[free]**사용하지 않은 메모리 크기 또는 사용되지 않은 스왑 메모리 크기 (/proc/meminfo 의 MemFree 및 SwapFree)total - used - buff/cache
        - **[shared]**주로 tmpfs(메모리 파일시스템) 에서 사용하는 메모리. 여러 프로세스에서 사용할 수 있는 공유 메모리
        - **[buffers]**커널 buffer 로 사용중인 메모리
        - **[cache]**page cache 와 slab 으로 사용중인 메모리
        - **[buff/cache]**버퍼와 캐시 메모리의 합
        - **[available]**Swapping 없이 새 응용 프로그램을 사용하는 데 사용할 수 있는 메모리의 크기.
    - **df** [옵션] [*FileSystem* ... | *File...* ] 명령어
        - **df** 명령은 파일 시스템의 전체 공간 및 사용 가능 공간에 대한 정보를 표시합니다.
            
            *FileSystem* 매개변수는 파일 시스템이 상주하는 장치의 이름, 파일 시스템이 마운트되는 디렉토리 또는 파일 시스템의 상대 경로 이름을 지정합니다. *File* 매개변수는 마운트 위치가 아닌 파일 또는 디렉토리를 지정합니다. *File* 매개변수가 지정되는 경우 **df** 명령은 파일 또는 디렉토리가 상주하는 파일 시스템에 대한 정보를 표시합니다.
            
             파일 시스템 통계는 기본적으로 512바이트 블록 단위로 표시됩니다.
            
        
        *FileSystem* 또는 *File* 매개변수를 지정하지 않는 경우 **df** 명령은 모든 현재 마운트된 파일 시스템에 대한 정보를 표시합니다.
        
        **df -B** : 출력하기 전에 크기를 SIZE로 조정 **df -BM** or df -BK or df -BG (**df -BM** : MiB(1024) 단위로 변경후 출력)
        
        [https://d-life93.tistory.com/365](https://d-life93.tistory.com/365)     
        
    - **mpstat** [ **[-O](https://www.ibm.com/docs/ko/aix/7.2?topic=m-mpstat-command#mpstat__row-d3e176741)***Options* ] [ **-@** *wparname* ] [ *interval* [ *count* ] ] 명령어
        
        **mpstat** 명령은 시스템에서 모든 논리적인 프로세서를 위해 성능 통계를 수집하고 표시합니다. 사용자는 통계가 표시되는 횟수 및 데이터가 갱신되는 간격을 모두 정의할 수 있습니다.
        
        옵션 없이 **mpstat** 명령은 부팅 시간 이후로 모든 논리적인 프로세서를 위한 성능 통계를 포함하는 단일 보고서를 생성합니다.
        
        레드햇 계열은 `yum install -y sysstat` 으로 설치
        
        - 각 열의 의미는 아래와 같다.
            - %usr : nice값이 적용되지 않은 Process들의 User Code를 구동하는데 이용한 CPU 사용률을 나타낸다. 대부분의 User Process들의 사용률을 의미한다.
            - %nice : nice값이 적용된 Process들의 User Code들을 구동하는데 이용한 CPU 사용률을 나타낸다.
            - %sys : Kernel Code를 구동하는데 이용한 CPU 사용률 중에서 id, wa, hi, si의 사용률/대기율 제외한 사용률을 의미한다.
            - %iowait : I/O Wait로 인한 CPU 대기율을 나타낸다.
            - %irq : 순수 Hardware Interrupt 처리를 위해 사용된 CPU 사용률을 나타낸다. Kernel의 Interrupt Flag를 Set만 하는 Top Havles 부분을 처리를 위한 CPU 사용률을 의미한다.
            - %soft : Top Halves에서 Set한 Interrupt Flag에 따라서 실제 Interrupt를 처리하는 Bottom Havles의 CPU 사용률을 나타낸다.
            - %steal : Kernel이 Hypervisor가 제어하는 가상 머신 안에서 동작할 때, Hypervisor나 다른 가상 머신에 의해서 사용을 뺏긴 CPU 사용률을 나타낸다.
            - %guest : Hypervisor를 통해서 가상 머신을 구동하는 경우, nice값이 적용되지 않은 가상 머신의 vCPU를 구동하는데 이용한 CPU 사용률을 의미한다.
            - %gnice : Hypervisor를 통해서 가상 머신을 구동하는 경우, nice값이 적용된 가상 머신의 vCPU를 구동하는데 이용한 CPU 사용률을 의미한다.
            - %idle : I/O Wait를 제외한 CPU의 대기율를 나타낸다.
            
            [https://ssup2.github.io/command_tool/mpstat/](https://ssup2.github.io/command_tool/mpstat/)
            
    - **who**, **whoami**, **w**
        - **who [option]** : 현재 시스템에 로그인되어 있는 사용자를 출력해 주는 명령입니다.
            
            
            | -a | -b,-d,-l,-p,-r,-t,-T,-u 를 통합한 옵션 |
            | --- | --- |
            | -b | 시스템부팅시간 출력 |
            | -d | 죽은 프로세스 출력 |
            | -H | 출력되는 정보의 헤더를 출력 |
            | -l | 로그인프로세스 출력 |
            | -p | ini프로세스에 의해 발생된 프로세스 출력 |
            | -q | 로그인된 사용자명과 사용자수 출력 |
            | -r | 런 레벨 출력 |
            | -s | 사용자명, 라인, 시간출력(명령어 없이쓰는 who와 같음) |
            | -t | 시스템시간이 변경된 정보출력 |
            | -T | 사용자의 메세지 상태 출력 |
            | -u | 로그인한 사용자 목록 출력 |
        - **whoami :** 사용중인 권한자를 출력해 주는 명령입니다.
            
            부가적으로 설명을 드리면 로그인된 사용자명이 아니고 권한자에 주의 깊게 보셔야 합니다.
            권한자를 출력하기 때문에 su명령으로 바꾸어서 들어갈시 su명령으로 권한을 부여받은 사용자명이 뜹니다. 반대로 who는 사용자를 출력하기 때문에 su를 입력한 사용자가 뜹니다.
            
        - **w** : 로그인된 사용자와 수행중인 작업을 출력해주는 명령입니다.
            
            w [option]
            
    - **netstat** 명령어 : 활성 연결의 다양한 네트워크 관련 데이터 구조의 내용을 기호로 표시합니다.
        
        처음에 설치가 안되어 있음 : sudo yum install net-tools
        
        네트워크의 상태를 모니터링하기 위한 도구로 사용한다. 송/수신 연결 정보, 라우팅 테이블, 송/수신 포트, 패킷통계 모니터링이 일반적인 용도다.
        
        *-a, --all* 옵션을 사용하면 사용중인 모든 포트를 나열합니다.
        
        *-l, --listening* 옵션을 사용하면 listening 중인 모든 TCP/UDP/Unix Domain socket을 표시합니다.
        
        ***-t, –tcp* 옵션은 listening 중인 TCP 소켓만 표시합니다.**
        
        - 여러 옵션을 조합해서 listening 중인 모든 소켓에 대한 상세 정보를 볼수 있으며 옵션에 대한 설명은 하단을 참고하세요.
            
            *-c, --continuous* 옵션을 사용하면 종료되지 않고 계속 정보를 갱신하면서 표시합니다.
            
            *-r, --route* 옵션으로 현재 시스템의 커널 라우팅 정보를 볼 수 있습니다.
            
        
        [https://www.lesstif.com/ws/netstat-43844201.html](https://www.lesstif.com/ws/netstat-43844201.html)
        
        - ss [옵션] → PATH 설정 필요함
            
            It is good to note that running the ss command with and without sudo privileges might give different outputs—meaning the ss command lists information based on the user context.
            
            [https://linuxhint.com/ss-command-linux/](https://linuxhint.com/ss-command-linux/)
            
    - **hostname -I**
        - i, --ip : 호스트의 IP 주소를 출력한다.
    - MAC 주소, **ifconfig**(→ PATH경로가 기본과달라서 입력시 /sbin/ifconfig 입력해야함)
        
        **MAC 주소(Media Access Control Address)는 네트워크 세그먼트의 [데이터 링크 계층](https://ko.wikipedia.org/wiki/%EB%8D%B0%EC%9D%B4%ED%84%B0_%EB%A7%81%ED%81%AC_%EA%B3%84%EC%B8%B5)에서 통신을 위한 네트워크 인터페이스에 할당된 고유 식별자이다.**
        MAC 주소는 [이더넷](https://ko.wikipedia.org/wiki/%EC%9D%B4%EB%8D%94%EB%84%B7)과 [와이파이](https://ko.wikipedia.org/wiki/%EC%99%80%EC%9D%B4%ED%8C%8C%EC%9D%B4)를 포함한 대부분의 [IEEE 802](https://ko.wikipedia.org/wiki/IEEE_802) 네트워크 기술에 [네트워크 주소](https://ko.wikipedia.org/w/index.php?title=%ED%9C%B4%EB%8C%80%ED%8F%B0_%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC_%EC%A3%BC%EC%86%8C&action=edit&redlink=1)로 사용된다. 논리적으로 MAC 주소는 [매체 접근 제어](https://ko.wikipedia.org/wiki/%EB%A7%A4%EC%B2%B4_%EC%A0%91%EA%B7%BC_%EC%A0%9C%EC%96%B4) 프로토콜이라는 [OSI 모델](https://ko.wikipedia.org/wiki/OSI_%EB%AA%A8%EB%8D%B8)의 하위 계층에서 사용된다.
        
        **ifconfig 명령을 사용하여 네트워크 인터페이스에 주소를 지정하고 현재 네트워크 인터페이스 구성 정보를 구성 또는 표시할 수 있습니다.** TCP/IP를 사용하여 네트워크의 네트워크 인터페이스 매개변수를 구성 또는 표시합니다. ifconfig 명령은 시스템 시작 시 시스템이 있는 각 인터페이스의 네트워크 주소를 정의하기 위해 사용해야 합니다. 시스템 시작 후 인터페이스 주소 및 기타 해당 작동 매개변수를 재지정하는 데 사용할 수도 있습니다. 네트워크 인터페이스 구성은 실행 시스템에서 유지되며 시스템을 재시작할 때마다 재설정되어야 합니다.
        
        - **ifconfig 명령**
            
            **ifconfig 명령을 사용하여 네트워크 인터페이스에 주소를 지정하고 현재 네트워크 인터페이스 구성 정보를 구성 또는 표시할 수 있습니다.** TCP/IP를 사용하여 네트워크의 네트워크 인터페이스 매개변수를 구성 또는 표시합니다. ifconfig 명령은 시스템 시작 시 시스템이 있는 각 인터페이스의 네트워크 주소를 정의하기 위해 사용해야 합니다. 시스템 시작 후 인터페이스 주소 및 기타 해당 작동 매개변수를 재지정하는 데 사용할 수도 있습니다. 네트워크 인터페이스 구성은 실행 시스템에서 유지되며 시스템을 재시작할 때마다 재설정되어야 합니다.
            
    - **Sudo Log**
        
        Sudo 규정에서 수정한 sudo log폴더를 불러와서 명령어수를 찾아 제공한다.
        기본적으로 cron이 폴더 접근권한이 없어서 수정해야한다. (sudo chmod -R 755 /var/log/sudo)
        
    - **Code**
        
        ```c
        printf "#Architecture: "
        uname -a
        
        printf "#CPU physical : "
        lscpu | grep -E '^Core|^Socket' | rev | cut -d ' ' -f1 | rev | awk 'BEGIN {mul = 1} {mul *= $1} END {print mul}'
        
        printf "#vCPU : "
        lscpu | grep -E '^CPU\(s\):' | rev | cut -d ' ' -f1 | rev
        
        printf "#Memory Usage: "
        free -m | grep Mem | awk '{printf"%d/%dMiB (%.2f%%)\n", $3, $2, $3/$2 * 100}'
        
        tdisk=`df -BM | grep -v ^Filesystem | awk '{sum += $2} END {printf sum}'`
        udisk=`df -BM | grep -v ^Filesystem | awk '{sum += $3} END {printf sum}'`
        echo $udisk $tdisk | awk '{printf "#Disk Usage: %d/%dMiB (%d%%)\n", $1, $2, $1/$2*100}'
        
        printf "#CPU load: "
        mpstat | grep all | rev | cut -d ' ' -f1 | rev | awk '{printf "%.2f%%\n", 100-$1}'
        
        printf "#Last boot: "
        who -b | awk '{printf $3" "$4"\n"}'
        
        printf "#LVM use: "
        if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ] ; then printf "yes\n" ; else printf "no\n" ; fi
        
        printf "#Connections TCP : "
        netstat -t | grep '^tcp' | wc -l | tr -d '\n'
        printf " ESTABLISHED\n"
        
        printf "#User log: "
        who | wc -l
        
        printf "#Network: IP "
        hostname -I | tr -d '\n'
        printf "("
        /sbin/ifconfig | grep 'ether' | awk '{printf $2}'
        printf ")\n"
        
        printf "#Sudo : "
        ls -lR /var/log/sudo/ | grep log$ | wc -l | tr -d '\n'
        printf " cmd\n"
        ```
        
- **lighttpd** 설치 및 활성화
    
    ```c
    시스템에서 EPEL 저장소를 활성화하고 다음 명령을 사용하여 소프트웨어 패키지를 업데이트해야합니다.
    # yum -y install epel-release
    # yum -y update
    
    EPEL 저장소를 활성화했으면 이제 다음 명령을 실행하여 Lighttpd를 설치할 수 있습니다.
    # yum install lighttpd
    
    Lighttpd 패키지가 설치되면 서비스를 시작하고 활성화하여 부팅시 자동으로 시작되도록 할 수 있으며 다음 명령을 사용하여 상태를 확인하십시오.
    # systemctl start lighttpd
    # systemctl enable lighttpd
    # systemctl status lighttpd
    
    다음 명령을 사용하여 시스템에 설치된 Lighttpd의 버전을 확인합니다.
    # lighttpd -v
    lighttpd/1.4.67 (ssl) - a light and fast webserver
    
    방화벽에서 HTTP 및 HTTPS 트래픽을 허용해야합니다.
    # firewall-cmd --permanent --zone=public --add-service=http
    # firewall-cmd --permanent --zone=public --add-service=https
    # firewall-cmd --zone=public --add-port=80/tcp --permanent
    (http의 기본 포트는 80이고, https의 기본 포트는 443이다.)
    # firewall-cmd --reload
    # firewall-cmd --list-all
    
    오류 수정
    vim /etc/lighttpd/lighttpd.conf
    server.use-ipv6 = "disabled"
    server.port = 80
    
    setsebool -P httpd_setrlimit on
    
    재부팅 후 systemctl status lighttpd로 추가 오류 확인
    
    포트포워딩 설정
    호스트ip     호스트port    게스트ip   게스트port
    127.0.0.1   8080                    80
    
    이제 브라우저를 열고 다음 URL을 가리키면 Lighttpd 웹 서버가 작동하는지 확인할 수 있습니다.
    http://127.0.0.1:8080
    ```
    
    [https://ko.linux-console.net/?p=744#gsc.tab=0](https://ko.linux-console.net/?p=744#gsc.tab=0)
    
    [https://velog.io/@peeeeeter_j/lighttpd](https://velog.io/@peeeeeter_j/lighttpd)
    
- ****MariaDB,**** **PHP 설치 및 연동**
    
    ```c
    다음 명령을 사용하여 Lighttpd 에 대한 MySQL 지원을 설치
    yum -y install mariadb mariadb-server
    
    MariaDB를 시작하고 활성화하고 상태를 확인
    # systemctl start mariadb.service
    # systemctl enable mariadb.service
    # systemctl status mariadb.service
    
    다음 명령을 실행하여 MariaDB 설치를 보호
    # mysql_secure_installation
    
    MySQL 서버에 연결을 시도하고 터미널에서 다음 명령을 사용하여 데이터베이스 서버의 기존 데이터베이스를 검토
    # mysql -u root -p
    password입력
    MariaDB [(none)]> show databases;
    
    https://ko.linux-console.net/?p=127#gsc.tab=0
    ```
    
    ```c
    필요한 확장명과 함께 PHP 를 설치 (7.4버전으로 설치, https://www.linuxcapable.com/how-to-install-enable-remi-rpm-repository-on-rocky-linux-9/)
    sudo dnf upgrade --refresh -y
    sudo dnf config-manager --set-enabled crb
    sudo dnf install \
        https://dl.fedoraproject.org/pub/epel/epel-release-latest-9.noarch.rpm \
        https://dl.fedoraproject.org/pub/epel/epel-next-release-latest-9.noarch.rpm
    sudo dnf install dnf-utils http://rpms.remirepo.net/enterprise/remi-release-9.rpm -y
    dnf module list php
    sudo dnf module enable php:remi-7.4 -y
    sudo dnf install php php-mysqlnd php-pdo php-gd php-mbstring
    
    PHP 를 설치 한 후 PHP 및 FastCGI 를 Lighttpd 에 지원하도록 설정하기 위한 패키지들도 설치
    yum -y install php-fpm lighttpd-fastcgi
    
    /etc/php-fpm.d/www.conf 파일 편집 -> 사용자 및 그룹을 lighttpd 로 설정 & socket
    ; RPM: apache Choosed to be able to access some dir as httpd
    user = lighttpd 
    ; RPM: Keep a group allowed to write in log dir.
    group = lighttpd
    
    ; Note: This value is mandatory.
    listen = 127.0.0.1:9000
    
    ; When set, listen.owner and listen.group are ignored
    listen.acl_users = lighttpd
    
    ; Default Value: any
    listen.allowed_clients = 127.0.0.1
    
    이제 PHP-FPM 서비스를 시작하고 다음 명령을 사용하여 부팅 할 때 자동으로 시작되도록 설정
    # systemctl start php-fpm.service
    # systemctl enable php-fpm.service
    
    /etc/php.ini 파일을 편집 -> 48%
    cgi.fix_pathinfo=1
    
    /etc/lighttpd/modules.conf 파일을 편집
    ## FastCGI (mod_fastcgi)
    ##
    include "conf.d/fastcgi.conf"
    
    /etc/lighttpd/conf.d/fastcgi.conf 파일을 편집
    fastcgi.server += ( ".php" =>
            ((
                    "host" => "127.0.0.1",
                    "port" => "9000",
                    "broken-scriptfilename" => "enable"
            ))
    )
    
    firewall-cmd --zone=public --add-port=80/tcp --permanent
    
    /var/www/lighttpd/info.php 파일을 생성하고 편집
    <?php
    phpinfo();
    ?>
    
    SELinux가 활성화된 상태에서는 HTTP 웹 서버에서 tcp 포트를 접근할수 없어, 다음과 같이 HTTP에 대한 설정을 변경
    setsebool -P httpd_can_network_connect 1
    setsebool -P nis_enabled 1
    
    php info페이지로 php-fpm연동 확인
    http://127.0.0.1:8080/info.php
    ```
    
    ![Screen Shot 2023-01-10 at 3.54.54 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-10_at_3.54.54_PM.png)
    
    - PHP-FPM과 CGI의 차이와 설정법
        
        **사용 방안**
        
        - 동적 페이지를 사용할 때 CGI보다 더 빠른 속도로 작업이 진행되도록 할 수 있습니다.
        
        **CGI와 FastCGI**
        
        - 로그인, 게시글 등록과 같이 동적인 페이지 사용 시 웹 외부 프로그램(WAS 등)에서 처리하는 방법이 필요합니다.
        - 외부 프로그램이 내용을 전달받아 HTML 파일로 반환하는 단계를 CGI라고 합니다.
        - PHP-FPM는 PHP FastCGI Process Manager의 약자로 여기서 FastCGI는 CGI보다 더 빠른 처리를 뜻합니다.
        
        **일반 CGI의 경우**
        
        - 요청(Request)가 인입될 때마다 신규 프로세스를 생성/구동하여 이 과정에서 부하 증가 등의 이슈가 발생됩니다.
        
        **FastCGI의 경우**
        
        - FastCGI 실행 시 미리 프로세스를 생성한 뒤 해당 프로세스를 활용함으로써 일반 속도가 빠르고 부하가 적습니다.
        - 이론 상으로 볼 시 일반 CGI를 FastCGI를 변경하여 처리할 경우 3~30배의 성능 개선 효과를 볼 수 있습니다.
        
        **[출처]** [[CentOS] PHP-FPM과 CGI의 차이와 설정법](https://blog.naver.com/ncloud24/221948188915)|**작성자** [엔클라우드24](https://blog.naver.com/ncloud24)
        
    - cgi.fix_pathinfo=1
        
        php.ini 파일의 cgi.fix_pathinfo의 값이 1일 경우,
        [http://localhost/bad.hack/aa.php와](http://localhost/bad.hack/aa.php%EC%99%80) 같이 비정상적인 접근을 할 수 있다.
        
        bad.hack을 서버에서 읽어들여 보안상 위험한 일을 초래한다.
        
- DB 생성 및 Wordpress 설치 및 연동
    
    ```c
    https://blog.innern.net/120
    
    mysql     # mariadb 접속
    CREATE DATABASE wdDB;     # wdDB 라는 데이터베이스 생성
    GRANT ALL PRIVILEGES ON wdDB.*  TO  wdadmin@localhost  IDENTIFIED BY  '1234';  # wdDB에 접속 가능한 wdadmin이라는 password 1234로 생성
    exit    # mariadb 나가기
    ```
    
    ```c
    mysql -u wdadmin -p     # wdadmin 계정으로 mariadb를 접속합니다.
    Enter password:1234     # 패스워드를 입력합니다.
    show databases;     # 접근 가능한 데이터베이스를 검색합니다.
    ```
    
    ![Screen Shot 2023-01-10 at 4.36.31 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-10_at_4.36.31_PM.png)
    
    ```c
    yum -y install wget     # wget을 설치합니다.
    wget https://ko.wordpress.org/wordpress-6.0-ko_KR.tar.gz    #wordpress를 다운받습니다.
    yum -y install tar     # tar을 설치합니다.
    tar xfz wordpress-6.0-ko_KR.tar.gz     # 다운받은 wordpress 파일의 압축을 해제합니다.
    mv wordpress  /var/www/lighttpd     # wordpress 파일을 /var/www/lighttpd 디렉토리로 이동합니다.
    cd /var/www/lighttpd     # lighttpd 디렉토리로 이동합니다.
    chmod 707 -R wordpress     # wordpress의 폴더 권한을 707로 변경합니다.
    
    cd wordpress     # wordpress 파일로 이동합니다.
    cp wp-config-sample.php wp-config.php     # wordpress 설정 파일 샘플을 wp-config.php로 복사합니다.
    
    /var/www/lighttpd/wordpress/wp-config.php 수정
    23 define( 'DB_NAME', 'wdDB' );     # 해당 줄에 데이터베이스의 이름을 입력합니다.(위에서 생성한 wpDB로 입력)
    25 /** Database username */
    26 define( 'DB_USER', 'wdadmin' );     # 해당 줄은 db에 접근한 계정을 입력합니다.(위에서 생성한 wdadmin로 입력)
    28 /** Database password */
    29 define( 'DB_PASSWORD', '1234' );     # 해당 줄은 mariadb계정의 password를 입력합니다.(위에서 생성한 1234로 입력)
    
    wp-config.php 파일 밑부분에 인증키를 설정
    인증키는 아래 주소에서 나오는 키를 그대로 복사해 붙여넣으면 된다.
    https://api.wordpress.org/secret-key/1.1/salt/
    
    vi /etc/lighttpd/lighttpd.conf
    Append / modify
    server.dir-listing = "enable" # wordpress의 dir-listing 가능하도록 설정
    
    semanage fcontext -a -t httpd_sys_content_t /var/www/lighttpd/
    sudo restorecon -v /var/www/lighttpd/
    chcon -t httpd_sys_rw_content_t /var/www/lighttpd/wordpress/
    chcon -Rv --type=httpd_sys_content_t /var/www/lighttpd/
    # setsebool -P httpd_can_network_connect on
    # setsebool -P httpd_enable_homedirs=1
    # setsebool -P httpd_use_nfs=1
    
    systemctl restart lighttpd
    
    http://http://127.0.0.1:8080/wordpress 를 입력하여 wordpress를 접속
    
    https://techblog.jeppson.org/2016/10/install-wordpress-centos-7/
    ```
    
    ![Screen Shot 2023-01-10 at 4.52.37 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-10_at_4.52.37_PM.png)
    
    ![Screen Shot 2023-01-10 at 5.20.12 PM.png](Born2beroot%20Rocky%20Linux%204b0aef6d787e4310bd7a047fa5ce620e/Screen_Shot_2023-01-10_at_5.20.12_PM.png)
    
- psacct서비스, signature.txt
    
    ```c
    psacct 설치
    dnf -y install psacct
    systemctl start psacct
    systemctl enable psacct
    
    # 일자별 총 로그인 시간
    [root@localhost ~]# ac -d
    # 사용자별 로그인 시간 확인
    [root@localhost ~]# ac -p
    # 일자별, 사용자 로그인 시간 확인
    [root@localhost ~]# ac -d -p
    
    미래를 위해 스냅샷 생성
    ~/goinfre/Folder Rocktlinux.vdi 확인
    
    shasum Rocktlinux.vdi
    -> ex) 1eb91a06c63a644377717526fdc06a929e92e67e
    
    제출할 깃클론 폴더 최상위 디텍토리에 signature.txt 생성
    vim signature.txt
    ```
