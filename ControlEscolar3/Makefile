PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

OBJS = ControlEscolar3.o Conexion.o Alumno.o Profesor.o Materia.o

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else
	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

all:	ControlEscolar3

ControlEscolar3:	$(OBJS)
	$(CXX) -o $@ $^ -lpqxx -lpq

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ -lpqxx -lpq$<

clean:
	rm -fr ControlEscolar3 $(OBJS)
