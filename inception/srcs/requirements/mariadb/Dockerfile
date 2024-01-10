FROM alpine:3.18

RUN apk update && apk upgrade && apk add --no-cache mariadb mariadb-client openrc dumb-init && \
    sed -i "s|\[mysqld\]|\[mysqld\]\nskip-host-cache\nskip-name-resolve\nbind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf && \
    sed -i "s|skip-networking|skip-networking=0|g" /etc/my.cnf.d/mariadb-server.cnf

EXPOSE 3306

COPY ./tools/configuration.sh .

ENTRYPOINT [ "/usr/bin/dumb-init", "--", "sh", "configuration.sh"]