CC_EXEC = g++
CC_FLASGS = -g

CC = ${CC_EXEC} ${CC_FLASGS}

SF_LIB = -lsfml-graphics -lsfml-window -lsfml-system

BUILD_DR = build


all: snap.out


snap.out: ${BUILD_DR}/main.o 
    ${CC} ${BUILD_DR}/main.o ${SF_LIB} -o snap.out

${BUILD_DR}/main.o: main.cpp Data_base.hpp
    ${CC} -c main.cpp -o ${BUILD_DR}/main.o

${BUILD_DR}/Input.o: Input.cpp
    ${CC} -c Input.cpp -o ${BUILD_DR}/Input.o

${BUILD_DR}/Data_base.o: Data_base.cpp 
    ${CC} -c Data_base.cpp -o ${BUILD_DR}/Data_base.o

clean:
    rm -rf build/ && mkdir -p build