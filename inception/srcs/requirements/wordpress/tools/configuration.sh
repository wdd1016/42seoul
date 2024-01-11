#!/bin/sh

#https://make.wordpress.org/cli/handbook/how-to/how-to-install/
if [ ! -e "/var/www/wp-config.php" ]; then
  wp core download --allow-root
  wp config create --dbname=${DB_NAME} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_PASSWORD} \
  --dbcharset='utf8' --dbhost=${DB_HOST} --skip-check
  wp core install --title=${WP_NAME} --url=${DOMAIN_NAME} --admin_user=${WP_ADMIN_USER} --admin_password=${WP_ADMIN_PASSWORD} --admin_email=${WP_ADMIN_EMAIL}
  wp user create ${WP_USER} ${WP_USER_EMAIL} --user_pass=${WP_USER_PASSWORD}
fi

/usr/sbin/php-fpm81 -F