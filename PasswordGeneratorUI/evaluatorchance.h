#ifndef EVALUATORCHANCE_H
#define EVALUATORCHANCE_H

#define MAX_COUNT_SYMBOLS 61
#define MIN_COUNT_SYMBOLS 26
#define MIN_PASSWORD_LENGTH 6

#define MIN_STRONG 26
#define MIN_LENGTH 6

#include <QApplication>

#include <math.h>

class EvaluatorChance
{
public:

    //EvaluatorChance();
    EvaluatorChance(
            const int &inputChancePower,
            const int &inputSpeed,
            const int &inputValidity,
            const int &inputStrong,
            const int &inputLength);

    int getStrong() const;
    int getLength() const;
    int getSpeed() const;
    int getValidity() const;
    int getChancePower() const;


    void setArguments(const int &inputChancePower, const int &inputSpeed, const int &inputValidity);

private:

    int strong;         //мощность А
    int length;         //длина пароля L
    int speed;          //скорость перебора V
    int validity;       //период действия Т
    int chancePower;    //степень вероятности подбора P * (-1)

    void resetArguments(const int &inputStrong, const int &inputLength);

    double calculationLowLimit();
    double calculationLowLimit(const int &inputChancePower, const int &inputSpeed, const int& inputValidity);

    double calculationCombination();
    double calculationCombination(const int &inputStrong, const int &inputLength);

    void calculationPowerAndLength();
};

#endif // EVALUATORCHANCE_H
