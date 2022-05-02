#include<linux/kernel.h>
#include<linux/wait.h>
#include<linux/sched.h>
#include<asm/current.h>
#include<linux/init.h>

DECLARE_WAIT_QUEUE_HEAD(project2_queue_1);
DECLARE_WAIT_QUEUE_HEAD(project2_queue_2);
DECLARE_WAIT_QUEUE_HEAD(project2_queue_3);
/*
System call for entering wait queue
*/
asmlinkage int enter_wait_queue(int x){
	printk("------------enter wait queue----------");
	DECLARE_WAITQUEUE(wait,current);

	if(x==1){
		printk("------------enter wait queue 1----------");
		add_wait_queue(&project2_queue_1,&wait);
		set_current_state(TASK_INTERRUPTIBLE); //set state to INTERRUPTIBLE
		schedule();
		return 1;
	}	
	else if(x==2) {
		printk("------------enter wait queue 2----------");
		add_wait_queue(&project2_queue_2,&wait);
		set_current_state(TASK_INTERRUPTIBLE);
		schedule();		
		return 2;
	}else if(x==3){
		printk("------------enter wait queue 3----------");
		add_wait_queue(&project2_queue_3,&wait);
		set_current_state(TASK_INTERRUPTIBLE);
		schedule();
		return 3;
	}
	
	return 0;
}
/*
System call for exiting wait queue
*/
asmlinkage int clean_wait_queue(int x){
	printk("------------clean wait queue----------");
	if(x==1){
		printk("------------clean wait queue 1----------");
		wake_up_all(&project2_queue_1);
		init_waitqueue_head(&project2_queue_1);
		return 1;
	}
	else if(x==2){
		printk("------------clean wait queue 2----------");
		wake_up_all(&project2_queue_2);
		init_waitqueue_head(&project2_queue_2);
		return 2;
	}
	else if(x==3){ 
		printk("------------clean wait queue 3----------");
		wake_up_all(&project2_queue_3);
		init_waitqueue_head(&project2_queue_3);
		return 3;
	}
	return 0;
}
