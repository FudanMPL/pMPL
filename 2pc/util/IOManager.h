#ifndef IOMANAGER_H 
#define IOMANAGER_H

#include "Mat.h"
#include "../Constant.h"
#include <cassert>
extern int party;

class IOManager {
public:
    static Matrixint64 train_data, train_label;
    static Matrixint64 test_data, test_label;
    // static int getsize(ifstream &in);               //获取文件的列数
    static void init();
    static void load_data(ifstream &in, Matrixint64 &data, Matrixint64 &label, int size);
    static void secret_share(Matrixint64& data, Matrixint64& label, string category);
    static void load_ss(ifstream& in, Matrixint64& data, Matrixint64& label, int size);
};



#endif //OMANAGER_H 