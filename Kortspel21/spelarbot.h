
#ifndef SPELARBOT_H
#define SPELARBOT_H
#include "abstraktspelare.h"



class Spelarbot:public abstraktspelare
{

    // abstraktspelare interface
public:
    Spelarbot(int antalPartierAttspela);
    bool villSpela() override;
    bool villHaKort() const override;
    void tagEmotKort(const Kort &kort) override;
    void bankenTogKort(const Kort &kort) override;
    void KortlekenHarBlandats() override;
    void speletAvslutat(bool spelarenVann, int vinnst) override;
    int hurmycketvilldusattsa() override;
    int pengarIKonto() override;
    bool villDudoublera(int pricepool) override;
     Korthand &korthand() override;
private:
    Korthand m_hand;
    int m_antalPartierAttSpela;
    int m_antalSpeladeSpel;
    float m_totalvinst;
    int botwallet;
};
#endif // SPELARBOT_H
