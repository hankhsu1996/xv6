#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

void
printPstat(struct pstat *ps)
{
  printf(1, "Print pstat...\n");
  for (int i = 0; i < NPROC; i++) {
      if (ps->inuse[i]) {
        printf(1, "pid %d tickets %d ticks %d\n", ps->pid[i], ps->tickets[i], ps->ticks[i]);
      }
  }
  printf(1, "\n");
}

int
main(int argc, char **argv)
{
  if (argc != 3){
    printf(2, "usage: spin num_iter num_fork...\n");
    exit();
  }

  int num_iter = atoi(argv[1]);
  int num_fork = atoi(argv[2]);
  int pid;

  for (int i = 0; i < num_fork; i++) {
    pid = fork();
    if (pid == 0) {
      // child process, do spinning
      settickets(10 * (i + 1));
      while (num_iter)
        num_iter--;

      if (i == num_fork - 1) {
        struct pstat *ps = malloc(sizeof(struct pstat));
        getpinfo(ps);
        printPstat(ps);
        free(ps);
      }

      exit();
    }
  }

  wait();
  exit();
}

/*
With printing running process, use the following.
5 sec:
spinfork 500000000 4
*/
