CXX           := g++
LD            := g++


EXEC          := fcg-gen
FLAGS         := -Wall
CXXFLAGS      := $(FLAGS)
LDFLAGS       := $(FLAGS)
INC           := -I include
SRC           := $(wildcard src/*.cpp)
OBJ           := $(SRC:src/%.cpp=tmp/%.o)
LIBS          := -lm

EXEC_TEST     := testunits
FLAGS_TEST    := $(FLAGS)
CXXFLAGS_TEST := $(CXXFLAGS)
LDFLAGS_TEST  := $(LDFLAGS)
INC_TEST      := $(INC) -I testunits/include -I /usr/include
SRC_TEST      := $(wildcard testunits/*.cpp)
OBJ_TEST      := $(filter-out tmp/main.o, $(OBJ)) $(SRC_TEST:tst/%.cpp=tmp/%.o)
LIBS_TEST     := $(LIBS) 
.SUFFIXES:

# --------------------------------------------------------------

.PHONY: all

all:$(EXEC)

$(EXEC):$(OBJ)
	@$(LD) $(LDFLAGS)  -o $@ $^ $(LIBS)  && echo "[OK]  $@"

# --------------------------------------------------------------

.PHONY: test
test: out/$(EXEC_TEST)

runtest : test
	@./out/$(EXEC_TEST) -s -d yes
	

out/$(EXEC_TEST): $(OBJ_TEST)
	@$(LD) $(LDFLAGS_TEST) $^ -o $@  $(INC_TEST) $(LIBS_TEST) && echo "[OK]  $@"

# --------------------------------------------------------------

tmp/%.o: src/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< $(INC) -o $@ && echo "[OK]  $@"

tmp/%.o: tst/%.cpp
	@$(CXX) $(CXXFLAGS_TEST) -c $< $(INC_TEST) -o $@ && echo "[OK]  $@"

# --------------------------------------------------------------

.PHONY: clean, clear
clean clear:
	@rm -f out/* && echo "[CL]  out/"
	@rm -f tmp/* && echo "[CL]  tmp/"

.PHONY: archive, zip
archive zip:
	@zip -x out/* tmp/* lib/* -q -r out/$(EXEC)-$(shell date '+%F').zip . && echo "[OK]  out/$(EXEC)-$(shell date '+%F').zip"
