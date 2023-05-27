# Simple ATM controller

This repository is only for the instrucution how to clone this project, build and run tests. I implemented a simple ATM controller using console UI. The user database is stored as text file `/data/account_list.txt`. Any questions are welcome, I attached my contact to the end of this file. Plus I wrote a demo for running this code.

<br/>

## Test Environment

* `cmake` : more than `3.0.2`
* `gcc, g++` :  more than `9`
* Ubuntu 20.04, Standard C++17

<br/>

## How to clone, build and run this project

### 1) Clone this repository on your local PC

~~~bash
git clone https://github.com/bigbigpark/ATMController.git
~~~
<br/>

### 2) Build the project

~~~bash
cd ATMController
mkdir build && cd build
cmake ../
make
~~~

<br/>

### 3) Run the code

~~~bash
./main
~~~

<br/>

## Project Description

Instead of the process that inserts the card and presses the PIN number, I used `std::cin` from the user on console. Users can input the identification number of card and its password after the program starts. If they are correct information, the customer do following three tasks using our ATM controller.

* Check the balance
* Deposit the cash into the account
* Withdraw the money from it

I considered every wrong input command such as any punctuation and mathmatical marks, blank, negative number etc.


<br/>

Like a real bank system I managed all customer's account as a format of txt file. You can check all data at [account_list.txt](/data/account_list.txt). Each row means every other account seperated by delimiter `,` meaning **card_id**, **password** and **the balance**.

<br/>

## Demo

It is most important to keep confidential personal information in a real bank system but to ease the implementation I used text file-based user database which can be found [here](/data/account_list.txt) same as below picture.

![](/fig/database.png)

I'll use the first row of it for this demo. <br/>
* card id : 12345678
* password : 1111
* balance : 3050

<br/>

Begin the demo with `./main`. <br/>
Input the card information (id + password).

![](/fig/1.png)

<br/>

If both are correct, the user can continue the steps.

![](/fig/2.png)

<br/>

From this process, the user can access own bank accout. The three main function is avaliable. 1) Check the balance, 2) Deposit and 3) Withdraw. Also, User can terminate the ATM controller with doing nothing.

![](/fig/3.png)

<br/>

As you already know, the user has $3,050. <br/>

![](/fig/4.png)

<br/>

You can push the money into your account. <br/>
The total balance is $8,050 now. <br/>

![](/fig/5.png)

<br/>

Also, you can pull out the money from it. <br/>
The total balance is $6,816. <br/>

![](/fig/6.png)

<br/>

Whenever you type `no` or `0` to terminate a ATM controller with corressponding terminal, the program ends with closing ments.

![](/fig/7.png)

<br/>

The last balance after several accessing the account is $6,816. Our ATM service automatically saves the changes and manages it as a format of text file.

![](/fig/8.png)


<br/>

## Contact

Author: SeongChang Park <br/>
Email: scsc1125@gmail.com