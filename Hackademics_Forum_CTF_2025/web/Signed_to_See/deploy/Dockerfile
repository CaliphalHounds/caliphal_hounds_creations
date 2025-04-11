FROM ubuntu:20.04

ENV TZ=Europe/Kiev
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone



RUN apt-get update -y && apt-get install -y apache2 php

RUN echo "export SECRET_KEY=1lzdf872875" >> /etc/apache2/envvars


COPY files/ /files/
COPY webserverFiles/* /var/www/html/
COPY main.sh /main.sh

RUN chmod +x main.sh
RUN rm /var/www/html/index.html
RUN chmod 444 /files/*
RUN chmod 555 /files

EXPOSE 80

ENTRYPOINT ["/main.sh"]
