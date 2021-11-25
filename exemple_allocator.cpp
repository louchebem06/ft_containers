// http://casteyde.christian.free.fr/cpp/cours/online/x5348.html

#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
    A();
    A(const A &);
    ~A();
};

A::A()
{
    cout << "Constructeur de A" << endl;
}

A::A(const A &)
{
    cout << "Constructeur de copie de A" << endl;
}

A::~A()
{
    cout << "Destructeur de A" << endl;
}

int main(void)
{
    // Construit une instance de l'allocateur standard pour la classe A :
    allocator<A> A_alloc;

    // Alloue l'espace nécessaire pour stocker cinq instances de A :
    allocator<A>::pointer p = A_alloc.allocate(5);

    // Construit ces instances et les initialise :
    A init;
    int i;
    for (i=0; i < 5; ++i)
        A_alloc.construct(p+i, init);
    // Détruit ces instances :
    for (i=0; i < 5; ++i)
        A_alloc.destroy(p+i);

    // Reconstruit ces 5 instances :
    for (i=0; i<5; ++i)
        A_alloc.construct(p+i, init);
    // Destruction finale :
    for (i=0; i<5; ++i)
        A_alloc.destroy(p+i);

    // Libère la mémoire :
    A_alloc.deallocate(p, 5);
    return 0;
}
