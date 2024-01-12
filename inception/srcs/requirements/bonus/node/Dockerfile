FROM debian:bullseye

RUN apt update && apt install -y nodejs npm

WORKDIR /app

COPY ./conf/package.json /app

RUN npm install

COPY ./conf /app

EXPOSE 3000

CMD ["node", "server.js"]