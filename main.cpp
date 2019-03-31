#include <iostream>
#include <pthread.h>
#include <time.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mutex> 
#include "Philosopher.h"
#include <unistd.h>

pthread_mutex_t mt;

bool run = true;

std::vector<pthread_t>threads;
std::vector<int>philosophers;

void *LifeTime(void *arg);

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    pthread_mutex_init(&mt, NULL);

    int number = 0;

    std::cout<<"Podaj ilosc filozofow: "<<std::endl;
    std::cin>>number;
    
    threads.resize(number);

    for(int i = 0; i < number; i++)
    {
        philosophers.push_back(i+1);
    }

    for(int j = 0; j < number; j++)
    {
        pthread_create(&threads[j], NULL, LifeTime, &philosophers[j]);
    }

    char tmp;

    while(tmp != 'n')
    {
        tmp = static_cast<char>(std::cin.get());
        if (tmp == 'n') 
        {
            run = false;
        }
    }

    for(int k = 0; k < number; k++)
    {
        pthread_join(threads[k], NULL);
        std::cout<<"Philosopher "<< k+1 <<" has finished"<<std::endl ;
    }

    return 0;
}

void *LifeTime(void *arg)
{
    int *temp = (int *)arg;
    Philosopher philo (*temp);

    philo.setSate(rand()%3);

    while(run)
    {
        
        if(philo.getState() == Philosopher::State::Hungry)
        {   
            usleep(philo.RandTime());
            pthread_mutex_lock(&mt);
            philo.hungry();
            pthread_mutex_unlock(&mt);
            usleep(philo.RandTime());
            philo.setSate(Philosopher::State::Eating);
        }

        if(philo.getState() == Philosopher::State::Eating)
        {
            pthread_mutex_lock(&mt);
            philo.eat();
            pthread_mutex_unlock(&mt);
            usleep(philo.RandTime());
            philo.setSate(Philosopher::State::Thinking);
        }
        
        if(philo.getState() == Philosopher::State::Thinking)
        {
            pthread_mutex_lock(&mt);
            philo.think();
            pthread_mutex_unlock(&mt);
            usleep(philo.RandTime());
            philo.setSate(Philosopher::State::Hungry);
        }
        
    }

    return nullptr;
}
