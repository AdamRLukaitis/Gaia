// syscall.h -- Defines the interface for and structures relating to the syscall dispatch system.
//              Written for JamesM's kernel development tutorials.

#ifndef SYSCALL_H
#define SYSCALL_H

#include "types.h"

typedef void (*t_em_send)(char*,int);

void syscall_init(void);

#endif
