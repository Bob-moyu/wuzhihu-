#pragma once 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define  PATHNAME "."
#define PROJ_ID 0x6666

int createShm(int size);
int destoryShm(int shmid);
int getShm(int size);

