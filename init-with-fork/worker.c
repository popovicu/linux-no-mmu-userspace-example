#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  while (1) {
    printf("Hello from worker!\n");
    sleep(3);
  }
  
  return 0;
}
