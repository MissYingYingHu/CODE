#pragma once
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/shm.h>

int CreateShm();

int OpenShm();

void DestroyShm(int shmid);

