#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define __NR_get_task_params_sys 341
#define __NR_set_task_params_sys 342
#define get_task(arg) syscall(__NR_get_task_params_sys,arg)
#define set_task(arg1,arg2) syscall(__NR_set_task_params_sys,arg1,arg2)

int main(void){
	struct d_params *params = (struct d_params *) malloc(sizeof(struct d_params));
	char group_name = 'K';
	int member_id = 13;
	printf("Executing test2.c\n");
	printf("Trapped in kernel level\n");
	printf("Task_set is being executed!\n");
	if(set_task(group_name,member_id) != 0){
		printf("Task_set error,group_name should be a capital letter and group_id > 0");
		return 1; 
	}else{
		printf("Task_set was executed!\n");
		printf("Task was initialized with group_name = %c and id = %d\n",group_name,member_id);
	}

	printf("Task_get is being executed!\n");
	if(get_task(params) != 0){
		printf("Task_get error\n");
		return 1; 
	}else{
		if(params->group_name == group_name && params->member_id == member_id){
			printf("Task_get was executed\n");
			printf("\n Group is %c",params->group_name);
			printf("\n Member id is %d",params->member_id);
		}else{
			printf("Task_get error, the parameters were not right!\n");
		}
	}
	printf("\n User level \n");
	return 0;
}
