#pragma once
#include <iostream>
#include <vector>
#include "Fork.h"

class Philosopher
{
    private:
        int philosopherId;
        int state;
        Fork left, right;

    public:
        Philosopher();
        Philosopher(int number);
        ~Philosopher();
        void eat();
        void think();
        void hungry();
        int getPhilosopherId();
        void setPhilosopherId(int number);
        int getState();
        void setSate(int state);
        int RandTime();

    enum State
    {
        Thinking,
        Hungry,
        Eating
    };
};