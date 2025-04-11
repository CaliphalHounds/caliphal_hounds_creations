FROM python:3.6

RUN apt-get update -y

WORKDIR /app
COPY app .
RUN pip3 install -r requirements.txt
EXPOSE 37000

ENTRYPOINT python3 app.py & gunicorn --bind 0.0.0.0:37000 app:app --workers 10 -t 15
