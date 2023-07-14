ToolFrameworkPath:= /usr/local/hk/ToolFrameworkCore/src

CXXFLAGS:= g++ -O3 -fPIC

objects:=$(patsubst %.cpp, %.o, $(wildcard *.cpp))

all: $(objects)
	$(CXXFLAGS) --shared  $(objects) -o libDataModel.so

%.o: %.cpp
	$(CXXFLAGS) -c $< -o $@  -I ./ -I $(ToolFrameworkPath)/include -L $(ToolFrameworkPath)/lib -lStore -lLogging -lpthread

clean:
	rm $(objects)
	rm libDataModel.so
