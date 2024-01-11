FROM alpine:3.18

ARG PHP_VER=81

RUN apk update && apk upgrade && apk add --no-cache dumb-init \
    php${PHP_VER} php${PHP_VER}-fpm php${PHP_VER}-mysqli \
    php${PHP_VER}-json php${PHP_VER}-curl php${PHP_VER}-dom \
    php${PHP_VER}-pecl-imagick php${PHP_VER}-pecl-igbinary php${PHP_VER}-intl \
    php${PHP_VER}-exif php${PHP_VER}-fileinfo php${PHP_VER}-mbstring \
    php${PHP_VER}-openssl php${PHP_VER}-xml php${PHP_VER}-zip \
    php${PHP_VER}-redis php${PHP_VER}-phar curl && \
    sed -i "s|listen = 127.0.0.1:9000|listen = 9000|g" /etc/php${PHP_VER}/php-fpm.d/www.conf

WORKDIR /var/www

# https://make.wordpress.org/cli/handbook/guides/installing/#recommended-installation
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

COPY ./tools/configuration.sh .

ENTRYPOINT [ "/usr/bin/dumb-init", "--", "sh", "configuration.sh" ]
