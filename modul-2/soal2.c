#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <time.h>

int main() {
  pid_t child_id;
  int status;

  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE);
  }

  char dir[100] = "/home/maroqi/Projects/OSProject/soal-2";
  char target_dir[100];
  char folder_name[100];

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(folder_name, "/%02d-%02d-%d_%02d:%02d:%02d\n", 
    tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour,
    tm.tm_min, tm.tm_sec);

  strcpy(target_dir, dir);
  strcat(target_dir, folder_name);

  if (child_id == 0) {
    char *argv[] = {"mkdir", "-p", target_dir, NULL};
    execv("/bin/mkdir", argv);
  } else {
    while ((wait(&status)) > 0);

    char source_dir[100] = "/home/maroqi/Downloads/.";

    char *argv[] = {"cp", "-R", source_dir, target_dir, NULL};
    execv("/bin/cp", argv);
  }
}