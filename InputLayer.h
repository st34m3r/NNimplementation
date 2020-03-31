#ifndef INPUTLAYER_H
#define INPUTLAYER_H
#include "Layer.h"

class InputLayer : public Layer
{
    public:
        InputLayer(int NbrNeurons,int Activation,int *TabNbrInputInNeurons);
        virtual ~InputLayer();

    protected:

    private:
};

#endif // INPUTLAYER_H
