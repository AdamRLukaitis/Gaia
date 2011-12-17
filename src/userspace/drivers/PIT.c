/*
 * timer.c
 *
 *  Created on: 05/12/2011
 *      Author: piranna
 */

// timer.c -- Initialises the PIT, and handles clock updates.
// Written for JamesM's kernel development tutorials.

#include "PIT.h"

#include <stdio.h>

#include "irq.h"


u32int tick = 0;


static void PIT_callback(registers_t* regs)
{
   tick++;

   printf("Tick: %d\n", tick);
}

void PIT_init(u32int frequency)
{
   // The value we send to the PIT is the value to divide it's input clock
   // (1193180 Hz) by, to get our required frequency. Important to note is
   // that the divisor must be small enough to fit into 16-bits.
   u32int divisor = 1193180 / frequency;

   // Firstly, register our timer callback.
	irq_register_handler(IRQ0, &PIT_callback);

   // Send the command byte.
   syscall_outb(0x43, 0x36);

   // Divisor has to be sent byte-wise, so split here into upper/lower bytes.
   // Send the frequency divisor.
   syscall_outb(0x40, (u8int)(divisor & 0xFF));
   syscall_outb(0x40, (u8int)((divisor>>8) & 0xFF));
}