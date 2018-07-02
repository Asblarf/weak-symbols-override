#include <dlfcn.h>
#include <stdio.h>

static int (*real_socket)(int domain, int type, int protocol);

/**
 * Wrapper around libc's socket(). The wrapper simply prints a string
 * before calling libc's socket() function.
 *
 * Returns a socket file descriptor for the new socket, on success. On
 * error, -1 is returned, and errno is set appropriately.
 */
int socket(int domain, int type, int protocol) {
  printf("%s:\t Hijacking socket(%d, %d, %d) call\n",
         __func__, domain, type, protocol);
  return real_socket(domain, type, protocol);
}

void __attribute__((constructor)) init(void) {
  printf("--> Loading libhijack.so...\n");

  void *handle = dlopen("libc.so.6", RTLD_LAZY);
  if (!handle) {
    return;
  }

  char *error = dlerror();
  if (error) {
    printf("%s\n", error);
    return;
  }

  real_socket = (int (*)(int, int, int)) dlsym(handle, "socket");

  (void)dlclose(handle);
}

void __attribute__((destructor)) fini(void) {
  printf("<-- libhijack.so unloaded.\n");
}
