# pMPL


## Introduction
pMPL is a three-party learning framework based on vector space secret sharing with the privileged setting where a party can be set as the privileged party before machine learning. Without the participation of it, assist parties have no chance to reveal the secret value even if they collude. Meanwhile, pMPL can tolerate either of assist parties dropping out during training.  pMPL supports linear regression, logistic regression and neural networks.

## Repository Structure
* '3PC/': The training process if no party drops out.

* '2PC/': The training process if one assist party drops out.


## Running for 3pc
### Network Configuration

> In the default configuration, multiple processes run on a server, which is a **LAN** environment.
>
> In order to simulate **WAN** environment,  we can use the following command.

```shell
# simulate WAN
sudo tc qdisc add dev lo root netem delay 20ms rate 40Mbps
# cancle the simulation
sudo tc qdisc del dev lo root netem delay 20ms rate 40Mbps
```

pMPL/3pc/util/SocketManager.cpp line 138

```c++
void SocketManager::pMPL::init()
{
    // init("127.0.0.1", 1234);
    string ip[M] = {"127.0.0.1", "127.0.0.1", "127.0.0.1", "127.0.0.1"}; 
    int port[M] = {12000, 12001, 12002, 12003}; 
    init(ip, port);
}
```

### Compile

**Constant.h**

```c++
#define M 4
#define ML 0
```

* M: the 4 shares (3 parties)
* ML: machine learning models, 0 for linear regression; 1 for logistic regression; 2 for neural networks


Compile the executable file

```shell
cd pMPL/3pc
cmake .
make -j
```

### Run

Start four processes and input the party index, respectively:

```shell
./pmpl_3pc 0
```

```shell
./pmpl_3pc 1
```

```shell
./pmpl_3pc 2
```

```shell
./pmpl_3pc 3
```

Note that, the raw dataset need to be secreted share before training.
(pMPL/3pc/util/IOManager.cpp line 177)
```c++
ifstream infile("data/mnist_train.csv");
load_data(infile, train_data, train_label, N);
secret_share(train_data, train_label, "train");

// ifstream infile("data/mnist_train_" + to_string(party) + ".csv");
// load_ss(infile, train_data, train_label, N);
infile.close();
```

After secret sharing the raw data, load the secreted share data and then preform training.
(pMPL/3pc/util/IOManager.cpp line 177)
```c++
// ifstream infile("data/mnist_train.csv");
// load_data(infile, train_data, train_label, N);
// secret_share(train_data, train_label, "train");

ifstream infile("data/mnist_train_" + to_string(party) + ".csv");
load_ss(infile, train_data, train_label, N);
infile.close();
```

If one assist party drops out during the training phase, the intermediate results hold by each party will be stored in "pMPL/3pc/Result", which can be used as initialization coefficients for 2PC training.

## Running for 2pc
### Network Configuration

pMPL/2pc/util/SocketManager.cpp line 138

```c++
void SocketManager::pMPL::init()
{
    // init("127.0.0.1", 1234);
    string ip[M] = {"127.0.0.1", "127.0.0.1", "127.0.0.1"};
    int port[M] = {12011, 12012, 12013};
    init(ip, port);
}
```

### Compile

**Constant.h**

```c++
#define M 3
#define ML 0
```

* M: the 3 shares (2 parties)
* ML: machine learning models, 0 for linear regression; 1 for logistic regression; 2 for neural networks


Compile the executable file

```shell
cd pMPL/2pc
cmake .
make -j
```

### Run

Start three processes and input the party index, respectively:

```shell
./pmpl_2pc 0
```

```shell
./pmpl_2pc 1
```

```shell
./pmpl_2pc 2
```


## Citation
You can cite the paper using the following bibtex entry:



## Help

Any question, please contact 19110240022@fudan.edu.cn.
