
#ifndef IOMANAGER_H 
#define IOMANAGER_H

#include "Mat.h"
#include "../Constant.h"
#include <cassert>
extern int party;

class IOManager {
public:
    static MatrixXu train_data, train_label;
    static MatrixXu test_data, test_label;
    // static int getsize(ifstream &in);               //获取文件的列数
    static void init();
    static void load_data(ifstream &in, MatrixXu &data, MatrixXu &label, int size);
    static void secret_share(MatrixXu& data, MatrixXu& label, string category);
    static void load_ss(ifstream& in, MatrixXu& data, MatrixXu& label, int size);
};



#endif //IOMANAGER_H 