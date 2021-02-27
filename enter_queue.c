#include<unistd.h>
#include<sys/time.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<syscall.h>
#include<sys/types.h>

pid_t gettid(void){
return syscall(__NR_gettid);
}
void main(){

int random_num;
int ttid,count;
char str[300];
struct timeval t1,t2;
gettimeofday(&t1,NULL);
ttid=gettid();
char f[255];

sprintf(f,"%d",ttid);

char fil[]="file_";
count=0;
FILE *fptr;
strcat(fil,f);

fptr=fopen(fil,"w");
while(1){
	gettimeofday(&t2,NULL);
	double time1,time2;
	time1=t1.tv_sec+(t1.tv_sec/1000000.0);
	time2=t2.tv_sec+(t2.tv_sec/1000000.0);
	time1=time1-time2;
	if(time1<0)time1=-time1;
	if(time1>=180)break;
	random_num=(rand()%3)+1;
	sprintf(str,"process %d is added into wait queue project2_queue_%d the %d th time at time %f\n",ttid, random_num,count++, time2);
	fprintf(fptr,"%s",str);

	syscall(351,random_num);

}
fclose(fptr);

printf("process %d completes!\n",ttid);

}
