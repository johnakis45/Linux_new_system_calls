��� ��� ��������� ��� ������� ���������� �� ������ ��� ��������� ��� ��� �������������.

����� ��� ����� ������� ��� ������ ��� Linux ��� �� ������������� �� 2 ��� system_calls get
��� set. �� ������� ���� ������� �������� ���� �� dummy ����������. �� ��������� ��� ���
path : linux- 2.6.38.1/include/linux/ ,����������� ��� header file : d_params.h ��� �� ���� �� type
definition ��� struct d_params ��� �� ������������ ��� ��� get.


���� set ������ ����� �� �� group_name ����� �������� (�� ASCII) ��� �� member_id
�� ����� ���������� ��� 0. � get ������ ������� ������� ����� Null � pointer ��������� 
��� ���� �������� ������� �� struct ��� ��������� �� ��� ����� ��� ��������
��� ����� ��� task_struct ��� ���������� ��� ��������� � get_current. 

������ ����� define ���� �������� ��� ���� system calls ��� unistd_32.h ��� ������
��� �������� ������ ��� system calls ���� 2. ���� �������� ����� ��� ���������� ���� kernel ��� �� ��� system
calls ���� ��� syscall_table_32.S (���� ����������� 2 entries �� ����� ��� ������). ���� ��������������� �� 
syscalls.h ������������ �� signature ��� ���� system call. ������ ����������� ��� header file : d_params.h
��� path : linux- 2.6.38.1/include/linux (��� �� ���� �� type definition ��� struct d_params ��� �� 
������������ ��� ��� get).����� ����������� 2 .c ������, ��� ��� �� ���� system call ���� ���� kernel 
�� ��� ������ ��� ����������� ����������.


���� qemu ������ ���������������� �� image ��� ��������� ��� �� compilation ��� kernel
����� �������� ��� unistd.h (��� root) �� definition ��� struct d_params.

��� �� ������������� �� ���������� "test1.out" ��� "test2.out", ����� ��������� ��� ������ make � make all.
��� �� ���������� �� "test1.out", �������������� ��� ������ make run_test1.
��� �� ���������� �� "test2.out", �������������� ��� ������ make run_test2.



