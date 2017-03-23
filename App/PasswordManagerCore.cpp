/*
 * |Aisha Hasan|
 *
 * The |PasswordManagerCore.cpp| file.
 * 
 * Intel's Windows tutorial version of this file interacts with the C# GUI
 * and marshalls data to the native (enclave) layer.
 *
 * Contains functions to lock/unlock/open vault, set account info/pass, get
 * account info/pass/count, set/change master_password, generate password,
 * update vault (not sure what this does yet?).
 */

#include "PasswordManagerCore.h"
using namespace std;

PasswordManagerCore::PasswordManagerCore(void){
	num = 444;
	dummyaccount = "SEPTEMBER";
}

PasswordManagerCore::~PasswordManagerCore(void){
	num = 400;
}

/*
 * Creates vault file if it doesn't already exist.
 * If it does exist, return.
 *
 * There is no error checking for file permissions/incomplete paths
 */
int PasswordManagerCore::vault_create(string path){
	int rv = NL_STATUS_OK;

	rv = vaultfile.create_file(path);
	if(rv != NL_STATUS_OK)	return rv;	

	//initialise an empty vault: ew_init
	rv = ecall_initialise();

 	printf("AISHAPRINT FILE: %s LINE:%d created enclaveID: [%lu].\n",
        __FILE__, __LINE__, enclaveID);


	return rv;
}

/* Destroys the enclave */
int PasswordManagerCore::vault_destroy(){
	
	printf("AISHAPRINT FILE: %s LINE:%d destroy enclaveID: [%lu].\n",
        __FILE__, __LINE__, enclaveID);

	if (sgx_destroy_enclave(enclaveID) != SGX_SUCCESS){
        return NL_STATUS_SGXERROR;
    }
	
	return NL_STATUS_OK;
}

int PasswordManagerCore::vault_get_count_all(int *count){
	int rv = SUCCESS;
	*count = SUCCESS;
	return rv;
}

int PasswordManagerCore::vault_get_info(int ndx, string *account_name){
	int rv = SUCCESS;
	*account_name = dummyaccount[ndx];
	return rv;
}
