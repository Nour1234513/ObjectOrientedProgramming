
#include "wallet.h"

Wallet::Wallet()
{

}

void Wallet::stoppaInvinst(int pengar)
{
    m_wallet+=pengar;
}

void Wallet::drabortPengar(int pengar)
{
    m_wallet-=pengar;
}

int Wallet::antalKR()const
{
    return m_wallet;
}

