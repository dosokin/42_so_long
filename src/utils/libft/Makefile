SRCS = ft_strdup.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strndup.c \
	ft_calloc.c \
	ft_itoa.c \
	ft_strlcat.c \
	ft_split.c \
	custom_strcat.c
OBJS = $(SRCS:.c=.o)
LIB  = libft.a
CFLAGS = -Wall -Wextra -Werror -g
CC = cc

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) rcs $(LIB) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(LIB)