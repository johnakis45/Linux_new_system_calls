#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <linux/d_params.h>
#include <asm/uaccess.h>
#include <asm/current.h>

asmlinkage long sys_set_task_params_sys(char group_name,int member_id){
	struct task_struct *task;
	task = get_current();
	printk("Ioannis Davanos,csd4622,set_task_params is being executed\n");
	if(group_name >= 65 && group_name <= 90&& member_id > 0 && task !=NULL){
		task->group_name = group_name;
		task->member_id = member_id;
	}else{
		return EINVAL;
	}
	return 0;
}
