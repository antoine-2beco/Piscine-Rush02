/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:40:23 by ade-beco          #+#    #+#             */
/*   Updated: 2023/09/23 10:40:31 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

int	ft_strlen(char *str);
void	ft_error(void);


char	*ft_getword(char *nbr, int i, char *file)
{
	int a;
	char *str;

	while (file[i] == ':' || file[i] == ' ')
		i++;
	a = i;
	while (file[i] != '\n' || file[i] != '\0')
		i++;
	a = i - a;
	str = (char*)malloc(a*sizeof(char));
	str[a] = '\0';
	i -= 1;
	while (a >= 0)
	{
		str[a] = file[i];
		a --;
		i --;
	}
	return (str);
}

char *ft_dictval(char *dict)
{
	int	i;
	int	a;
	char *tab;

	a = 0;
	i = 0;
	while(dict[i] != '/n' && dict[i] != '\0')
		i++;
	tab = malloc(i + 1);
	i = 0;
	while(dict[i] != '/n' && dict[i] != '\0')
	{
		while (dict[i] == ' ')
			i++;
			
		while (dict[i] != ' ')
		{
			tab[i] = dict[i];
			i++; 
		}
		if 
	}
}

int	*ft_dictnbr(t_data *data, char *file)
{
	int	l;
	int	i;
	int k;
	int *tab;

	l = 0;
	i = 0;
	while(dict[i] != '\0')
	{
		if (dict[i] == '\n')
			l++;
		i++;
	}
	tab = malloc(sizeof(l)*l);
	i = 0;
	k = 0;
	while(dict[i] != '\0')
	{
		if (dict[i] == '+' || dict[i] == '-')
			if (dict[i++] == '-')
				ft_error();
		if (!(dict[i] >= '0' && dict[i] <= '9'))
			return (ft_error());
		data[k]->nb = 0;
		while(dict[i] >= '0' && dict[i] <= '9')
		{
			data[k]->nb = ((dict[k].nb * 10) + (dict[i] - '0'));
			i ++;
		}
		while(dict[i] == ' ')
			i++;
		if(dict[i] != ':')
			return(ft_error());
		data[k]->val = ft_dictval(dict + i + 1);
		while(dict[i] != '\n' && dict[i] != '\0')
			i++;
		k++;
		i++;
	}
	i = 0;
	while(i <= l)
	{
		printf("%d", tab[i]);
		i++;
	}
	return(tab);
}

char	*ft_readdict(char *dict)
{
	int fd;
	int rd;
	char c;
	int len;
	char *buf;

	fd = open(dict, O_RDONLY);	
	if (fd == -1)
	{
		printf("Open Error");
		return NULL;
	}

	while (read(fd, &c, 1))
		len++;

	close(fd);
	fd = open(dict, O_RDONLY);	
	if (fd == -1)
	{
		printf("Open Error");
		return NULL;
	}
	buf = (char*)malloc(len*sizeof(char));
	rd = read(fd, buf, len);
    buf[rd] = '\0';
	close(fd);

	return (buf);
}

int	main(void)
{
	t_data	data;
	char *nbr = "6";
	char *file = ft_readdict("numbers.dict");
	if (file == NULL)
		return (0);
	printf("file read :\n%s", file);

	int *tab = ft_dictnbr(&data, file);
	


	
	/*int pos = ft_checknbr(nbr, file);
	if (pos == -1)
	{
		printf("Number Not Foundable");
		return (0);
	}
	printf("Number found : %d", pos);

	char *str = ft_getword(nbr, pos, file);
	printf("%s", str);*/
}