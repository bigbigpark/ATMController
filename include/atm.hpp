/**
 * @file atm.hpp
 * @author SeongChang Park (scsc1125@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-27 15:08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "types.hpp"

namespace bear_robotics
{
class ATMController
{
public:
  ATMController(int state);
  ~ATMController();

  void run();

private:
  int atm_state_;
  int access_state_;

  std::fstream data_file_;
  std::string file_path_;
  std::vector<PersonalAccount> account_list_;
  PersonalAccount user_account_;
  int user_index_;

  void atmBegin();
  void atmInputCardAndPIN();
  void atmSelectAccount();
  void atmAccessAccount();
  void atmDone();

  void accessBalance();
  void accessDeposit();
  void accessWithdraw();
};

};