// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(ON, test1) {
    Automata testmachine;
    testmachine.on();
    EXPECT_EQ(WAIT, testmachine.getState());
}

TEST(OFF, test2) {
    Automata testmachine;
    testmachine.on();
    testmachine.off();
    EXPECT_EQ(OFF, testmachine.getState());
}

TEST(COIN, test3) {
    Automata testmachine;
    testmachine.on();
    testmachine.coin(10);
    testmachine.coin(10);
    EXPECT_EQ(ACCEPT, testmachine.getState());
}

TEST(COIN2, test4) {
    Automata testmachine;
    testmachine.on();
    testmachine.coin(10);
    EXPECT_EQ(ACCEPT, testmachine.getState());
}

TEST(CANCEL, test5) {
    Automata testmachine;
    testmachine.on();
    testmachine.coin(10);
    testmachine.cancel();
    EXPECT_EQ(WAIT, testmachine.getState());
}

TEST(CHOICE, test6) {
    Automata testmachine;
    testmachine.on();
    testmachine.coin(1000);
    testmachine.choice(1);
    EXPECT_EQ(WAIT, testmachine.getState());
}

TEST(CHOICE2, test7) {
    Automata testmachine;
    testmachine.on();
    testmachine.coin(10);
    testmachine.choice(1);
    EXPECT_EQ(ACCEPT, testmachine.getState());
}

TEST(FALSEON, test8) {
    Automata testmachine;
    testmachine.choice(1);
    EXPECT_EQ(OFF, testmachine.getState());
}

TEST(FALSECOIN, test9) {
    Automata testmachine;
    testmachine.on();
    testmachine.choice(1);
    EXPECT_EQ(WAIT, testmachine.getState());
}

TEST(FALSEOFF, test10) {
    Automata testmachine;
    testmachine.on();
    testmachine.coin(10);
    testmachine.off();
    EXPECT_EQ(ACCEPT, testmachine.getState());
}
