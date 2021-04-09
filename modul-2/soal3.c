#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <stdbool.h>

int main() {
  pid_t pid, sid;
  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  char dir[100] = "/home/maroqi/Projects/OSProject/log";
  char source[20] = "/error.txt";
  char destination[100] = "/error.log";
  int counter = 0;
  FILE *input;
  FILE *output;

  while (true) {
    char source_file[100];
    char destination_file[200];
    char file_num[100];
    
    counter++;
    sprintf(file_num, ".%d", counter);

    strcpy(source_file, dir);
    strcat(source_file, source);
    input = fopen(source_file, "r+");

    if (input == NULL) {
        return 0;
    }

    strcpy(destination_file, dir);
    strcat(destination_file, destination);
    strcat(destination_file, file_num);
    output = fopen(destination_file, "w");

    if (output == NULL) {
        fclose(input);
        return 0;
    }

    char c;
    while ((c = fgetc(input)) != EOF) {
        fputc(c, output);
    }

    freopen(source_file, "w", input);
    fclose(input);
    fclose(output);
    sleep(10);
  }
}