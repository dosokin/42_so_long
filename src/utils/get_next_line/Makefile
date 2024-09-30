SRCS = get_next_line.c get_next_line_utils.c
HEADERS = get_next_line.h
OBJS = $(SRCS:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror -g
LIB = get_next_line.a

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) rcs $(LIB) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(LIB)