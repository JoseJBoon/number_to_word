NAME	:=	rush02
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror -g3
BIN		:=	bin
SRCS	:=	dict_utils.c ftput.c getline.c list.c main.c numtoword.c\
			numtoword_utils.c parse.c str_utils.c str_utils_extra.c
OBJS	:=	$(SRCS:%.c=$(BIN)/%.o)

all: $(NAME)

$(NAME): $(BIN) $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(BIN)/%.o:	ex00/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(BIN):
	mkdir $(BIN)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(BIN)
	$(RM) $(NAME)

fclean: clean

re: clean all

.PHONY: all clean fclean re
