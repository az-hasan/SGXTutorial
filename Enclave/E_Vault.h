#ifndef _E_VAULT_H_
#define _E_VAULT_H_

#include "../App/PasswordManagerError.h"
#define _VST_UPDSIZE    0X00000004UL

class E_Vault{
    int state;
    int naccounts;

    //E_AccountRecord accounts[MAX_ACCOUNTS];

public:
    E_Vault();
    ~E_Vault();

    int v_initialise();
};


#endif
