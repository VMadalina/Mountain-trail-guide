//
// Created by Madalina on 02/01/2021.
//

#pragma once
#include <iostream>
#include "../includes/Traseu.h"
class Strategy
{
public:
    virtual ~Strategy();
    virtual float DoAlgorithm();
};

Strategy::~Strategy() {}

float Strategy::DoAlgorithm() {
    return 0;
}

class Traseu_urs : public Strategy
{
public:
    float DoAlgorithm()
    {
        std::cout << "Ups! Acela este un urs. Va dura mai mult sa ajungem la destinatie...daca mai ajungem.\n";
        return 1.2;
    }
};

class Traseu_masina : public Strategy
{
public:
    float DoAlgorithm()
    {
        std::cout << "Niste persoane au fost generoase si v-au propus sa va duca cu masina o parte din"
                     "drum, pana unde e bun drumul. Veti ajunge mai repede la destinatie!\n";
        return -0.3;
    }
};

class Traseu_rana : public Strategy
{
public:
    float DoAlgorithm()
    {
        std::cout << "Auch! Cineva din grup si-a luxat glezna. Urcarea va fi mult mai lenta.\n";
        return 1.1;
    }
};

class Traseu_normal : public Strategy
{
public:
    float DoAlgorithm()
    {
        return 0;
    }
};


class Context {
private:
    Strategy *strategy_;
public:
    explicit Context(Strategy *strategy = nullptr) : strategy_(strategy) {
    }

    ~Context() {
        delete this->strategy_;
    }

    void set_strategy(Strategy *strategy) {
        delete this->strategy_;
        this->strategy_ = strategy;
    }

    float Situatie()
    {
        float result = this->strategy_->DoAlgorithm();
        return result;
    }
};
