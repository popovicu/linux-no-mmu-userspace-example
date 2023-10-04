#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("Hello world\n");

  for (int i = 0; i < 3; i++) {
    pid_t pid;

    if ((pid = vfork()) < 0) {
      fprintf(stderr, "Could not fork a worker at iteration %d\n", i);
      exit(1);
    }

    if (pid == 0) {
      // Child process
      char *args[2] = { "worker", NULL };
      execv("/worker", args);
    }
  }
  
  while (1) {
    sleep(5);
    printf("Hello from init\n");
  }
  
  return 0;
}
