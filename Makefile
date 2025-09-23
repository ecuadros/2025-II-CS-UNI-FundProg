CXX = g++
CXXFLAGS = -std=c++17 -Wunused-variable -g -pthread # Añadido -pthread
LDFLAGS = -pthread # Añadido -pthread

TARGET = main
SRCS =  main.cpp funcion.cpp parametros.cpp compareFunc.cpp \
		array.cpp matrix.cpp \
		sorting.cpp \
		recursion.cpp \
		const.cpp \
		structs.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean