#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"

class NeuralNetwork
{

    protected:
        InputLayer *inputlayer;
        std::vector <HiddenLayer>hiddenlayer;
        OutputLayer *outputlayer;
        std::vector <double>NN_Inputs;
        std::vector <double>NN_Outputs;
        int nbrHiddenlayer;
        int nbr_NN_Inputs;
        int nbr_NN_Outputs;
        int NN_activation;

    private:
    public:
        NeuralNetwork(int Nbr_neuron_input,int Activation,int *TabNbrInputInNeurons,int nbr_hidden,int Nbr_neuron_hidden);
        virtual ~NeuralNetwork();

};

#endif // NEURALNETWORK_H
