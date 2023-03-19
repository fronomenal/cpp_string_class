#include "String.h"

int main()
{

    String nuString{"mii"};
    String null{nullptr};
    String newString{nuString};
    String two;
    two = "tuu";
    int num{3};

    String sum{newString+null};
    String wait;

    std::cout.setf(std::ios::boolalpha);
    std::cout<< "_____________ Starts Here _______________"<< std::endl;
    std::cout<< "String initialized with 'mii': "<< nuString<< std::endl;
    std::cout<< "'mii' String + nullptr initialized string: "<< (newString += null)<< std::endl;
    std::cout<< "'mii' String + c-string 'tuu' : "<< nuString + "tuu"<< std::endl;
    std::cout<< "'tuu' String * 3: "<< (two*=num)<< std::endl;
    std::cout<< "Compare c-string initialized 'tuu' to copy constructed String 'tuu': "<< (newString==nuString)<< std::endl;
    std::cout<< "Swap lower cases with upper cases in 'mii'(operator++): "<< ++nuString<< std::endl;
    std::cout<< "length of nullptr initialized String: "<< null.getLength()<< "\nEnter a String consisting of upper cases less than 300 characters. No spaces allowed\n>";
    std::cin>> null;
    std::cout<< --null << std::endl;
    std::cin >> wait;

    return 0;
}
