/*
* prices.cpp is a program that computes a total price from a
* series of user inputs. It does this by declaring two empty
* doubles (to account for decimal values). It then uses a
* while loop to continously prompt the user for prices, then
* uses an if statement to immedeatly break out of the loop.
* It then returns the total.
*/

#include <string>
#include <iostream>

using namespace std;

int main() {
  double price = 0.0;
  double total = 0.0;

  cout << "Enter prices: " << endl;
  while (price >= 0.0) {
    cin >> price;
    if (price < 0.0) {  // immedeatly terminate
      break;
    }
    total += price;
  }
  cout << "Total: $" << total << endl;
  return 0;
}
