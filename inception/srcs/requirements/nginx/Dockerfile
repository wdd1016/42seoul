FROM alpine:3.18

RUN apk update && apk upgrade && apk add --no-cache nginx openssl dumb-init

COPY ./conf/nginx.conf /etc/nginx/http.d/nginx.conf
COPY ./tools/configuration.sh .

EXPOSE 443

CMD [ "/usr/bin/dumb-init", "--", "sh", "configuration.sh" ]