#ifndef QOS_H
# define QOS_H
# define D1 "0x68"
# define D2 "0x50"
# define D3 "0x00"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <ctype.h>


typedef struct  s_qos    t_qos;

struct                  s_qos
{
        char	*name;
		char	*IPaddr;
		double	debit;
        t_qos   *next;
};

t_qos	*createElem(char *name, char *IP, double debit);
t_qos	*addList(t_qos *qos, char *name, char *IP, double debit);
void	disList(t_qos *qos);
void	freeList(t_qos *qos);
t_qos    *ft_readfile(char *tmp);
int	    usage();
int	    error(char *str);
void	launch(t_qos *qos);
int		onePing(char *IP);
char	**ft_strsplit(char *str, char *c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putendl(char *str);
void    ft_putnbr(int n);
char	*ft_strtrim(char *str);
char	*ft_strreplace_ip(char *str);
#endif
