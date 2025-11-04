#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "k22info.h"

int main(){
    int ne = 8; //Buffer size testing
    int ret; //Syscall return value
    struct k22info *buf = malloc(ne * sizeof(struct k22info));

    if(buf == NULL){
        perror("Failed to allocate memory for k22info buffer");
        return 1;
    }
    
    ret = syscall(467, buf, &ne); //467 is the syscall number for k22tree
    if(ret < 0){
        perror("k22tree syscall failed");
        free(buf);
        return 1;
    }
    if (ret == 0){
        printf("k22tree succeeded, only testing with empty implementation\n");
        free(buf);
        return 0;
    }
    printf("k22tree returned %d entries (buffer size was %d)\n", ret, ne);

    return 0;
}