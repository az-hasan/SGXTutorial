/*
 * Aisha Hasan
 *
 * Header file for Enclave.cpp
 *
 */

#ifndef _ENCLAVE_H_
#define _ENCLAVE_H_

#include <stdlib.h>
#include <assert.h>

#include "sgx_trts.h"
#include "../App/PasswordManagerError.h"
#include "E_Vault.h"

#if defined(__cplusplus)
extern "C" {
#endif

int initialise();

#if defined(__cplusplus)
}
#endif

#endif /* !_ENCLAVE_H_ */
