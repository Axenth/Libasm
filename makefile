# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jlensing <jlensing@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/17 14:06:13 by jlensing      #+#    #+#                  #
#    Updated: 2020/10/17 11:26:51 by jlensing      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
SRCS =  ft_strlen.s ft_read.s ft_write.s ft_strcmp.s ft_strcpy.s ft_strdup.s
OBJS = $(SRCS:.s=.o)
CC = nasm 
CC_FLAGS = -f macho64

%.o: %.s libasm.h
	$(CC) $(CC_FLAGS) $<

all:	$(NAME)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all