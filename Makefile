SRC = $(wildcard src/*.c)
CFLAGS = -W -Wall -Wextra -Werror
TARGET = brainfuck_converter

all : $(TARGET)

$(TARGET) :
	$(CC) $(SRC) -o $@ $(FLAGS)

clean :
	$(RM) *.bf

fclean :
	$(RM) $(TARGET)

re : fclean all
