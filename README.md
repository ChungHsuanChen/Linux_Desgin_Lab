# NCU Linux Kernel Lab
# virtual_address_mapping.c
 Prove that the virtual memory of every process match to same physical memory. 
 Finding page table via mm_struct in task_struct.
Traverse all the process using task_struct and find the pgd ,pmd, pud,pte of the process. And see if all the process is same.

# wait_queue-enter_wait_queue
Create our own wait queue and add register a **system call** for adding process into those wait queue. The **system call** will add the process into the wait queue they indicate and set their state to TASK_INTERRUPTABLE for waking them up via signal.
 

# wait_queue-clean_wait_queue
Clean out wait queue and add register a **system call** for waking up processes in specific wait queue.
