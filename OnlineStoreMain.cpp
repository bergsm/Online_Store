/********************************************************************* 
** Author: Shawn Berg
** Date: 6/8/17
** Description:
*********************************************************************/

#include <iostream>
#include "Store.hpp"

using namespace std;

int main()
{

    Store MainStore;



    Product GiantRobot("123", "Giant Robot", "A Giant Robot for all your Giant "
            "Robot needs", 1700.00, 3);
    Product RedCorvette("456", "Red Corvette", "A Red Corvette for all your Red"
            " Corvette needs", 19000.00, 2);
    Product Popcorn("23", "Popcorn", "buttered popcorn", 4.99, 25);
    Product Beer("001", "Beer", "12 pack of beer", 11.99, 30);



    Customer Frank("Frank", "123", true);
    Customer Shawn("Shawn", "728", false);
    Customer Michele("Michele", "1031", false);


    MainStore.addProduct(&GiantRobot);
    MainStore.addProduct(&RedCorvette);
    MainStore.addProduct(&Popcorn);
    MainStore.addProduct(&Beer);
    //Product* Test = MainStore.getProductFromID("23");

    MainStore.addMember(&Frank);
    MainStore.addMember(&Shawn);
    MainStore.addMember(&Michele);

    MainStore.addProductToMemberCart("001", "728");
    MainStore.addProductToMemberCart("123", "728");
    MainStore.addProductToMemberCart("23", "1031");
    MainStore.addProductToMemberCart("456", "1031");
    MainStore.addProductToMemberCart("456", "123");

    /*vector<std::string> testCart = Shawn.getCart();

    cout << testCart.size() << endl;

    Product* Test2 = MainStore.getProductFromID(testCart[0]);

    cout << Test2->getTitle() << endl;*/


    //MainStore.addProductToMemberCart("456", "728");

    //MainStore.productSearch("corvette");

    //cout << Test->getTitle() << endl << endl;





    MainStore.checkOutMember("728");
    MainStore.checkOutMember("1031");


    MainStore.checkOutMember("123");
    MainStore.checkOutMember("125");

    return 0;
}
