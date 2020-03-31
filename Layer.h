#ifndef LAYER_H
#define LAYER_H
#include "Neuron.h"
#include <vector>

class Layer
{
    //public:
    protected:

        std::vector<Neuron> Neurons;
        std::vector<int>InputsPerNeuron;
        int Activation;
        int NbrNeurons;
        Layer *NextLayer;
        Layer *PreviousLayer;
        std::vector<double> Inputs;
        std::vector<double> Ouputs;
        int NbrOfInputs;
    private:

    public:
        std::vector<Neuron> get_Neurons()
        {
            return Neurons;
        }
        std::vector<int> get_InputsPerNeuron()
        {
            return InputsPerNeuron;
        }
        int get_Activation()
        {
            return Activation;
        }
        int get_NbrNeurons()
        {
            return NbrNeurons;
        }
        std::vector<double> get_Inputs()
        {
            return Inputs;
        }
        std::vector<double> get_Ouputs()
        {
            return Ouputs;
        }
        Layer(int NbrNeurons,int Activation);
        void Set_Inputs(double *inp);
       // void Set_Inputs(vector <double> alpha);
        void Set_Dimension(int *TabNbrInputInNeurons);
        void Init_Layer();
        void Calc_Layer();
        void Print_Layer_data();
        virtual ~Layer();

};

#endif // LAYER_H
