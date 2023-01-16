SRC = philo.c ft_libft.c check_args.c make_philos.c make_philos_utils.c time_stuff.c 

OSRC=$(SRC:.c=.o)

AR= ar -rcs
NAME= philo

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OSRC)
#	@$(CC) -Wall -Wextra -Werror -pthread -fsanitize=leak $^ -o $@
	@$(CC) -Wall -Wextra -Werror -pthread $^ -o $@
	@printf "$(RED)--------Philosophers DONE--------$(RESET)\n"

%.o : %.c
	@printf "hana kan compili f$(GREEN) $< $(RESET) \n"
	@$(CC) -Wall -Wextra -Werror -c $<

clean:
	@rm -rf *.o

fclean:
	@rm -rf *.o $(NAME)

re: fclean all

.PHONY: all clean fclean re