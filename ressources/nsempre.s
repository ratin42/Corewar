.name "La fistiniere"
.comment "by nsampre & qselle"

fork %:init_mess

#Those aff are gonna be overwritten by #FIST but it allows #MESS to get closer to the ennemy
aff r1				
aff r1				
aff r1				
aff r1				
aff r1				
aff r1					
aff r1						
aff r1						
aff r1						
aff r1					
aff r1					
aff r1					
aff r1					
aff r1						
aff r1					
aff r1						
aff r1						
aff r1						
aff r1						
aff r1				
aff r1					
aff r1						
aff r1					
aff r1						
aff r1						
aff r1					
aff r1						
aff r1						
aff r1						
aff r1						
aff r1						
aff r1						
aff r1						
aff r1						
aff r1						
aff r1						
aff r1						


####################
#       FIST       #
####################

ld    %0, r4				#carry a 1 so direct zjumping
zjmp  %:init_fist			#and not executing the 8 columns

#the 8 columns are 8 of width, 8x8 = 64 = all screen is taken
#they are declared here because they go overwrite back ^
column1:
sti   r6, r2, r3 #self replicating
zjmp  %-69
column2:
sti   r6, r2, r3
zjmp  %-69
column3:
sti   r6, r2, r3
zjmp  %-69
column4:
sti   r6, r2, r3
zjmp  %-69
column5:
sti   r6, r2, r3
zjmp  %-69
column6:
sti   r6, r2, r3
zjmp  %-69
column7:
sti   r6, r2, r3
zjmp  %-69
column8:
sti   r6, r2, r3
zjmp  %-69


init_fist:
ld    %-64, r3 #-64 is one line up
st    r1, 6
live  %42

fork %:processa
ld    %0, r2		#  10
ld    %0, r4		# +10
zjmp %:processb	    # +20
# =40

#processA and processB arrives on the same address at the same time with one diff :
#r2 = 4 for pA and r2 = 0 for pB

processa:
ld    %4, r2		#  10
	ld    %0, r4		# +10
live %0				# +10		cycle padding stuff to line 44 zjump (20) = 2x live(10)
	live %0				# +10 		cycle padding stuff
# =40,      pA and pB are aligned

#pA and pB  then arrives at the same time here
	processb:
	ldi   r2, %:column1, r6
	ld    %0, r4

	columns_call:
	st    r1, 6
	live  %42
	fork %:columns_call #loop for father, call columns for child

	st    r1, 6
	live  %42
	fork %:column3
	st    r1, 6
	live  %42
	fork %:column4
	st    r1, 6
	live  %42
	fork %:column2
	st    r1, 6
	live  %42
	fork %:column5
	st    r1, 6
	live  %42
	fork %:column1
	st    r1, 6
	live  %42
	fork %:column6
	st    r1, 6
	live  %42
	fork %:column8
	st    r1, 6
	live  %42
	fork %:column7

	st r1, 11
	st r16, -4
	loop: live %42    #infinite live loop, don't forget the winner is the last live
	zjmp %:loop


##############
#    MESS    #
##############

#We need to step to go closer to ennemy (2 accesses), step and 509 and 501
#and then small step to mess ennemy code

	init_mess:
	ld		%0, r2
	zjmp	%:begin_mess

	access_final:
	st		r1, 6
	live    %42
	fork	%:head  #same as fist, one fork and one zjmp but 2 are gonna be sync for sti 
	ld		%0, r2
	zjmp	%:brain

	head:
	ld		%191104768, r7 #0b 64 07 00
	ld		%5, r6
	st		r1, 6
	live    %42
	sti		r7, r6, %317 #self replicating
	zjmp	%309

	brain:
	ld		%16, r12
	add		r12, r9, r9
	add		r12, r10, r10
	add		r12, r11, r11
	st		r1, 6
	live	%42
	ld %0,  r2

	begin_mess:
	ld		%16777216, r16 #01 00 00 00
	sti		r16, %:init_mess, %6
	sti		r1, %:access_one, %1
	ld		%507, r4
	ld		%507, r6
	st		r1, 6
	live	%42
	ld		%190055170, r8 #0b 54 03 02
	ld		%67699190, r9  #04 09 01 f6
	st		r8, 511
	st		r9, 510
	ld		%24, r8
	fork	%:access_final
	fork	%:access_two

	access_one:
	live	%1
	ld		%0, r2
	ld		%190055682, r3 #0b 54 05 02
	ld		%190056194, r5 #0b 54 07 02
	ld		%190056194, r7 #0b 54 07 02
	ld		%0, r16
	zjmp	%448

	access_two:
	live	%0
	ld		%4, r2
	ld		%101253622, r3 #06 09 01 f6, zjmp
	ld		%134807571, r5 #08 09 00 13, zjmp
	ld		%134807571, r7 #08 09 00 13, zjmp
	ld		%0, r16
	zjmp	%405
