
#include "Wk_ch3.hpp"
using namespace std;

int main (){
    safeArray list(4, 8);
    list.set(4,5);
    list.set(5,6);
    list.set(6,8);
    list.set(7,101);
    list.print();
    list.set(-9, 55);
    list.print();
	return 0;
}
