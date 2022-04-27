//Khushi Mordani
//Shared memory client
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<string.h>

#define my_key 199
#define shm_size 0x1000
#define msg_len 256
#define pesp_msg_stsrt 256



int main()
{
int semID,shmID;
char *pShm;
struct sembuf smop;
semID=semget(my_key,1,0660);

if(semID<0)
{
printf("could not create semaphore\n");
return (1);
}
else
{
printf("could not create semaphore\n");
}
semctl(semID, 0, SETVAL, 0);
// create a shared memory segment
shmID = shmget(my_key, shm_size, 0660 | IPC_CREAT);
if (shmID < 0)
{
printf("could not create shared segment\n");
return (2);
}


pShm=shmat(shmID,NULL,0);
if(!pShm)
{
printf("could not attach shared memory segment\n");
return(3);
}
while(1)
{
printf("client:enter some request message  to send to server\n");
fgets(pShm,msg_len,stdin);
smop.sem_num=0;
smop.sem_op=1;
smop.sem_flg=0;

semop(semID,&smop,1);

smop.sem_num=1;
smop.sem_op=-1;
smop.sem_flg=0;
semop(semID,&smop,1);
puts(pShm+pesp_msg_stsrt);
}
}




