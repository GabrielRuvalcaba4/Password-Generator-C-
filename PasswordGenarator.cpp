/*
Gabriel Ruvalcaba
This program generates a random password to the length inputed by the users
I put a limit because most sites do not accept anything past 64 charcaters
and to stop a user form entering a extensively long password and crashing the program.
 */

#include <ctime>
#include <iostream>
#include <cstdlib>

int main()
{
  //variable for password length
  int length = 0;

  //String to store the password
  std::string password;

  //Const string contaning character pool
  const std::string possible_characters = "abcdefghijklmopqrstuvwxyz12345678901234567890!@#$%^&*?_-!@#$%^&*?_-ABCDEFGHIJKLMOPQRSTUVWXYZ";

  //print program header
  std::cout << "-------Welcome to the Random Password Generator--------\n" << std::endl;

  //promt user for desired password length
  do {
    std::cout << "How many characters should the password be? ";

    // read users inut into variable length
    std::cin >> length;

    // Check if input failed if user did not enter an integer
    if (std::cin.fail())
      {
      std::cout << "ERROR: password length must be a number.\n" << std::endl;

      // Clear the error state
      std::cin.clear();

      // Ignore the invalid input left in the buffer
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      // set length to invalid to continue loop
      length = -1;
      continue;
    }

    // Check if number is positive
    if (length <= 0) {
      std::cout << "ERROR: password length must be positive.\n" << std::endl;
    }

    // Check if number is too long
    if (length > 65) {
      std::cout << "ERROR: password is too long for most sites.\n" << std::endl;
    }

  } while (length <= 0 || length > 65);
  // loop until valid input


  // Seed random number generator once
  srand(time(NULL));


  // Generate the password
  for (int i = 0; i < length; i++)
  {
    int ran = rand() % possible_characters.size(); // pick random index
    char character = possible_characters[ran];
    password += character;
  }

  // Display the generated password
  std::cout << "\nRandom password: " << password << std::endl;

  return 0;
}
