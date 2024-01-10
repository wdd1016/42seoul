#!/bin/sh

# datadir에 기본 셋업을 진행한다.
mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db

# rc pid 실행을 수행한다.
rc default

# SQL 쿼리문을 넣기위해 잠시 실행한다.
rc-service mariadb start

# mysql_installation 설정
mysql -e "CREATE USER IF NOT EXISTS ${MYSQL_USER}@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"

# wordpress database 생성
mysql -e "CREATE DATABASE IF NOT EXISTS ${DB_NAME};"
mysql -e "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO ${MYSQL_USER}@'%' ;"
mysql -e "FLUSH PRIVILEGES";

# mysql_root 설정
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"

rc-service mariadb stop

chown -R mysql:mysql /var/lib/mysql

/usr/bin/mysqld --user=mysql