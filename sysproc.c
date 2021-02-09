#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

// {
//   /* data */
// };
struct proc *curproc;
int
sys_fork(void)
{
  curproc->c[1]++;
  return fork();
}

int
sys_exit(void)
{
  curproc->c[2]++;
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  curproc->c[3]++;
  return wait();
}

int
sys_kill(void)
{
  curproc->c[6]++;
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  curproc->c[11]++;
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  curproc->c[12]++;
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  curproc->c[13]++;
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;
curproc->c[14]++;
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getParentID(void){
  curproc->c[22]++;
  return getParentID();
}
//char result[]="";
int
sys_getChildren(void){
  curproc->c[23]++;
   void * res;
   if(argptr(0,(void*)&res,sizeof(void*))<0){
     return -1;

   }
   char ** new=(char **)(void**)res;
   getChildren(new);
  
  return sizeof(res);
}
int 
sys_getSyscallCounter(void){
  int n;
  curproc=myproc();
  curproc->c[24]++;

  if(argint(0, &n) < 0)
    return -1;
  int res= (curproc->c)[n];
  return res;
}