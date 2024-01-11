#!/bin/bash

docker stop $(docker ps -qa) 2>/dev/null
docker rm $(docker ps -qa) 2>/dev/null
docker rmi -f $(docker images -qa) 2>/dev/null
docker volume rm $(docker volume ls -q) 2>/dev/null
docker network rm $(docker network ls -q) 2>/dev/null
rm -rf /home/juyojeon/data/mysql/*
rm -rf /home/juyojeon/data/www/*

exit 0