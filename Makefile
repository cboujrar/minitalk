CNAME = client
SNAME = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f
CLIENT = client.c printf/ft_printf.c printf/ft_putchar.c printf/ft_puthexa.c helpers.c\
				printf/ft_putnbr.c printf/ft_putptr.c printf/ft_putstr.c printf/ft_putunbr.c 
SERVER = server.c printf/ft_printf.c printf/ft_putchar.c printf/ft_puthexa.c\
				printf/ft_putnbr.c printf/ft_putptr.c printf/ft_putstr.c printf/ft_putunbr.c 
	
CLIENT_O = ${CLIENT:.c=.o}
SERVER_O = ${SERVER:.c=.o}

all: ${CNAME} ${SNAME}

${CNAME}: ${CLIENT_O}
		${CC} ${CFLAGS} ${CLIENT_O} -o  ${CNAME}

${SNAME}: ${SERVER_O}
	${CC} ${CFLAGS} ${SERVER_O} -o  ${SNAME}

clean:
	${RM} ${CLIENT_O} ${SERVER_O}

fclean: clean
	${RM} ${CNAME} ${SNAME}

re: fclean all