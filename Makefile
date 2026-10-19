NAME = minitalk
BONUS = minitalk_bonus
SRV_SRC = ./srv/main.c ./srv/utils.c ./srv/ft_atoi_base.c
CLT_SRC = ./clt/main.c
SRV_SRC_BONUS = ./srv_bonus/main_bonus.c ./srv_bonus/utils_bonus.c ./srv_bonus/ft_atoi_base_bonus.c
CLT_SRC_BONUS = ./clt_bonus/main_bonus.c
SRV_OBJS = $(SRV_SRC:.c=.o)
CLT_OBJS = $(CLT_SRC:.c=.o)
SRV_OBJS_BONUS = $(SRV_SRC_BONUS:.c=.o)
CLT_OBJS_BONUS = $(CLT_SRC_BONUS:.c=.o)
SRV = server
SRV_BONUS = server_bonus
CLT = client
CLT_BONUS = client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm

all: $(NAME)

bonus : $(BONUS)

$(NAME) : $(SRV) $(CLT)

$(BONUS) : $(SRV_BONUS) $(CLT_BONUS)

$(SRV) : $(SRV_OBJS)
	$(CC) $(SRV_OBJS) -o $(SRV)

$(SRV_BONUS) : $(SRV_OBJS_BONUS)
	$(CC) $(SRV_OBJS_BONUS) -o $(SRV)
	
$(CLT) : $(CLT_OBJS)
	$(CC) $(CLT_OBJS) -o $(CLT)

$(CLT_BONUS) : $(CLT_OBJS_BONUS)
	$(CC) $(CLT_OBJS_BONUS) -o $(CLT)

clean:
	$(RM) -f $(SRV_OBJS) 
	$(RM) -f $(CLT_OBJS)
	$(RM) -f $(SRV_OBJS_BONUS) 
	$(RM) -f $(CLT_OBJS_BONUS) 

fclean : clean
	$(RM) -f $(SRV)
	$(RM) -f $(CLT)

re : fclean all

.PHONY: all clean fclean re
