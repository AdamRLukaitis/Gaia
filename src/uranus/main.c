/*
 * main.c
 *
 *  Gaia (example) userspace kernel
 *
 *  Created on: 17/12/2011
 *      Author: piranna
 */


#include "eventmanager.h"
#include "syscall.h"

#include "scheudler.h"

#include "drivers/PIT.h"
#include "drivers/VGA.h"
#include "drivers/keyboard.h"
#include "drivers/term.h"

void init(void)
{
	// Let the exokernel know where the event manager is
	eventmanager_init();
	set_eventmanager_send(eventmanager_send);
	set_eventmanager_pumpEvents(eventmanager_pumpEvents);

	// Start task scheudler
	scheudler_init();

	// Drivers
    VGA_init();

    PIT_init(1000);	// Initialise the PIT to 100Hz
    keyboard_init();

    term_init();
}

void main(void)
{
	init();

	// Start fake shell to interact with the user in some way...
	fakeshell_init();
}
