#!/bin/sh

# rc pid 실행을 수행한다.
rc default

# 잠시 실행한다.
service vsftpd start

adduser -h /var/www -s /bin/false -D ${FTP_USER}
echo "${FTP_USER}:${FTP_PASSWORD}" | /usr/sbin/chpasswd
adduser ${FTP_USER} root

service vsftpd stop

/usr/sbin/vsftpd "/etc/vsftpd/vsftpd.conf"