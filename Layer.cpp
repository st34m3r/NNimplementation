#include "Layer.h"
#include <iostream>
Layer::Layer(int NbrNeurons,int Activation)
{
    this->NbrNeurons=NbrNeurons;
    this->Activation=Activation;
    this->Neurons.reserve(NbrNeurons);
    this->NbrOfInputs=0;
}
void Layer::Set_Dimension(int *TabNbrInputInNeurons)
{
    for(int i=0;i<NbrNeurons;i++)
    InputsPerNeuron.push_back(TabNbrInputInNeurons[i]);

}
void Layer::Set_Inputs(double *inp)
{
    for(int i=0; i<NbrNeurons; i++)
    {
        Neuron *neuron= new Neuron(InputsPerNeuron[i],Activation);
        Neurons.push_back(*neuron);
        this->NbrOfInputs+=InputsPerNeuron[i];
    }
    for(int i=0; i<NbrOfInputs; i++)
    {
        this->Inputs.push_back(inp[i]);
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
/*void Layer::Set_Inputs(vector<double> *alpha)
{
    for(int i=0; i<NbrNeurons; i++)
    {
        Neuron *neuron= new Neuron(InputsPerNeuron[i],Activation);
        Neurons.push_back(*neuron);
        this->NbrOfInputs+=InputsPerNeuron[i];
    }
    for(int i=0; i<NbrOfInputs; i++)
    {
        this->Inputs.push_back(alpha[i]);
    }
    int k=0;
    for(int i=0; i<NbrNeurons;i++)
    {
        for(int j=0; j<Neurons[i].GetNbrInputs();j++)
        {
            Neurons[i].GetInput().push_back(this->Inputs[k++]);
        }
    }


}*/
void Layer::Init_Layer()
{

    for(int i=0; i<NbrNeurons;i++)
    {

           Neurons[i].init();

    }
}
void Layer::Calc_Layer()
{

    for(int i=0; i<NbrNeurons;i++)
    {

           Neurons[i].calc();
           this->Ouputs.push_back(Neurons[i].getOutput());

    }

}
void Layer::Print_Layer_data()
{
    for(int i=0; i<NbrNeurons;i++)
    {

            Neurons[i].printData();


    }
}
Layer::~Layer()
{
    //dtor
}
