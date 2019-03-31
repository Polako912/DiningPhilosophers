#include "Philosopher.h"
#include <iostream>
#include <random>

Philosopher::Philosopher()
{

}

Philosopher::Philosopher(int philosopherId)
{
    this->philosopherId = philosopherId;
}

Philosopher::~Philosopher()
{
    
}

void Philosopher::eat()
{
    std::cout<<"Philosopher " << philosopherId << " is eating" << std::endl;
}

void Philosopher::think()
{
    std::cout<<"Philosopher " << philosopherId << " is thinking" << std::endl;
}

void Philosopher::hungry()
{
    std::cout<<"Philosopher " << philosopherId << " is hungry" << std::endl;
}

int Philosopher::getPhilosopherId()
{
    return philosopherId;
}

void Philosopher::setPhilosopherId(int number)
{
    this->philosopherId = number;
}

int Philosopher::getState()
{
    return state;
}

void Philosopher::setSate(int state)
{
    Philosopher::state = state;
}

int Philosopher::RandTime()
{
    return static_cast<int>(((3,5 - 2,5) * ((double) rand() / (double) RAND_MAX) + 2,5) * 1000000);
}