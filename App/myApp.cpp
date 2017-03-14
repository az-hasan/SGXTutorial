/* Aisha Hasan */

#include <stdio.h> //FILENAME_MAX

#include "sgx_urts.h"
#include "myApp.h"
#include "Enclave_u.h"
//#include <string.h>

# define MAX_PATH FILENAME_MAX
sgx_enclave_id_t global_eid = 0;

/* OCall functions */
void ocall_print_string(const char *str)
{
    /* Proxy/Bridge will check the length and null-terminate 
     * the input string to prevent buffer overflow. 
     */
    printf("%s", str);
}

/* Initialize the enclave:
 *
 *   Step 1: try to retrieve the launch token saved by last transaction
 *   Step 2: call sgx_create_enclave to initialize an enclave instance
 *   Step 3: save the launch token if it is updated
 */
int initialise_enclave(void){

	int updated = 0;
	sgx_status_t ret = SGX_SUCCESS;
	sgx_launch_token_t token = {0};
	char token_path[MAX_PATH] = {'\0'};

	/* Step 1: try to retrieve launch token saved by last transaction */

	
	/* Step 2: call sgx_create_enclave to initialise an enclave instance*/
	
	//sgx_status_t sgx_create_enclave(
		/* const char *file_name, const int debug, sgx_launch_token_t *launch_token, int *launch_token_updated,
		sgx_enclave_id_t *enclave_id, sgx_misc_attribute_t *misc_attr); */
	ret = sgx_create_enclave(ENCLAVE_FILENAME, SGX_DEBUG_FLAG, &token, &updated, &global_eid, NULL);

	if(ret != SGX_SUCCESS){
		printf("App: error %d, failed to create enclave.\n", ret);
		return -1;
	}

	/* Step 3: save launch token if it's been updated*/
		//print errors, save launch token if it's been updated
	return 0;
}

int main(int argc, char *argv[]){

	(void) argc;
	(void) argv;
	PasswordManagerCore passman;
	int rv, num_accounts;
	int ndx = 1;
	std::string account_name;

	//START setting vault path and output file
	
	std::string vaultfolder = "./Vault";
	std::string vaultpath = "./Vault/testvault.vlt";

	std::cout << "AISHA PRINT Vault folder: " << vaultfolder << "\n";
	std::cout << "AISHA PRINT Vault file: " << vaultpath << "\n";

	rv = passman.vault_create(vaultpath);
	rv = passman.vault_get_count_all(&num_accounts);
    rv = passman.vault_get_info(ndx, &account_name);

	std::cout << "AISHA PRINT num_accounts: " << num_accounts << "\n";
	std::cout << "AISHA PRINT account_info: " << account_name << "\n";

	//END

	if (initialise_enclave() < 0){
		return -1;
	} 

	//ECALLS
	if (SGX_SUCCESS != sgx_destroy_enclave(global_eid)){
		return -1;
	}

	printf("Info: SampleEnclave successfully returned.\n");

    printf("Enter a character before exit ...\n");
    getchar();

	return 0;
}
