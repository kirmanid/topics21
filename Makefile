OBJS = main.cpp appState.cpp renderWindow.cpp
NAME = executeable
all: $(OBJS)
	g++ $(OBJS) -w -lSDL2 -o $(NAME)
