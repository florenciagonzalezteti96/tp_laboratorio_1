#include "Operaciones.h"
#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>

float addNumbers (float, float);
float subtractNumbers(float, float);
float divideNumbers (float, float, char* errorMessage);
float multiplyNumbers (float, float);
int getFactorial (float);

float addNumbers (float firstNumber, float secondNumber){
    return firstNumber + secondNumber;
}

float subtractNumbers(float firstNumber, float secondNumber){
    return firstNumber - secondNumber;
}

float divideNumbers (float firstNumber, float secondNumber, char* errorMessage){
    float returnValue = 0;
    if(secondNumber == 0){
        returnValue = -1;
    }else{
        returnValue = firstNumber / secondNumber;
    }
    return returnValue;
}

float multiplyNumbers(float firstNumber, float secondNumber){
    return firstNumber * secondNumber;
}

int  getFactorial(float number)
{   int factorial;
    if(number == 0 || number == 1){
        factorial = 1;
    }else{
        factorial = number * (getFactorial(number - 1));
    }
    return factorial;
}
