#磁盘管理DiskManagement

##要求Requirement

###实验目的Purpose

1、对磁盘调度的相关知识作进一步的了解，明确磁盘调度的原理。
Learn more about disk scheduling and clarify the principles of disk scheduling.

2、加深理解磁盘调度的主要任务。
Gain a deeper understanding of the main tasks of disk scheduling.

3、通过编程，掌握磁盘调度的主要算法。
Master the main algorithm of disk scheduling through programming.

###实验内容Content

1、对于如下给定的一组磁盘访问进行调度：
Schedules a set of disk accesses given below:

| 请求服务到达 | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   |
| ------------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 访问的磁道号 | 30  | 50  | 100 | 180 | 20  | 90  | 150 | 70  | 80  | 10  | 160 | 120 | 40  | 110 |

2、要求分别采用先来先服务、最短寻道优先以及电梯调度算法进行调度。
It is required to use first-come, first-served, shortest seek priority and elevator scheduling algorithms for scheduling.

3、要求给出每种算法中磁盘访问的顺序，计算出平均移动道数。
It is required to give the order of disk access and calculate the average number of moving lanes in each algorithm.

4、假定当前读写头在90号，电梯调度算法向磁道号增加的方向移动。
Assuming that the current read/write head is at number 90, the elevator scheduling algorithm moves in the direction of increasing track number.

##运行环境Environment

程序在Linux平台上编写，Qt(C++)实现可视化。
Based on Qt(C++) for Linux.

##界面UI



##数据说明Data

通过**data.txt**文件读入数据。
Read in data via **data.txt** file

第一行：磁头当前位置，磁头方向；
The first line: the current position and the direction of the magnetic head;

第2～n行：请求服务名称，访问的磁道号。
Lines 2 to n: Request service name, track number accessed.
