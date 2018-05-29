# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 16:37:19 by iseletsk          #+#    #+#              #
#    Updated: 2018/05/02 19:13:04 by iseletsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC :=		./sources/ft_count_c.c ./sources/ft_itoa_base.c ./sources/ft_itoa_base_u.c ./sources/ft_printf.c ./sources/ft_putunic.c ./sources/ft_replace_c.c ./sources/ft_size_uni.c ./sources/ft_unicpy.c ./sources/ft_unisdup.c ./sources/ft_unisjoin.c ./sources/ft_unislen.c ./sources/ft_unisnew.c ./sources/ft_unisset.c ./sources/ftp_check_cast.c ./sources/ftp_check_main_flag.c ./sources/ftp_check_valid.c ./sources/ftp_check_width.c ./sources/ftp_clear_data.c ./sources/ftp_give_p.c ./sources/ftp_give_str.c ./sources/ftp_hendl.c ./sources/ftp_hendl_dinbr.c ./sources/ftp_hendl_flag.c ./sources/ftp_hendl_uxonbr.c ./sources/ftp_hendl_xnbr.c ./sources/ftp_ntoa.c ./sources/ftp_putstr_del.c ./sources/ftp_putunis_del.c ./sources/ftp_strj_nbr.c ./sources/ftp_strj_str.c ./sources/ftp_strj_uni.c

all:
	gcc -Wall -Wextra -Werror $(SRC) -I ../ -c

clean:
	rm -f *.o

fclean: clean
	rm -rf *.o

re: fclean all

.PHONY: all clean fclean re
