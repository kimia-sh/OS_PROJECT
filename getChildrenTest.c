#include "types.h"
#include "stat.h"
#include "user.h"

int main (void){
    int pid=fork();
    char * result;
    if(pid>0){
        pid=wait();
        int pid2=fork();
        if(pid2>0){
            pid2=wait();
            int pid3=fork();
            if(pid3>0){
                    pid3=wait();
                    printf(1,"\nhi\n");
                    printf(1,"%d",getChildren(&result));
                    printf(1,"%s",result);
            }
        }

    }
     exit();
}