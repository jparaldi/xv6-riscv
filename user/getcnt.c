#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  // Verifica se o usuario passou o argumento
  if(argc < 2){
    fprintf(2, "Usage: getcnt <syscall_number>\n");
    exit(1);
  }

  // Converte a string do argumento para inteiro
  int sys_num = atoi(argv[1]);
  
  // Chama a syscall
  int count = getcnt(sys_num);
  
  if(count < 0) {
    fprintf(2, "getcnt: invalid syscall number\n");
  } else {
    printf("syscall %d has been called %d times\n", sys_num, count);
  }
  
  exit(0);
}