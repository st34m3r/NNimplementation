#include "InputLayer.h"

InputLayer::InputLayer(int NbrNeurons,int Activation,int *TabNbrInputInNeurons):Layer(NbrNeurons,Activation)
{
    Set_Dimension(TabNbrInputInNeurons);
}

InputLayer::~InputLayer()
{
    //dtor
}
