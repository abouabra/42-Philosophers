SRC = philo.c ft_libft.c check_args.c make_philos.c make_philos_utils.c time_stuff.c 

SRC_DIR = src/
OBJ_DIR = obj/
OSRC= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

NAME= philo

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RESET = \033[0m

all: ascii $(NAME)

$(NAME): $(OSRC)
	@$(CC) -Wall -Wextra -Werror -pthread -I includes $^ -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:
	@rm -rf $(OBJ_DIR) $(NAME)

re: fclean all



ascii:
	@clear
	@printf "$(GREEN)\
                                                                                                                   																							\n\
                                                                                                                                                                                                           \n\
PPPPPPPPPPPPPPPPP   hhhhhhh               iiii  lllllll                                                                       hhhhhhh                                                                      \n\
P::::::::::::::::P  h:::::h              i::::i l:::::l                                                                       h:::::h                                                                      \n\
P::::::PPPPPP:::::P h:::::h               iiii  l:::::l                                                                       h:::::h                                                                      \n\
PP:::::P     P:::::Ph:::::h                     l:::::l                                                                       h:::::h                                                                      \n\
  P::::P     P:::::P h::::h hhhhh       iiiiiii  l::::l    ooooooooooo       ssssssssss      ooooooooooo   ppppp   ppppppppp   h::::h hhhhh           eeeeeeeeeeee    rrrrr   rrrrrrrrr       ssssssssss   \n\
  P::::P     P:::::P h::::hh:::::hhh    i:::::i  l::::l  oo:::::::::::oo   ss::::::::::s   oo:::::::::::oo p::::ppp:::::::::p  h::::hh:::::hhh      ee::::::::::::ee  r::::rrr:::::::::r    ss::::::::::s  \n\
  P::::PPPPPP:::::P  h::::::::::::::hh   i::::i  l::::l o:::::::::::::::oss:::::::::::::s o:::::::::::::::op:::::::::::::::::p h::::::::::::::hh   e::::::eeeee:::::eer:::::::::::::::::r ss:::::::::::::s \n\
  P:::::::::::::PP   h:::::::hhh::::::h  i::::i  l::::l o:::::ooooo:::::os::::::ssss:::::so:::::ooooo:::::opp::::::ppppp::::::ph:::::::hhh::::::h e::::::e     e:::::err::::::rrrrr::::::rs::::::ssss:::::s\n\
  P::::PPPPPPPPP     h::::::h   h::::::h i::::i  l::::l o::::o     o::::o s:::::s  ssssss o::::o     o::::o p:::::p     p:::::ph::::::h   h::::::he:::::::eeeee::::::e r:::::r     r:::::r s:::::s  ssssss \n\
  P::::P             h:::::h     h:::::h i::::i  l::::l o::::o     o::::o   s::::::s      o::::o     o::::o p:::::p     p:::::ph:::::h     h:::::he:::::::::::::::::e  r:::::r     rrrrrrr   s::::::s      \n\
  P::::P             h:::::h     h:::::h i::::i  l::::l o::::o     o::::o      s::::::s   o::::o     o::::o p:::::p     p:::::ph:::::h     h:::::he::::::eeeeeeeeeee   r:::::r                  s::::::s   \n\
  P::::P             h:::::h     h:::::h i::::i  l::::l o::::o     o::::ossssss   s:::::s o::::o     o::::o p:::::p    p::::::ph:::::h     h:::::he:::::::e            r:::::r            ssssss   s:::::s \n\
PP::::::PP           h:::::h     h:::::hi::::::il::::::lo:::::ooooo:::::os:::::ssss::::::so:::::ooooo:::::o p:::::ppppp:::::::ph:::::h     h:::::he::::::::e           r:::::r            s:::::ssss::::::s\n\
P::::::::P           h:::::h     h:::::hi::::::il::::::lo:::::::::::::::os::::::::::::::s o:::::::::::::::o p::::::::::::::::p h:::::h     h:::::h e::::::::eeeeeeee   r:::::r            s::::::::::::::s \n\
P::::::::P           h:::::h     h:::::hi::::::il::::::l oo:::::::::::oo  s:::::::::::ss   oo:::::::::::oo  p::::::::::::::pp  h:::::h     h:::::h  ee:::::::::::::e   r:::::r             s:::::::::::ss  \n\
PPPPPPPPPP           hhhhhhh     hhhhhhhiiiiiiiillllllll   ooooooooooo     sssssssssss       ooooooooooo    p::::::pppppppp    hhhhhhh     hhhhhhh    eeeeeeeeeeeeee   rrrrrrr              sssssssssss    \n\
                                                                                                            p:::::p                                                                                        \n\
                                                                                                            p:::::p                                                                                        \n\
                                                                                                           p:::::::p                                        $(RED)by: abouabra$(GREEN)                                               \n\
                                                                                                           p:::::::p                                                                                       \n\
                                                                                                           p:::::::p                                                                                       \n\
                                                                                                           ppppppppp                                                                                       $(RESET)\n"
																								    
																										    
                                                                                                                                                                   

.PHONY: all clean fclean re