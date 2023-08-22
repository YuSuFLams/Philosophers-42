NAME	= philo

C_BLUE	= \033[0;34m
C_CYAN	= \033[0;36m
C_RESET= \033[0m

CC 	= cc

RM 	= rm -rf

CFLAGS	= -Wall -Wextra -Werror

HEADER = include/philo.h 

M_SRCS = philo.c \
	philo_utils/ft_atoi.c \
	philo_utils/ft_calloc.c \
	philo_utils/get_time.c \
	philo_utils/ft_error.c \
	philo_utils/print_str.c \
	philo_utils/is_all_digit.c \
	philo_utils/ft_lstadd_back.c\
	handling/philo_fin.c \
	handling/philo_eating.c \
	handling/philo_take_forks.c \
	handling/philo_puts_forks.c \
	handling/philo_sleep_think.c \
	handling/routine_ph.c \
	src/check_arg.c \
	src/get_args.c \
	src/init_philo.c 

M_OBJS = ${M_SRCS:.c=.o}

all: $(NAME)

$(NAME): $(M_OBJS) $(HEADER)
	@$(CC) $(CFLAGS)  $(M_OBJS) -o $(NAME)  
	@printf "$(C_BLUE)    - Compilation Mandatory finished!....$(C_RESET)\n"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(M_OBJS) $(B_OBJS)
	@printf "$(C_CYAN)    - Removed Object File finished!....$(C_RESET)\n"

fclean: clean
	@$(RM)  $(NAME) $(B_NAME)
	@printf "$(C_CYAN)    - Removed finished!....$(C_RESET)\n"

re: fclean all

.PHONY: all clean fclean re 