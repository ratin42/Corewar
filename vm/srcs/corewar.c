#include "../includes/vm.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../../includes/op.h"
#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>

int main(int ac, char **av)
{
	int fd;
	int	ret;
	
	struct stat hey;

	char	*file;

	if ((fd = open(av[1], O_RDONLY) == -1))
		return (0);

	stat(av[1], &hey);


	ret = read(fd, file, hey.st_size);
	if (ret != 0)
		return (0);
	

	(void)ac;
	return (0);
}
