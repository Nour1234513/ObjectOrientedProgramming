
#ifndef WALLET_H
#define WALLET_H




class Wallet
{
public:
    Wallet();
    void stoppaInvinst(int pengar);
    void drabortPengar(int pengar);
    int antalKR()const;
private:
    int m_wallet;
};

#endif // WALLET_H
