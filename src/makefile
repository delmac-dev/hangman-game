DIR = C:\Users\Delmac\Desktop\Kill_Shot
SOURCES = $(wildcard *.cpp) $(wildcard **/*.cpp)
FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

all:
	g++ -I${DIR}/include -L${DIR}/lib -o ${DIR}/bin/wgg ${SOURCES} ${FLAGS} && start ${DIR}/bin/minu