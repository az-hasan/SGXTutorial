/*
 * Aisha Hasan
 *
 * Enclave.cpp file
 *
 */


#include <stdarg.h>
#include <stdio.h>      /* vsnprintf */

#include "Enclave.h"
#include "Enclave_t.h"  /* print_string */

E_Vault vault;

int initialise(){
	return vault.v_initialise();
}

