#include "../../includes/vm.h"

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


//Le cheat sheet doit pas etre bon pour aff, ils parlent pas du carry dans le sujet;

void	inst_aff(t_corewar *cor, int i)
{
	int reg;

	ft_printf("process[%d] : AFF\n", i);
	cor->process[i].pc = pc_modulo(cor->process[i].pc + 1);
	reg = get_reg(cor, i);
	//comment gerer ce cas d'erreur ?
	if (reg < 1 || reg > 16)
		ft_printf("Reg: %d not valid, process[%d]", reg, i);

	ft_printf("aff: = [%c]\n", cor->process[i].reg[reg] % 256);

	cor->process[i].pc = pc_modulo(cor->process[i].pc + 1);
}