#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H
#include "Layer.h"

class HiddenLayer:public Layer
{
    public:
        HiddenLayer(int NbrNeurons,int Activation,Layer &layer);
        virtual ~HiddenLayer();

    protected:

    private:
};

#endif // HIDDENLAYER_H
