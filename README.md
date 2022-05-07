# pMPL


## Introduction
pMPL is a three-party learning framework based on vector space secret sharing with the privileged setting where a party can be set as the privileged party before machine learning. Without the participation of it, assist parties have no chance to reveal the secret value even if they collude. Meanwhile, pMPL can tolerate either of assist parties dropping out during training.  pMPL supports linear regression, logistic regression and neural networks.

## Repository Structure
* '3PC/': The training process if no party drops out.

* '2PC/': The training process if one assist party drops out.


## Running for 3pc
### Network Configuration

pMPL/3pc/util/SocketManager.cpp line138

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



## Running for 2pc
### Network Configuration

pMPL/2pc/util/SocketManager.cpp line138

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





## Help

Any question, please contact 19110240022@fudan.edu.cn.
