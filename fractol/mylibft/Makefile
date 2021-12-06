# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 16:28:46 by rezzahra          #+#    #+#              #
#    Updated: 2021/11/10 17:56:11 by rezzahra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c
					
OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
					ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c
BONUS_OBJS		= $(BONUS:.c=.o)

FLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)

bonus:			$(BONUS_OBJS)

%.o: %.c
				gcc $(FLAGS) -c $< -o $@
				ar rc $(NAME) $@
clean:
				rm -f $(OBJS) $(BONUS_OBJS)

fclean:			clean
				rm -f $(NAME) 

re:				fclean $(NAME)
