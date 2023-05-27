/**
 * @file main.cpp
 * @author SeongChang Park (scsc1125@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-27 15:06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "atm.hpp"

int main(int argc, char** argv)
{
  int atm_state = ATM_BEGIN;
  
  bear_robotics::ATMController atm_controller(atm_state);
  atm_controller.run();

  return 0;
}