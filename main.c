
#include "lib/alloc.h"

int main()
{
  char *str;
  str = (char *)m_alloc(sizeof(char) * 5);

  scanf("%s", str);
  printf("%s", str);

  return 0;
}
