#include <iostream>
#include"Automata.h"
int main()
{
    Automata automat;
    automat.on();
    automat.getMenu();
    automat.coin(100);
    automat.choice(2);
    automat.coin(50);
    automat.choice(2);
    automat.off();
}
