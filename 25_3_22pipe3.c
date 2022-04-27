// shows how pipes can be used


#include<stdio.h>
#include<unistd.h>


int fds[2];


void parent_code(){
char buf1[20] = "aaaaaaaaaaaaaaaaaaa";
char buf2[20] = "bbbbbbbbbbbbbbbbbb";
close(fds[0]);
write(fds[1], buf1, 20);
write(fds[1], buf2, 20);
printf("end of parent\n");
}


void child_code(){
char buf_to_read[100];
int n;
close(fds[1]);
n = read(fds[0], buf_to_read, 100); //will return the length of the buffer readed
printf("no of chars read = %d\n", n);



//added(this will capitalize the buffer value)
for(int i=0; buf_to_read[i]; i++){
if(buf_to_read[i]>='a' && buf_to_read[i]<='z'){
buf_to_read[i]=buf_to_read[i]-32;
}
}



for(int i=0; i<n; i++){
printf("%c", buf_to_read[i]);
}
printf("\nend of child");
}


int main(){

int res;
pid_t p;
res = pipe(fds);
// fds[0] for reading and fds[1] for writing


if(res==-1){
perror("pipe");
exit(1);
}


p = fork();


if(p==0){
child_code();
} else{
parent_code();
}


return 0;
}
