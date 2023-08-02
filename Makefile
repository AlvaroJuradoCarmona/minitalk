# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 12:18:29 by ajurado-          #+#    #+#              #
#    Updated: 2023/06/17 13:16:12 by ajurado-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME	= client
SERVER_NAME	= server

CLIENT_OBJ	= client.o
SERVER_OBJ	= server.o

NORMFLAG 	= -R CheckForbiddenSourceHeader

CFLAGS		= -Wall -Wextra -Werror #-g -fsanitize=address
INCLUDES	= -I $(LIBFT)
LIBFT		= libft
LIBFT_A		= $(LIBFT)/libft.a
RM			= rm -rf

all: $(CLIENT_NAME) $(SERVER_NAME)

$(LIBFT_A):
	make -C $(LIBFT)

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CLIENT_NAME): $(LIBFT_A) $(CLIENT_OBJ)
	gcc $(CFLAGS) client.c $(LIBFT_A) $(INCLUDES) -o $(CLIENT_NAME)

$(SERVER_NAME): $(LIBFT_A) $(SERVER_OBJ)
	gcc $(CFLAGS) server.c $(LIBFT_A) $(INCLUDES) -o $(SERVER_NAME)

clean: 
	make clean -C $(LIBFT)
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

fclean:	clean
	$(RM) $(LIBFT_A)
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re:		fclean all

norm:
	norminette $(NORMFLAG)

.PHONY:	all clean fclean re norm