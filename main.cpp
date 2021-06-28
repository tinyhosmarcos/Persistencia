#include "List.h"
#include "Node.h"
using namespace std;
void test(vector<int> &vec_test){
    vector<int> holi;
    holi=vec_test;
    cout<<vec_test[0];

}
int main(){
    vector<int> values; values.push_back(4);values.push_back(5);values.push_back(1231235);values.push_back(512323);
    vector<int> values2; values2.push_back(12);values2.push_back(768);values2.push_back(6879);values2.push_back(576);
    vector<int> values3; values3.push_back(65534);values3.push_back(431);values.push_back(476);values3.push_back(6789);
    vector<int> values4; values4.push_back(6776);values4.push_back(4536);values4.push_back(345);values4.push_back(8790);
    List<int> test;
    test.addNode(values);
    test.addNode(values2);
    test.addNode(values3);
    test.insert(2,1,99999);
    test.addNode(values4);
    test.insert(2,1,222222222);
    test.printList();
    cout<<"test: buscar en el Nodo 2 con la version 6 el valor con posicion 1::"<<endl;;
    test.buscar(2,6,1);

    cout<<endl;
    

}