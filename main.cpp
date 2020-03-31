#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Neuron.h"
#include <ctime>
#include <iomanip>
#define e 2.718281828
#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"
#include <time.h>
using namespace std;
//Activation Dispo : SIGMOID,STEP,TANH,IDENTITY

int main()
{


    clock_t tStart = clock();
    srand(time(NULL));

    int neuron_Dimension[4]={1,2,2,2};
    InputLayer inputlayer(4,SIGMOID,neuron_Dimension);
    double INPUTS[8]=  {1.01,
                        1.02,
                        1.03,
                        1.04,
                        1.05,
                        1.06,
                        1.07,
                        1.08};

    inputlayer.Set_Inputs(INPUTS);
    inputlayer.Init_Layer();
    inputlayer.Calc_Layer();

    HiddenLayer hiddenlayer(3,SIGMOID,inputlayer);
    hiddenlayer.Init_Layer();
    hiddenlayer.Calc_Layer();

    OutputLayer outputlayer(4,SIGMOID,hiddenlayer);
    outputlayer.Init_Layer();
    outputlayer.Calc_Layer();

    outputlayer.Print_Layer_data();
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
   // system("PAUSE");

    return 0;
}
