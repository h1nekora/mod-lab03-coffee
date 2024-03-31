// Copyright 2024 UNN-IASR
#include "Automata.h"
#include <string>
#include<vector>
#include<iostream>

Automata::Automata() {
    cash = 0;
    state = OFF;
    menu = { "Espresso",
    "Cappuccino",
    "Latte",
    "Cacao",
    "Hot chocolate",
    "Americano",
    "Black tea",
    "Green tea" };
    prices = { 100, 150, 180, 50, 75, 110, 80, 80 };
}
Automata::~Automata() {}
void Automata::on() {
    if (state == OFF) {
    state = WAIT;
    }
}
void Automata::off() {
    if (state == WAIT) {
    state = OFF;
    }
}
void Automata::coin(int money) {
    if (state == WAIT || state == ACCEPT) {
    state = ACCEPT;
    cash += money;
    }
}
void Automata::getMenu() {
    if (state == WAIT || state == ACCEPT) {
    std::cout << "MENU: ";
    for (int index = 0; index < menu.size(); index++) {
    std::cout << index+1 << ") " << menu[index];
    std::cout << " " << prices[index] << " | ";
    }
    std::cout<< std::endl;
    }
}
STATES Automata::getState() {
    return state;
}
void Automata::choice(int variant) {
    if (state == ACCEPT && variant >= 1 && variant <= menu.size()) {
    state = CHECK;
    check(variant);
    }
}
void Automata::check(int variant) {
    if (cash >= prices[variant - 1]) {
    cash -= prices[variant - 1];
    cook();
    } else {
    state = ACCEPT;
    }
}
void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
    cash = 0;
    state = WAIT;
    }
}
void Automata::cook() {
    state = COOK;
    finish();
}
void Automata::finish() {
    cash = 0;
    state = WAIT;
}
