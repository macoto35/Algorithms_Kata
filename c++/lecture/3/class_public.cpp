#include <iostream>

using namespace std;

class Number {
	public:
		int num;
};

/*
- Object: Any entity has state and behavoir. Instance of class
- Class: Blueprint. Collection of objects. Logical entity.
- Inheritance: One object acquires all the properties and behaviours of a parent object. Provide code reusability. Achieve runtime polymorphism.
- Polymorphism: One task is performed by different ways. (e,g, Animal parent / cat, dog and duck are children - make different sound). Use method overloading/overriding to achieve this.
- Abstraction: Hiding internal details and showing functionality. Use abstract class and interfact to achieve this.
- Encapsulation: Wrapping code and data together into a single unit. (e.g. java class) 
*/
int main(void)
{
	Number n;
	n.num = 3;

	cout << n.num;
}
