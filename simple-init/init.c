#include <string.h>
#include <unistd.h>

volatile char *UART = (char*) 0x10000000;

void print_to_uart(char *message) {
  for (int i = 0; i < strlen(message); i++) {
    *UART = message[i];
  }
}

int main() {
  print_to_uart("Hello world! Welcome to the Tiny Linux MMU-less kernel!\n");

  while (1) {
    sleep(1000);
  }
  
  return 0;
}
