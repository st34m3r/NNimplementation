#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include<random>
#define SIGMOID 0
#define STEP 1
#define TANH 2
#define IDENTITY 3
class Neuron
{
    //public:
    private:
    protected:

        std::vector<double>Inputs;
        std::vector<double>Weights;
        int Activation;
        double Bias;
        double OutputBeforeActivation;
        double Output;
        int NbrInputs;
        double Activation_function(double a);
    public:
        std::vector<double>& GetInput();
        double getOutputBeforeActivation();
        double getOutput();
        int GetNbrInputs();
        void Set_Inputs(double *tab);
        void printData();
        Neuron(int NbrInputs,int a);
        virtual ~Neuron();
        void init();
        void calc();
        double rand_float( float a, float b )
        {
            return ( rand() / (float)RAND_MAX ) * ( b - a ) + a;
        }


};

#endif // NEURON_H
