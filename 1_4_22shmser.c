//Khushi Mordani
//Shared memory server

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<string.h>

#define MY_KEY 199
#define SHM_SIZE 0x1000

void togglecase(char *buf,int cnt);

union semun{
int val;
struct semid_ds *buf;
unsigned short *array;
struct seminfo *__buf;

};
union semun sem_union;
int main()
{
int semID,shmID;
char *pShm;
struct sembuf smop;
semID=semget(MY_KEY,1,0660|IPC_CREAT);

if(semID<0)
{
printf("could not create semaphore\n");
return (1);
}
else
printf("opened a semaphore ID is %d\n ", semID);
semctl(semID, 0, SETVAL,0);
shmID=shmget(MY_KEY, SHM_SIZE, 0660|IPC_CREAT);
if(shmID<0)
{
printf("could not create shared segment\n");
return (2);
}
semctl(semID,NULL,0);
if(!pShm)
{
printf("could not shard memory segment\n");
return (3);
}

while(1)
{
smop.sem_num=0;
smop.sem_op=-1;
smop.sem_flg=0;
semop(semID,&smop,1);
printf("got the semaphore\n");
strcpy(pShm+256,pShm);
toggleCase(pShm+256,strlen(pShm+26));
printf("processed the request message and placed response\n");
smop.sem_num=1;
smop.sem_op=1;
smop.sem_flg=0;
}
}
void toggleCase(char *buf,int cnt)
{
int ii;
for(ii=0;ii<cnt;ii++)
{
if((buf[ii]>='A')&&(buf[ii]<='Z'))
buf[ii]+=0x20;
else if((buf[ii]>='a')&&(buf[ii]<='z'))
buf[ii]-=0x20;
}
}
