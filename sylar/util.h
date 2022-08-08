//
// Created by zhi-jun on 22-8-7.
//

#ifndef SYLAR_UTIL_H
#define SYLAR_UTIL_H

#include <sys/syscall.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

namespace sylar{
    pid_t GetThreadId();
    uint32_t GetFiberId();
}

#endif //SYLAR_UTIL_H
