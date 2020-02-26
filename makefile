CC = g++
CFLAGS = -Wall
EXEC_NAME = analyseur_lexical
OBJ_FILES = automate.o etat.o lexer.o main.o symbole.o

all : $(EXEC_NAME) clean

clean :
	rm -rf *.o

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) 

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

cleanAll : clean
	rm -rf $(EXEC_NAME)
