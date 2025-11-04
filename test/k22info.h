#include <sys/types.h>
struct k22info { //Using the the struct out of the kernel code so we must copy it here to compile
    char comm[64];
    pid_t pid;
    pid_t parent_pid;
    pid_t first_child_pid;
    pid_t next_sibling_pid;
    unsigned long nvcsw;
    unsigned long nivcsw;
    unsigned long start_time;
};