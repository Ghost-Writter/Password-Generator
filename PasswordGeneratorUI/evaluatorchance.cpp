#include "evaluatorchance.h"

/*
EvaluatorChance::EvaluatorChance()
{
    resetArguments(MIN_COUNT_SYMBOLS, MIN_PASSWORD_LENGTH);
}
*/

/******* PUBLIC **********/

EvaluatorChance::EvaluatorChance(
        const int &inputChancePower,
        const int &inputSpeed,
        const int &inputValidity,
        const int &inputStrong,
        const int &inputLength)
{
    resetArguments(inputStrong, inputLength);
    setArguments(inputChancePower, inputSpeed, inputValidity);
    calculationPowerAndLength();
}

int EvaluatorChance::getStrong() const
{
    return this->strong;
}

int EvaluatorChance::getLength() const
{
    return this->length;
}

int EvaluatorChance::getSpeed() const
{
    return this->speed;
}

int EvaluatorChance::getValidity() const
{
    return this->validity;
}

int EvaluatorChance::getChancePower() const
{
    return this->chancePower;
}

void EvaluatorChance::setArguments(const int &inputChancePower, const int &inputSpeed, const int &inputValidity)
{
    this->chancePower = inputChancePower;
    this->speed = inputSpeed * 24 * 7;     //перевод скорости - в паролей на неделю
    this->validity = inputValidity / 7;         //перевод дни - в недели
}

/******* PRIVATE **********/

void EvaluatorChance::resetArguments(const int &inputStrong, const int &inputLength)
{
    this->chancePower = 0;
    this->strong = inputStrong;
    this->length = inputLength;
    this->speed = 0;
    this->validity = 0;
}

double EvaluatorChance::calculationLowLimit()
{
    double tempSpeed = (double) getSpeed();
    double tempValidity = (double) getValidity();
    double tempPower = (double) getChancePower();

    double result = tempSpeed * tempValidity * pow(10, tempPower);

    return result;
}

double EvaluatorChance::calculationLowLimit(const int &inputChancePower, const int &inputSpeed, const int &inputValidity)
{
    double tempSpeed = (double) inputSpeed;
    double tempValidity = (double) inputValidity;
    double tempPower = (double) inputChancePower;

    double result = tempSpeed * tempValidity * pow(10, tempPower);

    return result;
}

double EvaluatorChance::calculationCombination()
{
    double tempStrong = (double) getStrong();
    double tempLength = (double) getLength();

    double result = pow(tempStrong, tempLength);

    return result;
}

double EvaluatorChance::calculationCombination(const int &inputStrong, const int &inputLength)
{
    double tempStrong = (double) inputStrong;
    double tempLength = (double) inputLength;

    double result = pow(tempStrong, tempLength);

    return result;
}

void EvaluatorChance::calculationPowerAndLength()
{
    bool isWork = true;

    int tempStrong = getStrong();
    int tempLegth = getLength();

    double lowLimit = calculationLowLimit();

    while(isWork)
    {
        QApplication::processEvents();

        double combination = calculationCombination(tempStrong, tempLegth);

        if(combination < lowLimit)
        {
            if(tempStrong < MAX_COUNT_SYMBOLS)
            {
                tempStrong++;
            }
            else
            {
                tempStrong = MIN_COUNT_SYMBOLS;
                tempLegth++;
            }
        }
        else
        {
            this->strong = tempStrong;
            this->length = tempLegth;

            isWork = false;
        }
    }
}
