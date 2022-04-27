#include<stdio.h>
#include<stdlib.h>
#include<signal.h>


void printSignalSet(sigset_t *set)
{
const int sigList[] = { SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGABRT, SIGFPE, SIGKILL, SIGSEGV,};
const char *sigNames[] = { "SIGHUP", "SIGINT", "SIGQUIT", "SIGILL", "SIGABRT", "SIGFPE", "SIGKILL", "SIGSEGV",};
const int sigLen = 8;
for(int i=0; i<sigLen;i++){
int ret = sigismember(set,sigList[i]);
if(ret == -1)
{
perror("sigismember:");
exit(EXIT_FAILURE);
}
else if(ret == 1)
{
printf("signal %s=%d is in the set \n",sigNames[i], sigList[i]);
}
else{
printf("signal %s=%d is in the set \n",sigNames[i], sigList[i]);
}
}
}


int main(void){
sigset_t set;
if(sigprocmask(0,NULL,&set) != 0)
{
perror("sigprocmask:");
exit(EXIT_FAILURE);
}
printf("---Initial signal mask for this process: ---\n");
printSignalSet(&set);


if(sigaddset(&set,SIGINT) != 0)
{
perror("sigaddset:");
exit(EXIT_FAILURE);
}

if(sigprocmask(SIG_SETMASK,&set,NULL) != 0)
{
perror("sigprocmask:");
exit(EXIT_FAILURE);
}

printf("--- NEW signal mask for this process: ---\n");
printSignalSet(&set);

int secToSleep = 20;
printf("try crtl+c. try killing this process this program with 'kill -kill %d'. going to sleep for %d second.\n",getpid(),secToSleep);
sleep(secToSleep);
printf("sleep returned \n");
printf("removeing all signals from mask. \n");

sigfillset(&set);

sigprocmask(SIG_SETMASK,&set, NULL);
printSignalSet(&set);
sleep(1);
printf("exited normally.\n");
return 0;
}
