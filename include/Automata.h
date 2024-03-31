// Copyright 2024 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include<string>
#include<vector>
enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
    int cash;
    std::vector<std::string>menu;
    std::vector <int> prices;
    STATES state;
 public:
    Automata();
    ~Automata();
    void on();
    void off();
    void coin(int money);
    void getMenu();
    STATES getState();
    void choice(int variant);
    void check(int variant);
    void cancel();
    void cook();
    void finish();
};
#endif // INCLUDE_AUTOMATA_H_
