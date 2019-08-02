#include "../../includes/vm.h"
#include "../../libft/includes/ft_printf.h"
#include <stdio.h>

uint8_t ft_get_ocp(uint16_t ins);

/*int ocp_decode_len_ins(uint8_t ocp)
{
  uint8_t param1;
  uint8_t param2;
  uint8_t param3;
  int len;

  len = 0;
  param1 = ((ocp >> 6) & 0x03);
  param2 = ((ocp >> 4) & 0x03);
  param3 = ((ocp >> 2) & 0x03);
  len += ((param1 == 1)? 1 : 0);
  len += ((param1 == 2)? 2 : 0); // T_DIR 2/4 bytes ?
  len += ((param1 == 3)? 2 : 0);
  len += ((param2 == 1)? 1 : 0);
  len += ((param2 == 2)? 2 : 0);
  len += ((param2 == 3)? 2 : 0);
  len += ((param3 == 1)? 1 : 0);
  len += ((param3 == 2)? 2 : 0);
  len += ((param3 == 3)? 2 : 0);
  return (len);
}

int main()
{
  uint8_t ocp = 0x68;
  uint8_t tmp = ocp >> 6;
  printf("length instruction: %d\n", ocp_decode_len_ins(ocp));
  //printf("\nTest: %d  %d %d\n\n",(tmp & 0x01), (tmp & 0x10), (tmp & 0x11));
  return (0);
}*/
