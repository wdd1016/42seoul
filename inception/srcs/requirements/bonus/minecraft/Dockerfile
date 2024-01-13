FROM debian:bullseye

RUN apt update && apt -y upgrade
RUN apt install -y vim iputils-ping wget curl tar dumb-init
RUN apt install -y openjdk-17-jdk openjdk-17-jre

WORKDIR /server

COPY tools/minecraft_server.1.20.4.jar /usr/bin/server.jar
COPY tools/eula.txt .

EXPOSE 25565

ENTRYPOINT [ "/usr/bin/dumb-init", "--", "java", "-Xmx1024M", "-Xms1024M", "-jar", "/usr/bin/server.jar", "nogui" ]