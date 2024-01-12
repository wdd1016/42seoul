FROM debian:bullseye

RUN apt-get update && apt install -y php7.4 php7.4-mysql wget dumb-init

WORKDIR /var/www

RUN wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php && \
    mv adminer-4.8.1.php index.php

EXPOSE 8080

ENTRYPOINT [ "/usr/bin/dumb-init", "--", "php", "-S", "[::]:8080", "-t", "/var/www" ]
