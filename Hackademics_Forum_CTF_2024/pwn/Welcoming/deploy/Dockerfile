FROM debian:12.5-slim

RUN apt-get update && apt-get upgrade -y

RUN useradd -d /home/ctf/ -m -p ctf -s /bin/bash ctf
RUN echo "ctf:ctf" | chpasswd

WORKDIR /home/ctf

COPY ./files . 

RUN chown -R root:root /home/ctf
RUN chmod 555 ./ynetd
RUN chmod 555 ./welcoming
RUN chmod 444 ./flag.txt

USER ctf
EXPOSE 37004

CMD ./ynetd -p 37004 ./welcoming
