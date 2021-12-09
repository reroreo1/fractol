# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 16:28:46 by rezzahra          #+#    #+#              #
#    Updated: 2021/12/09 19:48:41 by rezzahra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_atoi.c ft_itof.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_strjoin.c \
					ft_strlen.c ft_substr.c julia.c main.c mandelbrot.c ft_isdigit.c func.c

OBJS			= $(SRCS:.c=.o)

FLAGS			= -Wall -Wextra -Werror -g -fsanitize=address

NAME			= fractal

all:			$(NAME)

$(NAME):		$(SRCS)
				gcc  $(FLAGS) -lmlx -framework OpenGL -framework Appkit $(SRCS) -o $(NAME)
clean:
				rm -f $(OBJS)
				
fclean:			clean
				rm -f $(NAME) 

re:				fclean $(NAME)
