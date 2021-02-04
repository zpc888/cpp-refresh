if [ $# -eq 0 ]; then
   echo "Usage: $(basename $0) folder [-c|--clean]"
   exit 1;
fi
FOLDER=$1
if [ ! -d $1 ]; then
   echo "Error: no such folder [$FOLDER] under [$PWD]" 
   exit 2
fi
if [ $# -eq 2 ] && [ $2 == '-c' -o $2 == '--clean' ]; then
    echo "make clean on gcc-docker container instance"
	docker run --rm -v "$PWD/$FOLDER":/usr/src/myapp -w /usr/src/myapp gcc:4.9 /bin/bash -c "make clean"
else
    echo "make and run on gcc-docker container instance"
	docker run --rm -v "$PWD/$FOLDER":/usr/src/myapp -w /usr/src/myapp gcc:4.9 /bin/bash -c "make; [ $? -eq 0 ] && ./run"
fi
