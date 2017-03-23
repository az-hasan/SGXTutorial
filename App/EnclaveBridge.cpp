#include "EnclaveBridge.h"

sgx_enclave_id_t enclaveID = 0;

int get_enclave(sgx_enclave_id_t *eid){
	if(launched) return launched;
	else return create_enclave(NULL);
}

int create_enclave(sgx_enclave_id_t *eid){
	
	/* call sgx_create_enclave to initialise an enclave instance */
  	/* sgx_status_t sgx_create_enclave(
		const char *file_name, const int debug, sgx_launch_token_t *launch_token, int *launch_token_updated,
		sgx_enclave_id_t *enclave_id, sgx_misc_attribute_t *misc_attr); */

	sgx_status = sgx_create_enclave(ENCLAVE_FILENAME, SGX_DEBUG_FLAG, &token, &updated, &enclaveID, NULL);
	
	if(sgx_status == SGX_SUCCESS){
    	printf("AISHAPRINT FILE: %s LINE:%d created enclaveID: [%lu].\n",
        __FILE__, __LINE__, enclaveID);

		if(eid != NULL) *eid = enclaveID;
		launched = LAUNCHED;
		return 1;
	}

	return 0;
}

int ecall_initialise(){
	int rv = NL_STATUS_OK;

	if(!get_enclave(NULL)) return NL_STATUS_SGXERROR;
	sgx_status = initialise(enclaveID, &rv);

	// If our enclave crashed try loading it again.
	return rv;
}


