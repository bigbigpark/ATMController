# Simple ATM controller

This repository is only for the instrucution how to clone this project, build and run tests. I implemented a simple ATM controller using console UI. The user database is stored as text file `/data/account_list.txt`. Any questions are welcome, I attached my contact to the end of this file.

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

Instead of the process that inserts the card and presses the PIN number, I used `std::cin` from the user on console. Like a real bank system I managed all customer's account as a format of txt file. You can check all data at [account_list.txt]("/data/account_list.txt")

<br/>

## Contact

Author: SeongChang Park <br/>
Email: scsc1125@gmail.com