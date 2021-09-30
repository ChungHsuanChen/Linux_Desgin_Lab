# linux_lab1_p1 linux_lab1_p2
 Prove that the virtual memory of every process match to same physical memory.
 
## implementation
Traverse all the process using task_struct and find the pgd ,pmd, pud,pte of the process. And see if all the process is same.

# enter_wait_queue
Create our own wait queue and add register a **system call** for adding process into those wait queue. The **system call* will add the process into the wait queue they indicate and set their state to TASK_INTERRUPTABLE because we have another **system call** clean_wait_queue that use to wake up all the process in indicated wait queue 
 

