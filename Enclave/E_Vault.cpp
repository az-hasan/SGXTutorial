#include "E_Vault.h"

E_Vault::E_Vault(){
    state = _VST_UPDSIZE;
    naccounts = 0;
}

E_Vault::~E_Vault(){

}

int E_Vault::v_initialise(){
    int rv; //change "int" to "crypto_status_t"
    //this->clear();
    //generate db_key in Crypto.cpp
    naccounts = 4;
    return NL_STATUS_OK;
}
