PROGRAM := test

all : $(PROGRAM)

clean:
	rm obj/*.o $(PROGRAM)

SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LIBS := libmicrohttpd
CXXFLAGS := -g `pkg-config --cflags $(LIBS)` -std=c++0x -I/usr/include/flycapture/ -DWITH_GPU -DTRACK -DROTATE
LDFLAGS := `pkg-config --libs $(LIBS)`


$(PROGRAM): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS) -c -o $@ $<

