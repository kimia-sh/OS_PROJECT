#include "types.h"
#include "stat.h"
#include "user.h"

int main (void){
    int pid=fork();
    if(pid==0){
      printf(1,"this is process %d and the parent id is %d\n",pid,getParentID()); 

    }
    else if(pid>0){
        pid=wait();
        pid=fork();
        if(pid==0){
        printf(1,"this is process %d and the parent id is %d\n",pid,getParentID());
        }
        else{
            pid=wait();
            printf(1,"this is process %d and the parent id is %d\n",pid,getParentID());
        }
    }
     exit();
}