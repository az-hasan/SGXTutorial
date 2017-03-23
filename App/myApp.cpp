/* Aisha Hasan */

#include <stdio.h> //FILENAME_MAX

#include "sgx_urts.h"
#include "myApp.h"
#include "Enclave_u.h"
//#include <string.h>

# define MAX_PATH FILENAME_MAX

using namespace std;

int main(int argc, char *argv[]){

	(void) argc;
	(void) argv;
	PasswordManagerCore manager;
	int rv, num_accounts;
	int ndx = 1;
	string account_name;

	//START setting vault path and output file
	
	string vaultfolder = "./Vault";
	string vaultpath = "./Vault/testvault.vlt";

	cout << "AISHAPRINT Vault folder: " << vaultfolder << "\n";
	cout << "AISHAPRINT Vault file: " << vaultpath << "\n";

	rv = manager.vault_create(vaultpath);

	//	rv = manager.vault_get_count_all(&num_accounts);
  	//  rv = manager.vault_get_info(ndx, &account_name);

	//cout << "AISHA PRINT num_accounts: " << num_accounts << "\n";
	//cout << "AISHA PRINT account_info: " << account_name << "\n";

	rv = manager.vault_destroy();

	cout << "AISHAPRINT FILE: " << __FILE__ << " LINE:" << __LINE__ << " " <<
            "Vault destroyed?: [" << (rv==NL_STATUS_OK ? "NL_STATUS_OK" : "NL_STATUS_SGXERROR" ) << "].\n";
	
	//END

	printf("Info: SampleEnclave successfully returned.\n");
    printf("Enter a character before exit from program...\n");
    getchar();

	return 0;
}
