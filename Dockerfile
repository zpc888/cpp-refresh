FROM gcc:4.9
COPY ./int-pointer-ref/. /usr/src/myapp
WORKDIR /usr/src/myapp
RUN gcc -o myapp main.c
CMD ["./myapp"]
