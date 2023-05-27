/**
 * @file types.hpp
 * @author SeongChang Park (scsc1125@gmail.com)
 * @version 0.1
 * @date 2023-05-27 15:10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unistd.h>
#include <cstdlib>

#define   END    "\033[0m"
#define   RED    "\033[1;31m"
#define   GREEN  "\033[1;32m"
#define   BLUE   "\033[1;34m"
#define   CLEAR  "\033[2J\033[1;1H"

namespace fs = std::filesystem;

enum ATMState
{
  ATM_BEGIN,
  ATM_INPUT_CARD_AND_PIN,
  ATM_SELECT_ACCOUNT,
  ATM_ACCESS_ACCOUNT,
  ATM_DONE,
  ATM_TERMINATE
};

enum AccessState
{
  ACCESS_BALANCE,
  ACCESS_DEPOSIT,
  ACCESS_WITHDRAW,
  ACCESS_DONE
};

struct PersonalAccount
{
  std::string id = "";
  std::string password = "";
  std::string balance = "";
};