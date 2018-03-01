NAME = qos
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADERS = -I ./include/

SRC_PATH = ./srcs
LIB_PATH = ./libs

SRCS =  qos.c\
        error.c\
		read.c\
		listqos.c\
		ping.c\
		core.c

LIBS = ft_strsplit.c ft_putchar.c ft_putstr.c ft_putendl.c ft_strtrim.c ft_strreplace_ip.c ft_putnbr.c

OBJS = $(patsubst %.c,$(LIB_PATH)/%.o,$(LIBS)) $(patsubst %.c,$(SRC_PATH)/%.o,$(SRCS))

$(NAME): $(OBJS)
	@($(CC) $(CFLAGS) $(HEADERS) -o $@ $^)
	@echo "--------------------------------------------------"
	@echo "          Compilation of $@ has finish            "
	@echo "            QOS : v 1.0 - By Tybbow               "
	@echo "            For Section Metrologie                "
	@echo "--------------------------------------------------"

all : $(NAME)

%.o: %.c
	@($(CC) -c $(CFLAGS) $(HEADERS) -o $@ $^)
	@echo " OK  $@"

clean:
	@(rm -rf $(OBJS))
	@echo "--------------------------------------------------"
	@echo " OK          $(NAME): Objects deleted"
	@echo "--------------------------------------------------"

fclean: clean
	@(rm -rf $(NAME))
	@echo "--------------------------------------------------"
	@echo " OK           $(NAME): All deleted"
	@echo "--------------------------------------------------"

re: fclean all

.PHONY: fclean clean all
