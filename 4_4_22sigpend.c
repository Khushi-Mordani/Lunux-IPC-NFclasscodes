//Khushi Mordani
#include<stdio.h>
#include<signal.h>

void check_pending_sigs()
{
	int i,res;
	sigset_t s;
	sigprocmask(SIG_BLOCK,NULL,&s);
	for(i =1 ; i<5 ;i++)
	{
		res = sigismember(&s,i);
		if(res)
			printf("Signal %d is pending\n");
		else
			printf("Signal %d is not pending\n");
	}
}

void sighand(int no)
{
	printf("Inside sighandler\n");
}

int main()
{
	sigset_t s_set;
	sigemptyset(&s_set);
	sigaddset(&s_set,2);
	sigaddset(&s_set,4);
	sigprocmask(SIG_BLOCK | SIG_SETMASK, &s_set, NULL);
	printf("Send a signal one and see the effect");
	getchar();
	getchar();
	sigpending(&s_set);
	check_pending_sigs(s_set);
	getchar();
	sigprocmask(SIG_UNBLOCK, &s_set, NULL);
	printf("Now signals are unblocked");
	while(1);
	return 0;	
}

//ctrl+c : terminate
//ctrl+\ : kill when ctrl+c is not working(shayad)
//ctrl+z : suspend
//ctrl+s : freeze terminal
//ctrl+q : unfreeze/release terminal
