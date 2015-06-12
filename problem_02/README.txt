/* Needed for sysinfo */
#include <sys/sysinfo.h>

/* Needed for time */
#include <time.h>

time_t start_time = -1;

void read_status() {
  struct sysinfo info;
  time_t current_time;

  if(start_time == -1) {
    time(&start_time);
    printf("Read status starting at %s\n",ctime(&start_time));
  }
  time(&current_time);
  sysinfo(&info);
}
