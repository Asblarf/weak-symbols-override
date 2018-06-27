#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "hijack.h"

int main(void) {
  printf("%s:\t Starting main program...\n", __func__);
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  printf("%s:\t fd value: %d\n", __func__, fd);
  return 0;
}
