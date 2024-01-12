FROM debian:bullseye

RUN apt-get update && apt-get -y install mariadb-client dumb-init \
    php7.4 php7.4-fpm php7.4-mysql php7.4-cgi \
    php7.4-json php7.4-curl php7.4-intl \
    php7.4-common php7.4-mbstring php7.4-gd php7.4-cli \
    php7.4-xml php7.4-zip \
    php7.4-redis redis curl

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
  && chmod +x wp-cli.phar \
  && mv wp-cli.phar /usr/local/bin/wp

COPY ./tools/www.conf /etc/php/7.4/fpm/pool.d/www.conf

RUN mkdir /run/php

EXPOSE 9000

COPY ./tools/configuration.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/configuration.sh

WORKDIR /var/www

ENTRYPOINT [ "/usr/bin/dumb-init", "--", "sh", "/usr/local/bin/configuration.sh" ]
