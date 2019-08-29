#include "vm.h"

// aff | Aff | 0x10
// Usage : aff S(RG) Durée : 2
// OCP : Oui Adressage Restreint : Non Modifie le carry : Oui
// Affiche a l'ecran le char correspondant a la valeure du registre passé
// en parametre, modulo 256. Si ce char est NUL, alors le carry passe a
// l'etat 1, sinon a l'état 0. A vous de choisir le formattage de la sortie
// ecran. Vous pouvez par exemple preciser a chaque aff l'id de sont
// processus d'origine, ou bien attribuer une couleur a chaque
// processus, ou encore attribuer une ligne de aff par processus, ou
// n'importe quoi d'autre avec les processus, l'important reste que votre
// sortie de aff soit le plus swag possible.
// Idée de bonus : L'instruction aff a pour seul but de taunter son
// adversaire ( ce qui est une part non negligeable du jeu ). Mais, en
// envoyant les chars au compte goute, il est tres difficile de sortir une
// phrase propre a l'ecran, sans etre interompu par un live ou un autre
// aff. Pour palier a ca, vous pouvez bufferiser le aff. Dans ce cas
// chaque processus possede son buffer. A chaque appel de aff,
// l'instruction rajoute le char dans le buffer du processus. Lors d'un
// appel de aff avec le char NUL, l'instruction vide le buffer a l'ecran. Un
// char NUL definissant egalement le carry a 1, cette construction
// permet de facilement faire des boucle pour display des strings, si tant
// est qu'elles se terminent par un NUL char.

//Le cheat sheet doit pas etre bon pour aff,
//ils parlent pas du carry dans le sujet;
//Oui, ca ne modifie pas le carry.

void	inst_aff(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	ft_print_debug(plst, "AFF", 0);
	ft_arg_init(&arg, 1, FULL, TRUE, SPECIAL);
	ft_get_opcode(cor, plst, &arg);
	ft_get_args_size(&arg);
	if (arg.type[0] != REG_CODE)
	{
		pc_modulo2(plst, ft_get_args_size_sum(arg));
		ft_verbosity_adv(cor, plst);
		return ;
	}
	ft_get_args(cor, plst, &arg);
	if (ft_check_reg_index(cor, plst, arg) == FAIL)
		return ;
	ft_verbosity_instru(cor, plst, arg);
	if (!cor->verbosity && !cor->visu)
		ft_printf("%c\n", plst->p.reg[arg.value[0]] % 256);
	ft_verbosity_adv(cor, plst);
	ft_print_debug(plst, "AFF", 1);
}
