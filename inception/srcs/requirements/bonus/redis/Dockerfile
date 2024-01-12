FROM alpine:3.18

# https://redis.io/docs/reference/eviction/
RUN apk update && apk upgrade && apk add --no-cache redis && \
    sed -i "s|bind 127.0.0.1|#bind 127.0.0.1|g"  /etc/redis.conf && \
    sed -i "s|# maxmemory <bytes>|maxmemory 256mb|g"  /etc/redis.conf && \
    sed -i "s|protected-mode yes|protected-mode no|g"  /etc/redis.conf && \
    sed -i "s/^# maxmemory-policy noeviction/maxmemory-policy allkeys-lru/" /etc/redis.conf

EXPOSE 6379

CMD [ "/etc/redis.conf" ]

ENTRYPOINT [ "redis-server" ]