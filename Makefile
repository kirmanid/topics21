OBJS = main.cpp appState.cpp renderWindow.cpp
NAME = executeable
all: $(OBJS)
	g++ $(OBJS) -w -lSDL2 -lSDL_ttf -o $(NAME)
