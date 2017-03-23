#ifndef _ENCLAVE_BRIDGE_H_
#define _ENCLAVE_BRIDGE_H

#include <iostream>
#include <cstdlib>

#include "Enclave_u.h"
#include "sgx_urts.h"
#include "PasswordManagerError.h"

#ifdef __cplusplus
extern "C" {
#endif


#define NOT_LAUNCHED 0
#define LAUNCHED 1
#define ENCLAVE_FILENAME "enclave.signed.so"

extern sgx_enclave_id_t enclaveID;
static sgx_status_t sgx_status= SGX_SUCCESS;
static int launched = NOT_LAUNCHED;
static int updated = 0;
static sgx_launch_token_t token = {0};

int get_enclave(sgx_enclave_id_t *eid);
int create_enclave(sgx_enclave_id_t *eid);
int ecall_initialise(void);

#ifdef __cplusplus
};
#endif

#endif
