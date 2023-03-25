[English](README.md) | [简体中文](README.zh-CN.md)

# DiskManagement

## Purpose

1. Learn more about disk scheduling and clarify the principles of disk scheduling.

2. Gain a deeper understanding of the main tasks of disk scheduling.

3. Master the main algorithm of disk scheduling through programming.

## Content

1. Schedules a set of disk accesses given below:

| requests | A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   |
| ------------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| requests for cylinders | 30  | 50  | 100 | 180 | 20  | 90  | 150 | 70  | 80  | 10  | 160 | 120 | 40  | 110 |

2. It is required to use First Come First Serve (FCFS), Shortest Seek Time First (SSTF) and elevator algorithm (SCAN)  for scheduling.

3. It is required to give the order of disk access and calculate the average number of moving lanes in each algorithm.

4. Assuming that the current read/write head is at number 90, the elevator scheduling algorithm moves in the direction of increasing track number.

## Environment

Based on Qt(C++) for Linux.

## UI

![image](https://github.com/BattleforAzeroth/DiskManagement/blob/main/2022-02-23%2011-27-27%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

## Data

Read in data via **data.txt** file.

The first line: the current position and the direction of the magnetic head;

Lines 2 to n: Request service name, track number accessed.
