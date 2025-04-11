FROM node:16

ENV FLAG=hfctf{poluc1onam3_l4_fl4G}

WORKDIR /usr/src/app

COPY package*.json ./
COPY index.js ./

RUN npm install

EXPOSE 7777

CMD node index.js
