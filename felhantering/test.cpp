#include "myTrace.h" // min traceklass
#include <iostream>
#include <stdexcept>

USING_COUT_TRACE

using namespace std;
void doIt(int nummer) {
  tracemex(to_string(nummer));
  if (nummer == 108)
    throw runtime_error("tekniskt fel, försök igen!");
    traceMsg("Uppgiften slutförd");
}
void utforUppgift(int nummer) {
  traceme;
  traceMsg("allokerar massa minne");
  const int antalHeltal = 1000000;
  int *pMem = new int[antalHeltal];
  doIt(nummer);
  traceMsg("lämnar tillbaka minne");
  delete[] pMem;
}

void uppgiftsloop() {
  cout << "Ange nummer på uppgifter att utföras." << endl;
  cout << "Avsluta med ett negativt tal." << endl;
  while (true) {
    cout << "Uppgiftsnummer:";

    int nummer = 0;
    cin >> nummer;
    if (nummer < 0)
      break;
    try{
        utforUppgift( nummer );
    }
    catch (runtime_error fel){
        cout << "Ett fel inträffade" << endl;
        cout << fel.what() << endl;
    }
   // utforUppgift(nummer);
  }
}
