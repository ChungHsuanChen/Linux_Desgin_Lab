#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/sched.h>
#include<linux/mm_types.h>
#include<asm/current.h>
#include<asm/pgtable.h>
/*
Module for proving the virtual kernel space of all preocess map to same physical address  
*/
int init_module(void){
	int c=0,flag=0;
	unsigned long eric[60] = {0};
	unsigned long temp=0;
    	struct task_struct *p;
	for_each_process(p){ 
		//0xF7700000
		unsigned long last=0xF7700000;
		
		if(p->mm==NULL) {
		continue;
		}
		pgd_t *pgd;	
		pud_t *pud;
		pmd_t *pmd;
		pte_t *pte;
		unsigned long page_addr=0,page_offset=0,paddr=0;
		c++;
		
		unsigned long vaddr=0xc0000000;

		int i=-1;
		while(vaddr<=last){
			i++;
			pgd=pgd_offset(p->mm,vaddr);
			pud=pud_offset(pgd,vaddr);
			pmd=pmd_offset(pud,vaddr);
			pte=pte_offset_kernel(pmd,vaddr);
			page_addr=pte_val(*pte)&PAGE_MASK;
			page_offset=vaddr& ~PAGE_MASK;
			paddr=page_addr|page_offset;	
					
			if(c==1 ){
				eric[i]=paddr;
			}
			else if(c>1){
				if(paddr!=eric[i]){
					printk(KERN_INFO "ericgg = 0x%lu",vaddr);
					flag=1;
					break;		
				}			
			}
			printk(KERN_INFO "\nvirtualaddr->0x%lu ",vaddr);
			printk(KERN_INFO "\neric[%d]=0x%lu \n",i, eric[i]);
			printk(KERN_INFO "process =0x%lu", eric[i]);
			vaddr=vaddr+30000000;	

		}
		if(flag) break;	

	}
	printk(KERN_INFO "ericEND=%d \n",flag);
	printk(KERN_INFO "processNo=%d \n",c);
	return 0;
}
void cleanup_module(void){
	printk(KERN_INFO "BYE ERIC");
}



