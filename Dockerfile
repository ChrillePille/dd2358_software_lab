FROM ubuntu

ENV TZ=Europe/Stockholm
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

WORKDIR /
COPY assignment/ assignment/

RUN apt-get update && apt-get install -y build-essential autoconf autoconf-archive autotools-dev git gfortran pkg-config libopenblas-dev && \
    apt install -y libgtest-dev libgmock-dev

WORKDIR /assignment
RUN ./configure && make && make check

WORKDIR /
ADD start.sh /
RUN chmod +x /start.sh
CMD ["/start.sh"]