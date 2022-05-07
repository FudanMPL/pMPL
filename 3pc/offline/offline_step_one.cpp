
#include <iostream>
#include "../util/Mat.h"
#include "../Constant.h"
#include "../util/IOManager.h"
#include "../core/Secret_Mul.h"
#include <vector>

SocketManager::pMPL tel;
int party;
int main(int argc, char **argv)
{
    // srand(time(NULL)); // random seed

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

    // Initialization
    Mat::init_public_vector();
    tel.init();
    Tensor<int64, 3> ui(3, B, D), vi(3, D, 1), hi(3, B, 1);
    Tensor<int64, 3> ui_share(4, B, D), vi_share(4, D, 1), hi_share(4, B, 1);

    Matrixint64 ui_0(B, D), vi_0(D, 1), hi_0(B, 1), hi_1(B, 1), hi_2(B, 1), message_send(3, 1), message_recv(3, 1);
    message_send = Mat::randomMatrixint64(3, 1);
    message_recv = Mat::randomMatrixint64(3, 1);
    // where random_block is used to save pairs of random numbers to meet the need of algorithm, and random_block_temp to get the summarization of two random numbers from other party
    //  Matrixint64 random_block(D,2), random_block_sum(D,1), random_block_temp(D,1);

    /*where ui_rec_pr and vi_rec_pr are designed for privileged party
      These variables are designed to save the share values*/
    Matrixint64 temp_ui_0(B, D), temp_ui_1(B, D), temp_ui_2(B, D), temp_ui_3(B, D),
        temp_vi_0(D, 1), temp_vi_1(D, 1), temp_vi_2(D, 1), temp_vi_3(D, 1),
        temp_hi_0(B, 1), temp_hi_1(B, 1), temp_hi_2(B, 1), temp_hi_3(B, 1),
        ui_rec(B, D), vi_rec(D, 1), ui_rec_pr(B, D), vi_rec_pr(D, 1), hi_rec(B, 1), hi_rec_pr(B, 1);

    Constant::Clock *offline;
    offline = new Constant::Clock(2);
    for (int i = 0; i < 1000; i++)
    {
        // generate ui, vi
        ui = Mat::randomTensorRu3(B, D);
        vi = Mat::randomTensorRu3(D, 1);
        hi = Mat::randomTensorRu3(B, 1);

        // ui.setConstant(1);
        // vi.setConstant(1);
        // hi.setConstant(1);
        
        for (int i = 0; i < B; i++)
        {
            for (int j = 0; j < D; j++)
            {
                ui_0(i, j) = ui(0, i, j);
            }
        }
        for (int j = 0; j < D; j++)
        {
            vi_0(j, 0) = vi(0, j, 0);
        }

        // genrate random number, make sure that randomMatrixint64(i, 0) + randomMatrixint64(i, 1) != 0
        hi_0 = ui_0 * vi_0;

        // calculate their share
        Eigen::array<Eigen::IndexPair<int>, 1> product_dims = {Eigen::IndexPair<int>(1, 0)};
        ui_share = Mat::A_plus.contract(ui, product_dims);
        Eigen::array<Eigen::IndexPair<int>, 1> product_dims2 = {Eigen::IndexPair<int>(1, 0)};
        vi_share = Mat::A_plus.contract(vi, product_dims2);
        // send to others
        if (party == 0)
        {
            // send part
            // for ui
            for (int i = 0; i < B; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    temp_ui_2(i, j) = ui_share(2, i, j);
                    temp_ui_3(i, j) = ui_share(3, i, j);
                }
            }
            // std::cout << "Party 0 begins" << std::endl;
            // send the share to party one
            tel.send(&temp_ui_2, 2);
            // std::cout << "temp_ui_2 sended" << std::endl;
            // send the share to party two
            tel.send(&temp_ui_3, 3);
            // std::cout << "temp_ui_1 sended" << std::endl;

            // for vi

            for (int i = 0; i < D; i++)
            {
                temp_vi_2(i, 0) = vi_share(2, i, 0);
                temp_vi_3(i, 0) = vi_share(3, i, 0);
            }
            tel.send(&temp_vi_2, 2);
            // std::cout<<"temp_vi_2 sended" << std::endl;
            tel.send(&temp_vi_3, 3);
            // std::cout<<"temp_vi_1 sended" << std::endl;
            // receive_part

            // ui_0 and ui_1
            // original share
            for (int i = 0; i < B; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    ui_rec(i, j) = ui_share(0, i, j);
                    ui_rec_pr(i, j) = ui_share(1, i, j);
                }
            }
            // receive from party 2
            tel.receive(&temp_ui_2, 2);
            // std::cout<<"temp_ui_1 sended" << std::endl;
            ui_rec = temp_ui_2 + ui_rec;
            // receive from party 3
            tel.receive(&temp_ui_3, 3);
            // std::cout<<"temp_ui_2 sended" << std::endl;
            ui_rec = temp_ui_3 + ui_rec;

            // receive from party 2
            tel.receive(&temp_ui_2, 2);
            // std::cout<<"temp_ui_1 sended" << std::endl ;
            ui_rec_pr = temp_ui_2 + ui_rec_pr;
            // receive from party 3
            tel.receive(&temp_ui_3, 3);
            // std::cout<<"temp_ui_2 sended" << std::endl;
            ui_rec_pr = temp_ui_3 + ui_rec_pr;

            // vi_0 and vi_1
            for (int i = 0; i < D; i++)
            {
                vi_rec(i, 0) = vi_share(0, i, 0);
                vi_rec_pr(i, 0) = vi_share(1, i, 0);
            }
            // std::cout<<"vi_rec generated" << std::endl;
            // std::cout<<"vi_rec_pr generated" << std::endl;

            // receive from party 2
            tel.receive(&temp_vi_2, 2);
            // std::cout<<"temp_vi_1 received" << std::endl;
            vi_rec = temp_vi_2 + vi_rec;
            // receive from party 3
            tel.receive(&temp_vi_3, 3);
            // std::cout<<"temp_vi_2 received" << std::endl;
            vi_rec = temp_vi_3 + vi_rec;

            // receive from party 2
            tel.receive(&temp_vi_2, 2);
            // std::cout<<"temp_vi_2 received" << std::endl;
            vi_rec_pr = temp_vi_2 + vi_rec_pr;

            // receive from party 3
            tel.receive(&temp_vi_3, 3);
            // std::cout << "temp_vi_3 received" << std::endl;
            vi_rec_pr = temp_vi_3 + vi_rec_pr;

            for (int i = 0; i < B; i++)
            {
                hi_0(i, 0) += Secret_Mul::Generate_triplets_Alice_improve(ui_0, D, 2, i, true, true);
                hi_0(i, 0) += Secret_Mul::Generate_triplets_Alice_improve(ui_0, D, 3, i, true, true);
                hi_0(i, 0) += Secret_Mul::Generate_triplets_Alice_improve(vi_0, D, 2, i, false, true);
                hi_0(i, 0) += Secret_Mul::Generate_triplets_Alice_improve(vi_0, D, 3, i, false, true);
            }
            // std::cout << "hi_0 is" << hi_0 << std::endl;
            // get hi
            for (int i = 0; i < B; i++)
            {
                hi(0, i, 0) = hi_0(i, 0);
            }
            Eigen::array<Eigen::IndexPair<int>, 1> product_dims2 = {Eigen::IndexPair<int>(1, 0)};
            hi_share = Mat::A_plus.contract(hi, product_dims2);
            for (int i = 0; i < B; i++)
            {
                hi_rec(i, 0) = hi_share(0, i, 0);
                temp_hi_2(i, 0) = hi_share(2, i, 0);
                temp_hi_3(i, 0) = hi_share(3, i, 0);
                hi_rec_pr(i, 0) = hi_share(1, i, 0);
            }
            tel.send(&temp_hi_2, 2);
            tel.send(&temp_hi_2, 3);

            tel.receive(&temp_hi_2, 2);
            hi_rec = temp_hi_2 + hi_rec;
            tel.receive(&temp_hi_3, 3);
            hi_rec = temp_hi_3 + hi_rec;
            tel.receive(&temp_hi_2, 2);
            hi_rec_pr = temp_hi_2 + hi_rec_pr;
            tel.receive(&temp_hi_3, 3);
            hi_rec_pr = temp_hi_3 + hi_rec_pr;

            // write to file
            ofstream F0;
            ofstream F1;
            ofstream F2;
            ofstream F3;
            F0.open("share_0.txt");
            F1.open("share_1.txt");
            for (int i = 0; i < B; i++)
            {

                for (int j = 0; j < D; j++)
                {
                    F0 << ui_rec(i, j) << ',';
                    F1 << ui_rec_pr(i, j) << ',';
                }
                F0 << std::endl;
                F1 << std::endl;
            }
            for (int i = 0; i < D; i++)
            {
                F0 << vi_rec(i, 0) << ',';
                F1 << vi_rec_pr(i, 0) << ',';
            }
            F0 << std::endl;
            F1 << std::endl;
            for (int i = 0; i < B; i++)
            {
                F0 << hi_rec(i, 0) << ',';
                F1 << hi_rec_pr(i, 0) << ',';
            }
            F0 << std::endl;
            F1 << std::endl;
            F0.close();
            F1.close();
        }
        else if (party == 2)
        {
            // receive_part

            // original share
            for (int i = 0; i < B; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    ui_rec(i, j) = ui_share(2, i, j);
                }
            }
            // receive from party 2
            tel.receive(&temp_ui_3, 3);
            // std::cout<<"temp_ui_2 received" << std::endl;
            ui_rec = temp_ui_3 + ui_rec;

            // vi_0
            for (int i = 0; i < D; i++)
            {
                vi_rec(i, 0) = vi_share(2, i, 0);
            }

            // receive from party 2
            tel.receive(&temp_vi_3, 3);
            // std::cout<<"temp_vi_2 received" << std::endl;
            vi_rec = temp_vi_3 + vi_rec;

            // send part
            // for ui
            for (int i = 0; i < B; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    temp_ui_0(i, j) = ui_share(0, i, j);
                    temp_ui_1(i, j) = ui_share(1, i, j);
                    // reuse this space, where ui_rec_pr act like temp_ui_2
                    temp_ui_3(i, j) = ui_share(3, i, j);
                }
            }
            // send the share to party 0
            tel.send(&temp_ui_0, 0);
            // std::cout<<"temp_ui_0 sended" << std::endl;
            tel.send(&temp_ui_1, 0);
            // std::cout<<"temp_ui_3 sended" << std::endl;
            // send the share to party 2
            tel.send(&temp_ui_3, 3);
            // std::cout<<"temp_ui_2 sended" << std::endl;

            // for vi

            for (int i = 0; i < D; i++)
            {
                temp_vi_0(i, 0) = vi_share(0, i, 0);
                temp_vi_1(i, 0) = vi_share(1, i, 0);
                temp_vi_3(i, 0) = vi_share(3, i, 0);
            }
            tel.send(&temp_vi_0, 0);
            // std::cout<<"temp_vi_0 sended" << std::endl;
            tel.send(&temp_vi_1, 0);
            // std::cout<<"temp_vi_3 sended" << std::endl;
            tel.send(&temp_vi_3, 3);
            // std::cout<<"temp_vi_2 sended" << std::endl;

            // write to file
            // receive from party 0
            tel.receive(&temp_ui_0, 0);
            // std::cout<<"temp_ui_0 received" << std::endl;
            ui_rec = temp_ui_0 + ui_rec;
            // receive from party 0
            tel.receive(&temp_vi_0, 0);
            // std::cout<<"temp_vi_0 received" << std::endl;
            vi_rec = temp_vi_0 + vi_rec;

            for (int i = 0; i < B; i++)
            {
                hi_0(i, 0) += Secret_Mul::Generate_triplets_Bob_improve(vi_0, D, 0, i, false, false);
                hi_0(i, 0) += Secret_Mul::Generate_triplets_Bob_improve(ui_0, D, 0, i, true, false);
                hi_0(i, 0) += Secret_Mul::Generate_triplets_Bob_improve(vi_0, D, 3, i, false, false);
                hi_0(i, 0) += Secret_Mul::Generate_triplets_Bob_improve(ui_0, D, 3, i, true, false);
            }
            // std::cout << hi_0 << std::endl;
            // get hi
            for (int i = 0; i < B; i++)
            {
                hi(0, i, 0) = hi_0(i, 0);
            }

            Eigen::array<Eigen::IndexPair<int>, 1> product_dims2 = {Eigen::IndexPair<int>(1, 0)};
            hi_share = Mat::A_plus.contract(hi, product_dims2);

            for (int i = 0; i < B; i++)
            {
                temp_hi_0(i, 0) = hi_share(0, i, 0);
                hi_rec(i, 0) = hi_share(2, i, 0);
                temp_hi_3(i, 0) = hi_share(3, i, 0);
                temp_hi_1(i, 0) = hi_share(1, i, 0);
            }

            tel.send(&temp_hi_0, 0);
            tel.send(&temp_hi_1, 0);
            tel.send(&temp_hi_3, 3);

            tel.receive(&temp_hi_0, 0);
            hi_rec = temp_hi_0 + hi_rec;
            tel.receive(&temp_hi_3, 3);
            hi_rec = temp_hi_3 + hi_rec;

            ofstream F0;
            ofstream F1;
            F0.open("share_2.txt");
            for (int i = 0; i < B; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    F0 << ui_rec(i, j) << ',';
                }
                F0 << std::endl;
            }
            for (int i = 0; i < D; i++)
            {
                F0 << vi_rec(i, 0) << ',';
            }
            F0 << std::endl;
            for (int i = 0; i < B; i++)
            {
                F0 << hi_rec(i, 0) << ',';
            }
            F0 << std::endl;
            F0.close();
        }
        else if (party==3)
        {
            // send part
            // for ui
            for (int i = 0; i < B; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    temp_ui_0(i, j) = ui_share(0, i, j);
                    temp_ui_1(i, j) = ui_share(1, i, j);
                    temp_ui_2(i, j) = ui_share(2, i, j);
                }
            }
            // send the share to party 0
            tel.send(&temp_ui_0, 0);
            // std::cout<<"temp_ui_0 sended" << std::endl;
            tel.send(&temp_ui_1, 0);
            // std::cout<<"temp_ui_3 sended" << std::endl;
            // send the share to party 1
            tel.send(&temp_ui_2, 2);
            // std::cout<<"temp_ui_1 sended" << std::endl;

            // for vi

            for (int i = 0; i < D; i++)
            {
                temp_vi_0(i, 0) = vi_share(0, i, 0);
                temp_vi_1(i, 0) = vi_share(1, i, 0);
                temp_vi_2(i, 0) = vi_share(2, i, 0);
            }
            tel.send(&temp_vi_0, 0);
            // std::cout<<"temp_vi_0 sended" << std::endl;
            tel.send(&temp_vi_1, 0);
            // std::cout<<"temp_vi_3 sended" << std::endl;
            tel.send(&temp_vi_2, 2);
            // std::cout<<"temp_vi_1 sended" << std::endl;

            // receive_part
            // original share
            for (int i = 0; i < B; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    ui_rec(i, j) = ui_share(3, i, j);
                }
            }

            // receive from party 0
            tel.receive(&temp_ui_0, 0);
            // std::cout<<"temp_ui_0 received" << std::endl;
            ui_rec = temp_ui_0 + ui_rec;
            // receive from party 1
            //  std::cout<<"temp_ui_1 received" << std::endl;
            tel.receive(&temp_ui_2, 2);
            ui_rec = temp_ui_2 + ui_rec;

            // vi_0
            for (int i = 0; i < D; i++)
            {
                vi_rec(i, 0) = vi_share(3, i, 0);
            }

            // receive from party 0
            tel.receive(&temp_vi_0, 0);
            // std::cout<<"temp_vi_0 received" << std::endl;
            vi_rec = temp_vi_0 + vi_rec;
            // receive from party 1
            tel.receive(&temp_vi_2, 2);
            // std::cout<<"temp_vi_1 received" << std::endl;
            vi_rec = temp_vi_2 + vi_rec;
            for (int i = 0; i < B; i++)
            {
                hi_0(i, 0) += Secret_Mul::Generate_triplets_Bob_improve(vi_0, D, 0, i, false, false);
                hi_0(i, 0) += Secret_Mul::Generate_triplets_Bob_improve(ui_0, D, 0, i, true, false);
                hi_0(i, 0) += Secret_Mul::Generate_triplets_Alice_improve(ui_0, D, 2, i, true, true);
                hi_0(i, 0) += Secret_Mul::Generate_triplets_Alice_improve(vi_0, D, 2, i, false, true);
            }
            // std::cout << hi_0 << std::endl;
            // get hi
            for (int i = 0; i < B; i++)
            {
                hi(0, i, 0) = hi_0(i, 0);
            }
            Eigen::array<Eigen::IndexPair<int>, 1> product_dims2 = {Eigen::IndexPair<int>(1, 0)};
            hi_share = Mat::A_plus.contract(hi, product_dims2);

            for (int i = 0; i < B; i++)
            {
                temp_hi_0(i, 0) = hi_share(0, i, 0);
                temp_hi_2(i, 0) = hi_share(2, i, 0);
                hi_rec(i, 0) = hi_share(3, i, 0);
                temp_hi_1(i, 0) = hi_share(1, i, 0);
            }

            tel.send(&temp_hi_0, 0);
            tel.send(&temp_hi_1, 0);

            tel.receive(&temp_hi_0, 0);
            hi_rec = temp_hi_0 + hi_rec;
            tel.receive(&temp_hi_2, 2);
            hi_rec = temp_hi_2 + hi_rec;

            tel.send(&temp_hi_2, 2);

            // write to file
            ofstream F0;
            F0.open("share_3.txt");
            for (int i = 0; i < B; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    F0 << ui_rec(i, j) << ',';
                }
                F0 << std::endl;
            }
            for (int i = 0; i < D; i++)
            {
                F0 << vi_rec(i, 0) << ',';
            }
            F0 << std::endl;
            for (int i = 0; i < B; i++)
            {
                F0 << hi_rec(i, 0) << ',';
            }
            F0 << std::endl;
            F0.close();
        }
    }
    cout << "offline time:" << offline->get() << endl;
}
