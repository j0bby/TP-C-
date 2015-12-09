EXE = EXE
CCOMP = g++
RM = rm
ECHO = echo
INT = Log.h Cible.h Collection.h Graphe.h
REAL = $(INT: .h =. cpp)
OBJ = $(INT: .h = .o) 
OUTPUT = -o
RMFLAGS = -f
CPPFLAGS = -wall -DMAP
EDGFLAGS =
LIBS =
LIBPATH =
INCPATH =

$(EXE) : $(OBJ) main.o
	$(ECHO) "Edition des liens"
	$(EDL) $(OUTPUT) $(EXE) $(EDLFLAGS) $(LIBPATH) $(OBJ) main.o $(LIBS)

$(TEST) : $(OBJ) test.o
	$(ECHO) "Edition des liens"
	$(EDL) $(OUTPUT) $(TEST) $(EDLFLAGS) $(LIBPATH) $(OBJ) test.o $(LIBS)

clean :
	$(ECHO) "Clean"
	$(RM) $(RMFLAGS) $(EXE) $(TEST) $(OBJ) core.

%.o : %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<
Log.o : Log.h
Cible.o : Cible.h Log.h
Collection.o : Collection.h Cible.h
Graphe.o : Graphe.h Collection.h
main.o : $(INT)
test.o : $(INT)
