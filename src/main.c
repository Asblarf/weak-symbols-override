#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "hijack.h"

int main(void) {
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  printf("%s:\t fd value: %d\n", __func__, fd);

  return close(fd);
}
