#include "types.h"
#include "stat.h"
#include "user.h"

int main (void){
    
    getSyscallCounter(22);
    getParentID();
    getParentID();
    getParentID();
    getParentID();
    printf(1,"\n%d\n",getSyscallCounter(22));
    exit();
}