
#include <iostream>
#include <cstdio>
#include "../util/Mat.h"
#include "../Constant.h"
#include "../util/IOManager.h"
#include "../core/Secret_Mul.h"
#include <vector>

//test
void transform(int64 n){
    int i,j = 0;
    int64 a[1000];
    while(n > 0)
    {
        a[j]=n%2;
        n/=2;
        j++;    
    }
    for(i=j-1;i>=0;i--)
        std::cout<<a[i];
    std::cout<<endl;
}

SocketManager::pMPL tel;
int party;
int main(int argc, char** argv){
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
    time_t t;
    srand(party * time(&t));
    //Initialization
    Mat::init_public_vector();    
    tel.init();
    vector<int64> res;
    Matrixint64 x(1,1), pre_shared_k(1,1);
    pre_shared_k = Mat::randomMatrixint64(1,1);
    res = Constant::Util::edabits(); //generate edabits
    std::cout<<res[0]<<std::endl<<(res[0]>>20)<<std::endl<<res[65]<<std::endl;
    // transform(res[0]);
    for(int i = 1; i < 65; i++){
        std::cout << res[i];
    }
    // transform(res[65]);
    for(int i = 66; i < 110; i++){
        std::cout << res[i];
    }
    ofstream F0;
    F0.open("truncation_"+std::to_string(party)+".txt");
    for (int i = 0; i < 110; i++)
    {
        F0 << res[i] << ',';
    }
    F0 << pre_shared_k(0,0) << ',' << std::endl;
    F0.close();
    x(0,0) = res[0]/Mat::A_inv_123(0,party);
    if(party == 0){
        Matrixint64 pre_shared_k_1(1,1), pre_shared_k_2(1,1), pre_shared_k_3(1,1), share_val_1(1,1), share_val_2(1,1);
        pre_shared_k_3 = Mat::randomMatrixint64(1,1);
        tel.receive(&pre_shared_k_1, 1);
        tel.receive(&pre_shared_k_2, 2);
        tel.receive(&share_val_1, 1);
        tel.receive(&share_val_2, 2);
        x(0,0) = Mat::A_plus(0,1) * pre_shared_k_1(0,0) + Mat::A_plus(0,2) * pre_shared_k_2(0,0) - pre_shared_k_3(0,0);
        std::cout<<"x(0,0) is "<<x(0,0)<<std::endl;
        res = Constant::Util::edabits(x(0,0)); //generate edabits
        ofstream F1;
        F1.open("truncation_0.txt",ios::app);
        for (int i = 0; i < 110; i++)
        {  
            F1 << res[i] << ',';
        }
        F1 << pre_shared_k_3(0,0) << ',' << std::endl;
    }
    else{
        tel.send(&pre_shared_k, 0);
        x = x + pre_shared_k;
        tel.send(&x, 0);
    }
}