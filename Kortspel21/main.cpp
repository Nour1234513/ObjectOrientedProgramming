#include <iostream>
#include <stdio.h>
#include "bankir.h"
#include "spelare.h"
#include "spelarbot.h"
int main()
{
   std::cout << "Kortspelet 21! " << std::endl;
   Bankir bank;
   Spelarbot Spelare(1000);
   bank.registreraSpelare(&Spelare);
   while (bank.harRegisteradeSpelare())
       bank.spelaEnOmgang();
   return 0;
}
