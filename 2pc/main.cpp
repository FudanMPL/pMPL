#include <iostream>
#include "ml/linear.h"
#include "ml/logistic.h"
#include "ml/nn.h"

using namespace std;
using namespace Eigen;

int party = 0;
SocketManager::pMPL tel;

int main(int argc, char **argv)
{
    Mat::init_public_vector();
    Secret_Mul::init();
    Boolean_Share::init();
    if (argc < 2)
    {
        DBGprint("Please enter party index:\n");
        scanf("%d", &party);
    }
    else
    {
        party = argv[1][0] - '0';
    }
    DBGprint("party index: %d\n", party);
    tel.init();
    IOManager::init();
    Secret_Mul::get_Triplets();
    if (ML == 0)
        Linear::train_model();
    else if (ML == 1)
        Logistic::train_model();
    else if (ML == 2)
        NN::train_model();
    return 0;
}