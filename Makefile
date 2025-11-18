CXX = g++
CXXFLAGS = -std=c++17 -g -pthread -MMD -MP
LDFLAGS =

TARGET = main
SRCS = main.cpp funcion.cpp parametros.cpp compareFunc.cpp \
		array.cpp matrix.cpp \
		recursion.cpp \
		const.cpp \
		structs.cpp \
		BinaryFiles.cpp \
		MoveObject.cpp \
		DemoComplex.cpp \
		academic/person.cpp \
		academic/student.cpp academic/professor.cpp \
		academic/DemoAcademic.cpp
# 		sorting.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) $(DEPS)

# Incluir todas las dependencias generadas
-include $(DEPS)

.PHONY: all clean