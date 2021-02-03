# docker run --rm -v "$PWD/int-pointer-ref":/usr/src/myapp -w /usr/src/myapp gcc:4.9 /bin/bash -c "gcc -o run main.c; echo $?; ./run; echo $?"
docker run --rm -v "$PWD/int-pointer-ref":/usr/src/myapp -w /usr/src/myapp gcc:4.9 /bin/bash -c "g++ -Wall -o run main.c; echo $?; ./run; echo $?"
