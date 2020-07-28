# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihhan <jihhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/12 19:53:43 by jihhan            #+#    #+#              #
#    Updated: 2020/07/27 13:11:20 by jihhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#REQUIRED TARGETS: $(NAME) all clean fclean
# Header
CFLAGS				= -Wall -Werror -Wextra -I. -c
.DEFAULT_GOAL		:= all
NAME				= ft_printf.a

SOURCES				= $(wildcard srcs/ft_*.c)
OBJECTS				= $(patsubst %.c,%.o,$(SOURCES))

.PHONY: all
all: $(NAME) additionals

.PHONY: additionals
additionals:
	$(MAKE) -C additionals

$(NAME): $(OBJECTS) additionals
	ar rcs $@ $(OBJECTS)
	ranlib $@

.PHONY: clean
clean:
	@/bin/rm -f $(OBJECTS)
	$(MAKE) clean -C additionals

.PHONY: fclean
fclean: clean
	@/bin/rm -f $(NAME)
	$(MAKE) fclean -C additionals

.PHONY: re
re: fclean all
