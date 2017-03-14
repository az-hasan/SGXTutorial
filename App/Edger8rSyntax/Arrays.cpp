/*
 * Aisha Hasan
 *
 * Arrays.cpp - for App (untrusted)
 *
 */

#include "../myApp.h"
#include "Enclave_u.h"


/* edger8r_array_attributes:
 *   Invokes ECALLs declared with array attributes.
 */

void edger8r_array_attributes(void)
{
    sgx_status_t ret = SGX_ERROR_UNEXPECTED;

    /* user_check */
    int arr1[4] = {0, 1, 2, 3};
    ret = ecall_array_user_check(global_eid, arr1);
    if (ret != SGX_SUCCESS)
        abort();

    /* make sure arr1 is changed */
    for (int i = 0; i < 4; i++)
        assert(arr1[i] == (3 - i));
}