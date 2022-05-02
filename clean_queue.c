#include<unistd.h>
#include<sys/time.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<string.h>
#include<syscall.h>
#include<sys/types.h>
/*
Clean queue test file
*/

pid_t gettid(void){
	return syscall(__NR_gettid);
}
void main(){

	int random_num1,random_num2;
	
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
	strcat(fil,f);// fil=file_tid

	fptr=fopen(fil,"w");
	while(1){
		gettimeofday(&t2,NULL);
		double time1,time2;
		time1=t1.tv_sec+(t1.tv_sec/1000000.0);
		time2=t2.tv_sec+(t2.tv_sec/1000000.0);
		time1=time1-time2;
		if(time1<0)time1=-time1;
		if(time1>=300)break;

		
		random_num1=(rand()%3)+1;
		random_num2=(rand()%60);
		sleep(random_num2);
		sprintf(str,"Wake up all processes in wait queue project2_queue_%d at time %f\n",random_num1, time2);
		fprintf(fptr,"%s",str);

		syscall(352,random_num1);
	}
	fprintf(fptr,"Clean wait wait queue project2_queue_1\n");
	syscall(352,1);
	fprintf(fptr,"Clean wait wait queue project2_queue_2\n");
	syscall(352,2);
	fprintf(fptr,"Clean wait wait queue project2_queue_3\n");
	syscall(352,3);

	fclose(fptr);

	printf("process %d completes!\n",ttid);

}
