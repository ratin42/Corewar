# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    zork.s                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratin <ratin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 14:14:10 by ratin             #+#    #+#              #
#    Updated: 2019/07/29 14:35:58 by ratin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name "zork"
.comment "hey"

l2: 	sti r1, %:live , %1 
		and r1, %0, r1

live:	live %1
		zjmp %:live
