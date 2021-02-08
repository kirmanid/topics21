OBJS = main.cpp
NAME = executeable
all: $(OBJS)
	g++ $(OBJS) -w -lSDL2 -o $(NAME)
