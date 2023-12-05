#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/sched.h>
#include <linux/d_params.h>
#include <asm/uaccess.h>
#include <asm/current.h>

asmlinkage long sys_get_task_params_sys(struct d_params *params){
	struct task_struct *task;
	task = get_current();
	printk("Ioannis Davanos,csd4622,get_task_params is being executed\n");
	if(access_ok(VERIFY_WRITE,params,sizeof(struct d_params)) !=0 && params != NULL){
		params->group_name = task->group_name;
		params->member_id = task->member_id;
	}else{
		return EINVAL;
	}
	return 0;
}
