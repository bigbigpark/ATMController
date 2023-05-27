/**
 * @file atm.cpp
 * @author SeongChang Park (scsc1125@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-27 15:08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "atm.hpp"

namespace bear_robotics
{
ATMController::ATMController(int state) : atm_state_(state)
{
  access_state_ = ACCESS_BALANCE;
}

ATMController::~ATMController()
{
}

void ATMController::atmDone()
{
  std::system("clear");
  std::cout << "[Info] Thank you for using our ATM service! :)" << std::endl;
  data_file_.open(file_path_, std::ios::out);

  for(const auto& account: account_list_)
  {
    data_file_ << account.id << "," << account.password << "," << account.balance << "\n";
  }

  data_file_.close();

  atm_state_ = ATM_TERMINATE;
}

void ATMController::accessWithdraw()
{
  std::system("clear");
  std::cout << "[Info] withdraw the cash from your account" << std::endl;
  std::cout << "  total amount: ";
  std::string total_amount;
  std::getline(std::cin, total_amount);

  for(auto& ch : total_amount)
  {
    int num = ch - '0';
    if (num < 0 || num > 9)
    {
      std::cout << "[Error] wrong input" << std::endl;
      sleep(3);
      return;
    }
  }
  if (total_amount.size() > 7)
  {
    std::cout << "[Error] You can withdraw less than $10,000,000 at once" << std::endl;
    sleep(3);
    return;
  }

  auto amount = std::stoi(total_amount);
  if (amount < 0 || amount > std::stoi(user_account_.balance))
  {
    std::cout << "[Error] after withdraw, the remain is negative number" << std::endl;
    sleep(3);
    return;
  }

  std::cout << "  (before) balance: " << user_account_.balance << std::endl;
  user_account_.balance = std::to_string(std::stoi(user_account_.balance) - amount);
  std::cout << "  (after)  balance: " << user_account_.balance << std::endl;

  account_list_[user_index_].balance = user_account_.balance;

  std::cout << "\nIf you want to do another work or not?" << std::endl;
  std::cout << "Type 'yes' or 'no': ";

  std::string choice;
  std::getline(std::cin, choice);
  if (choice == "yes") atm_state_ = ATM_ACCESS_ACCOUNT;
  else if (choice == "no") access_state_ = ACCESS_DONE;
  else
  {
    std::cout << "[Error] wrong command input! Going back to menu" << std::endl;
    sleep(2);
    return;
  }
}

void ATMController::accessDeposit()
{
  std::system("clear");
  std::cout << "[Info] Put the cash into your account" << std::endl;
  std::cout << "  total amount: ";
  std::string total_amount;
  std::getline(std::cin, total_amount);

  for(auto& ch : total_amount)
  {
    int num = ch - '0';
    if (num < 0 || num > 9)
    {
      std::cout << "[Error] wrong input" << std::endl;
      sleep(3);
      return;
    }
  }
  if (total_amount.size() > 7)
  {
    std::cout << "[Error] You can deposit less than $10,000,000 at once" << std::endl;
    sleep(3);
    return;
  }

  auto amount = std::stoi(total_amount);
  if (amount < 0)
  {
    std::cout << "[Error] total amount is less than 0, please insert positive number" << std::endl;
    sleep(3);
    return;
  }

  std::cout << "  (before) balance: " << user_account_.balance << std::endl;
  user_account_.balance = std::to_string(std::stoi(user_account_.balance) + amount);
  std::cout << "  (after)  balance: " << user_account_.balance << std::endl;

  account_list_[user_index_].balance = user_account_.balance;

  std::cout << "\nIf you want to do another work or not?" << std::endl;
  std::cout << "Type 'yes' or 'no': ";

  std::string choice;
  std::getline(std::cin, choice);
  if (choice == "yes") atm_state_ = ATM_ACCESS_ACCOUNT;
  else if (choice == "no") access_state_ = ACCESS_DONE;
  else
  {
    std::cout << "[Error] wrong command input! Going back to menu" << std::endl;
    sleep(2);
    return;
  }
}

void ATMController::accessBalance()
{
  std::system("clear");
  std::cout << "[Info] Print your balance" << std::endl;
  std::cout << "  ID     : " << user_account_.id << std::endl;
  std::cout << "  Balance: " << user_account_.balance << " [USD]" << std::endl;

  std::cout << "\nIf you want to do another work or not?" << std::endl;
  std::cout << "Type 'yes' or 'no': ";

  std::string choice;
  std::getline(std::cin, choice);
  if (choice == "yes") atm_state_ = ATM_ACCESS_ACCOUNT;
  else if (choice == "no") access_state_ = ACCESS_DONE;
  else
  {
    std::cout << "[Error] wrong command input! Going back to menu" << std::endl;
    sleep(2);
    return;
  }
}

void ATMController::atmAccessAccount()
{
  while (access_state_ != ACCESS_DONE)
  {
    std::system("clear");
    std::cout << "[Info] Access your account, select the menu" << std::endl;
    std::cout << "Type '1': check the balance" << std::endl;
    std::cout << "Type '2': deposit into the account" << std::endl;
    std::cout << "Type '3': withdraw cash from the account" << std::endl;
    std::cout << "Type '0': terminate ATM system" << std::endl;
    std::cout << "input: ";

    std::string choice;
    std::getline(std::cin, choice);

    if (choice == "1") access_state_ = ACCESS_BALANCE;
    else if (choice == "2") access_state_ = ACCESS_DEPOSIT;
    else if (choice == "3") access_state_ = ACCESS_WITHDRAW;
    else if (choice == "0") access_state_ = ACCESS_DONE;
    else
    {
      std::cout << "[Error] wrong command input! going back to account access" << std::endl;
      sleep(2);
      return;
    }

    switch (access_state_)
    {
    case ACCESS_BALANCE:
      accessBalance();
      break;

    case ACCESS_DEPOSIT:
      accessDeposit();
      break;
    
    case ACCESS_WITHDRAW:
      accessWithdraw();
      break;

    default:
      break;
    }
    sleep(0.01);
  }
  atm_state_ = ATM_DONE;
}

void ATMController::atmSelectAccount()
{
  std::system("clear");
  std::cout << "[Info] We found your account !" << std::endl;
  std::cout << "\nIf you want to continue using our ATM service?" << std::endl;
  std::cout << "Type 'yes' or 'no': ";
  std::string choice;
  std::getline(std::cin, choice);
  if (choice == "yes") atm_state_ = ATM_ACCESS_ACCOUNT;
  else if (choice == "no") atm_state_ = ATM_DONE;
  else
  {
    std::cout << "[Error] wrong command input!" << std::endl;
    sleep(2);
    return;
  }
}

void ATMController::atmInputCardAndPIN()
{
  std::system("clear");

  std::cout << "[Info] Welcome to ATM Controller" << std::endl;
  std::string id, password;

  std::cout << "Type your card id [8 digits]: ";
  std::getline(std::cin, id);

  std::cout << "Type your PIN number [4 digits]: ";
  std::getline(std::cin, password);

  if (id.size() != 8 || password.size() != 4)
  {
    std::cout << "[Error] wrong input" << std::endl;
    sleep(3);
    return;
  }
  for(auto& ch : id)
  {
    int num = ch - '0';
    if (num < 0 || num > 9)
    {
      std::cout << "[Error] wrong input" << std::endl;
      sleep(3);
      return;
    }
  }

  bool is_valid = false;
  int idx = 0;
  for(const auto& acc: account_list_)
  {
    if (id == acc.id && password == acc.password)
    {
      is_valid = true;
      user_account_.id = acc.id;
      user_account_.password = acc.password;
      user_account_.balance = acc.balance;

      user_index_ = idx;
    }
    idx++;
  }

  if (is_valid) atm_state_ = ATM_SELECT_ACCOUNT;
  else
  {
    std::system("clear");
    std::cout << "[Error] Card ID or PIN number is incorrect !" << std::endl;
    std::cout << "\nIf you want to continue using our ATM service?" << std::endl;
    std::cout << "Type 'yes' or 'no': ";

    std::string choice;
    std::getline(std::cin, choice);
    if (choice == "yes") atm_state_ = ATM_INPUT_CARD_AND_PIN;
    else if (choice == "no") atm_state_ = ATM_DONE;
    else
    {
      std::cout << "[Error] wrong command input! Going back to home" << std::endl;
      sleep(2);
      return;
    }
  }
}

void ATMController::atmBegin()
{
  // Read customer data
  file_path_ = fs::current_path() / "../data/account_list.txt";
  data_file_.open(file_path_, std::ios::in);
  if (!data_file_.is_open())
  {
    std::system("clear");
    std::cout << "[Fatal] Cannot find user database 'account_list.txt' :(" << std::endl;
    atm_state_ = ATM_DONE;
    return;
  }

  while (!data_file_.eof())
  {
    std::string line;
    std::getline(data_file_, line);

    if (line.size() > 0)
    {
      std::istringstream ss(line);
      std::string word;
      PersonalAccount pa;
      int count = 0;
      while (std::getline(ss, word, ','))
      {
        if (count == 0) pa.id = word;
        else if (count == 1) pa.password = word;
        else pa.balance = word;
        count++;
      }
      account_list_.push_back(pa);
    }
  }
  data_file_.close();

  atm_state_ = ATM_INPUT_CARD_AND_PIN;
}

void ATMController::run()
{
  while (atm_state_ != ATM_TERMINATE)
  {
    switch (atm_state_)
    {
    case ATM_BEGIN:
      atmBegin();
      break;

    case ATM_INPUT_CARD_AND_PIN:
      atmInputCardAndPIN();
      break;

    case ATM_SELECT_ACCOUNT:
      atmSelectAccount();
      break;

    case ATM_ACCESS_ACCOUNT:
      atmAccessAccount();
      break;

    case ATM_DONE:
      atmDone();
      break;
    
    default:
      break;
    }
    sleep(0.01);
  }
}
};