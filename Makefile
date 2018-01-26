bindir = bin/
objdir = obj/

program = $(bindir)A1
testStack = $(bindir)testStackA1
testMazeSolver = $(bindir)testMazeSolverA1

programSources = main.c fileIO.c list.c mazeSolver.c stack.c
testStackSources = testStack.c list.c stack.c
testMazeSolverSources = testMazeSolver.c fileIO.c list.c mazeSolver.c stack.c

programObjects = $(patsubst %.c,$(objdir)%.o,$(programSources))
testStackObjects = $(patsubst %.c,$(objdir)%.o,$(testStackSources))
testMazeSolverObjects = $(patsubst %.c,$(objdir)%.o,$(testMazeSolverSources))

CFLAGS = -Wall -std=c99 -Iinclude -pedantic -g
VPATH = include:src

all : $(program) $(testStack) $(testMazeSolver)

$(program) : $(programObjects)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $(program) $(programObjects)

$(testStack) : $(testStackObjects)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $(testStack) $(testStackObjects)

$(testMazeSolver) : $(testMazeSolverObjects)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $(testMazeSolver) $(testMazeSolverObjects)

$(objdir)%.o : %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	-@$(RM) $(program) $(testStack) $(testMazeSolver) $(programObjects) $(testStackObjects) $(testMazeSolverObjects)
