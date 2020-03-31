#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H
#include "Layer.h"

class OutputLayer: public Layer
{
    public:
       OutputLayer(int NbrNeurons,int Activation,Layer &P_layer);
        virtual ~OutputLayer();

    protected:

    private:
};

#endif // OUTPUTLAYER_H
