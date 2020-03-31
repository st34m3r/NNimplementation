#include "Neuron.h"
#include <math.h>
#include <iostream>
using namespace std;


    Neuron::Neuron(int NbrInputs,int act)
    {
        Bias=-1;
        this->NbrInputs=NbrInputs;
        Inputs.reserve(NbrInputs);
        Weights.reserve(NbrInputs+1);
        this->Activation=act;
    }

    void Neuron::Set_Inputs(double *tab)
    {
        for(int i=0;i<NbrInputs;i++)
        {
           Inputs.push_back(*(tab+i));
        }
    }
    double Neuron::getOutputBeforeActivation()
    {
        return OutputBeforeActivation;
    }
    double Neuron::getOutput()
    {
        return Output;
    }
    int Neuron::GetNbrInputs()
    {
        return NbrInputs;
    }


    std::vector<double>& Neuron::GetInput()
    {
        return Inputs;
    }

    void Neuron::init()
    {

        for(int i=0;i<=NbrInputs;i++)
        {
           Weights.push_back(rand_float(-1.0,1.0));
        }
    }



    void Neuron::calc()
    {
        OutputBeforeActivation=0.0;
        if(NbrInputs>0)
        {
            for(int i=0;i<=NbrInputs;i++)
            {
               OutputBeforeActivation+=(i==NbrInputs)?(Bias*Weights[i]):(Weights[i]*Inputs[i]);
            }
            Output=Activation_function(OutputBeforeActivation);
        }
    }


    double Neuron::Activation_function(double a)
    {

        switch(Activation)
            {
            case 0:
                return 1.0/(1.0+exp(-a));
            break;
            case 1:
               return (a<0)?(-1):1;
            break;
            case 2:
                return double(exp(a)-exp(-a))/(exp(a)+exp(-a));
            break;
            case 3:
                return a;
            break;

            }
    }

    void Neuron::printData()
    {
            //cout <<"######################################"<<endl;
            cout <<"--------------- INPUTS ---------------"<<endl;
       for(int i=0;i<NbrInputs;i++)
            cout << "Input "<< i+1 <<"       value :"<<Inputs[i]<<endl;
            cout <<"--------------- WEIGHTS ---------------"<<endl;
       for(int i=0;i<=NbrInputs;i++)
            {
                if(i==NbrInputs)cout << "Bias Weight  "  <<" value :"<<Weights[i]<<endl;
                else            cout << "Weight "<< i+1 <<"      value :"<<Weights[i]<<endl;
            }
            cout <<"--------------- OUTPUT ---------------"<<endl;
            cout <<"Output before activation "<< OutputBeforeActivation<<endl;
            cout <<"Output "<< Output<<endl;
            cout << "Activation Used :"<<  ((Activation==0)?"SIGMOID":((Activation==1)?"STEP":((Activation==2)?"TANH":"IDENTITY"))) <<endl;
            cout <<"######################################"<<endl;
            cout << endl;
    }
Neuron::~Neuron()
{

}
