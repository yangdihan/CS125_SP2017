EXENAME = testscene
OBJS = png.o rgbapixel.o image.o testscene.o scene.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

testscene.o : testscene.cpp png.h rgbapixel.h image.h scene.h
	$(CXX) $(CXXFLAGS) testscene.cpp

png.o : png.cpp png.h rgbapixel.h 
	$(CXX) $(CXXFLAGS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(CXX) $(CXXFLAGS) rgbapixel.cpp

image.o : image.cpp image.h
	$(CXX) $(CXXFLAGS) image.cpp

scene.o : scene.cpp scene.h
	$(CXX) $(CXXFLAGS) scene.cpp


clean :
	-rm -f *.o $(EXENAME)
