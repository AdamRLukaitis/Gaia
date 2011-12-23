/*
 * Gaia system calls
 * Piranna, 2011-12-17
 */

#ifndef SYSCALL_H_USERSPACE
#define SYSCALL_H_USERSPACE

#include "syscall.h"
#include "syscall_defines.h"
#include "types.h"

DECL_SYSCALL2(in,  const u8int, const u16int)
DECL_SYSCALL3(out, const u8int, const u16int, const u8int)

int syscall_inb(const u16int port);
int syscall_outb(const u16int port, const u8int value);

#include "irq.h"
DECL_SYSCALL2(irq_register_handler, const u8int, const isr_t)

#include "eventmanager.h"
DECL_SYSCALL1(set_eventmanager_send, const t_em_send)

#endif
