# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 16:28:46 by rezzahra          #+#    #+#              #
#    Updated: 2021/12/06 21:17:34 by rezzahra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.c mandelbrot.c ft_atoi.c julia.c

OBJS			= $(SRCS:.c=.o)

FLAGS			= -Wall -Wextra -Werror

NAME			= fractal

all:			$(NAME)

$(NAME):		$(SRCS)
				gcc  $(FLAGS) -lmlx -framework OpenGL -framework Appkit $(SRCS) -o $(NAME)
clean:
				rm -f $(OBJS)
				
fclean:			clean
				rm -f $(NAME) 

re:				fclean $(NAME)
