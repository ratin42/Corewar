# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    zork.s                                             :+:      :+:    :+:    #
	#                                                     +:+ +:+         +:+      #
#    By: ratin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/28 20:19:20 by ratin             #+#    #+#              #
#    Updated: 2019/07/28 20:25:59 by ratin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

  .name "zork"
	.comment "I'M ALIIIIVE"

l2:		sti r1,%:live,%1  
		and r1, %0, r1#sldfkjsdlfkjsdf

live:	live %1
		zjmp %:live
