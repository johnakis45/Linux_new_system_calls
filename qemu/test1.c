#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define __NR_get_task_params_sys 341
#define __NR_set_task_params_sys 342
#define get_task(arg) syscall(__NR_get_task_params_sys,arg)
#define set_task(arg1,arg2) syscall(__NR_set_task_params_sys,arg1,arg2)

int main(void){
	struct d_params *params = (struct d_params *) malloc(sizeof(struct d_params));
	char group_name = 'B';
	int member_id = 13;
printf("Executing test1.c\n");
	printf("kernel level\n");
	if(set_task(group_name,member_id) == 0){
		printf("Task_set was executed!\n");
		printf("Task was initialized with group_name = %c and id = %d",group_name,member_id);
	}else{
		printf("Task_set error,group_name should be a capital letter and group_id > 0");
		return 1; 
	}
	if(get_task(params) == 0){
		printf("\n Group is %c",params->group_name);
		printf("\n Member id is %d",params->member_id);
		if(params->group_name != group_name){
			printf("Error : group_name is wrong!\n");
		}
		if(params->member_id != member_id){
			printf("Error : member_id is wrong!\n");
		}
	}else{
		printf("Task_get error\n");
		return 1; 
	}
	printf("\n User level \n");
	return 0;
}



