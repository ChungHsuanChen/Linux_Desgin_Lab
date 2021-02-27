#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h> // For using kernel module

#include <linux/sched.h>
#include <linux/mm_types.h>
#include <asm/current.h>
#include<linux/dcache.h>
#include <asm/fixmap.h> // For using fixed_addresses mapping

static int lab1_p2_start(void)
{
	printk(KERN_DEBUG "--- kernel module lab1_p2_start() start ---\n");
	struct task_struct *p;
	enum fixed_addresses fix_index = FIX_HOLE;
	printk(KERN_DEBUG "fix_to_virt(%d) FIX_HOLE = %lx", fix_index, fix_to_virt(fix_index));
	int process_max = 50;
	int process_counter = 0;
	for_each_process(p)
	{
		if (p->mm == NULL)
			continue;

		if (process_counter > process_max)
			break;

		else
		{
			printk(KERN_DEBUG "Process : %15s, fix_to_virt(%d) FIX_HOLE = %lx\n", p->comm, fix_index, fix_to_virt(fix_index));
		}
		process_counter++;
	}

	return 0;
}

static void lab1_p2_end(void)
{
	printk(KERN_DEBUG "--- kernel module lab1_p2_end() end ---\n");
}

module_init(lab1_p2_start);
module_exit(lab1_p2_end);
