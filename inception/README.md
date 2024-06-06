# Inception

# 핵심 포인트

- Docker, Docker compose
- SSL, TLS

# 정리

- Docker, Docker compose설치
    
    [https://suucong.tistory.com/58](https://suucong.tistory.com/58)
    
    ```cpp
    sudo apt install docker
    
    sudo apt install docker-compose
    ```

    
- SSL, TLS
    
    [https://aws-hyoh.tistory.com/11](https://aws-hyoh.tistory.com/11)

    
- 보안
    
    기본적으로 .env파일을 이용하여 버전관리 코드 공유 프로그램에 노출되지 않도록 조심
    
    그렇다고 평문으로 저장한 .env파일이 안전한지는 의문 → Docker (compose)의 Secret기능, AWS Secrets Manager, Parameter Store등의 보안장치를 통해 추가적인 안전장치 도입 가능
    
    하지만 subject에 따라 .env파일 이용

    
- Redirect by /etc/hosts
    
    [https://ko.wikipedia.org/wiki/Hosts](https://ko.wikipedia.org/wiki/Hosts)
    
    hosts 파일은 운영 체제가 호스트 이름을 IP 주소에 매핑할 때 사용하는 컴퓨터 파일이다. 이 hosts 파일은 플레인 텍스트 파일이며 전통적으로 hosts라는 이름을 사용한다.
    
    기존 [localhost](http://localhost)부분은 유지하고, 맨 아랫줄에 127.0.0.1 intra_id.42.fr 을 추가한다.


- 진행 방법

    Ubuntu Desktop 22.04.4 LTS (https://releases.ubuntu.com/jammy/)

    sudo apt install ssh
    sudo apt install docker.io
    sudo apt install make
    sudo vi /etc/hosts

    https://intraid.42.fr
    https://intraid.42.fr/wp-login.php
    https://intraid.42.fr/wp-admin/options-general.php?page=redis-cache

    <node static webpage>
    localhost:3000

    <adminer page>
    localhost:8080

    <ftp>
    sudo docker inspect ftp
    -> "IPAddress": "A.B.C.D"

    ftp A.B.C.D
    ftp_id 입력
    ftp_pw 입력

    ls
    get fillname
