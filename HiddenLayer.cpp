#include "HiddenLayer.h"

HiddenLayer::HiddenLayer(int NbrNeurons,int Activation,Layer &P_layer):Layer(NbrNeurons,Activation)
{
    //set dimesion
    for(int i=0;i<this->NbrNeurons;i++)
    InputsPerNeuron.push_back(P_layer.get_Ouputs().size());
    //set Inputs
    for(int i=0; i<NbrNeurons; i++)
    {
        Neuron *neuron= new Neuron(InputsPerNeuron[i],Activation);
        Neurons.push_back(*neuron);
        this->NbrOfInputs+=InputsPerNeuron[i];
    }
    for(int i=0; i<NbrNeurons; i++)
    {
    for(int j=0; j<P_layer.get_Ouputs().size(); j++)
        {
            this->Inputs.push_back(P_layer.get_Ouputs()[j]);
        }
    }
    int k=0;
    for(int i=0; i<NbrNeurons;i++)
    {
        for(int j=0; j<Neurons[i].GetNbrInputs();j++)
        {
            Neurons[i].GetInput().push_back(this->Inputs[k++]);
        }
    }

}

HiddenLayer::~HiddenLayer()
{
    //dtor
}
