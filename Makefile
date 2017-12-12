# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: legrivel <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/11 16:25:45 by legrivel     #+#   ##    ##    #+#        #
#    Updated: 2017/12/11 23:20:51 by legrivel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_ls
SRCS = main.c options.c
OBJS = $(SRCS:.c=.o)
SRCS_PATH = ./srcs/
INCS_PATH = ./includes/
FLAGS = -Wall -Wextra -Werror -fsanitize=leak
COMPILER = clang

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) -I $(INCS_PATH) $(OBJS) -o $(NAME) libft/libft.a

%.o: $(SRCS_PATH)%.c
	$(COMPILER) $(FLAGS) -I $(INCS_PATH) -c $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
