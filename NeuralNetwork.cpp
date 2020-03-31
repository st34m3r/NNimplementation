#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(int Nbr_neuron_input,int Activation,int *TabNbrInputInNeurons,int nbr_hidden,int Nbr_neuron_hidden)
{

    inputlayer = new InputLayer(Nbr_neuron_input,Activation,TabNbrInputInNeurons);
    for(int i=0;i<nbr_hidden;i++)
    {
        if(i==0)
        {
            HiddenLayer *hdd= new HiddenLayer(Nbr_neuron_hidden,Activation,*inputlayer);
            hiddenlayer.push_back(*hdd);


        }
        else
        {
            HiddenLayer *hdd= new HiddenLayer(Nbr_neuron_hidden,Activation,hiddenlayer[i-1]);
            hiddenlayer.push_back(*hdd);


        }

    }
}

NeuralNetwork::~NeuralNetwork()
{

}
