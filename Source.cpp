#include<iostream>
#include<string>
//Наследование - 
// это механизм расмширения функционала класса путем сужения его специализации,
//    при котором открывается дорога для полиморфизма.
//  публичное наследование позволяет тпользоваться внутри объекта наследника
//  родительскими полями public и protected, так как будто они являются его полЯми public и protected


class Base {
public:
	//Base() = default; - чтобы компилятор сам сделал конструктор по умолчанию

	Base():Base(0, 0, 0){ }//создали конструктор по умолчанию передавая нулевые объекты класса
	Base(int a, int b, int c):a(a),b(b),c(c){ }
	int a;
	int A() { return a; }
	int B() { return b; }
	int C() { return c; }
protected:
	int b;
private:
	int c;
};

class Derived:public Base{
public:
	Derived() = default;
	Derived(int a, int b, int c, int d):Base(a,b,c), d(d) {//во время делегации нужно соблюдать порядок (a,b,c)

	}

	int MOO() {
		int res{};
		res = a + b;//свободно используем публичные и защищенные поля
		res /= C();//приватные поля доступны через методы доступа внутри класса
		return res;
	}
	int D() { return d; }
private:
	int d;
};

class Animal {
public:
	int Age()const { return age_; }
	void Age(int newAge) { age_ = newAge; }

	void Name(std::string newName) { name_ = newName; }
	std::string Name()const { return name_; }

	virtual void Say()const {//virtual - виртуально помечают функцию которая должна
		                     //вызываться у наследников в момент их обработки под видом родителя
		std::cout << "Жрать\n";
	}
private:
	std::string name_;
	int age_;
};

class Cat :public Animal {
public:
	void Say()const override {//override - дополнительная проверка о том что мы функцию объявили правильно
		                        //используется для проверки родительского функционала
		std::cout << "Брысь\n";
	}

};


int main() {
	system("chcp 1251>nul");

	Base obj(1,2,5);
	obj.a;
	//obj.b;
	//obj.c;
	Derived dobj(1,2,7,777);
	dobj.B();

	Animal abs;
	abs.Name("Dog");
	abs.Age(1);
	abs.Say();
	Cat cat;
	cat.Name("Пушистик");
	cat.Age(5);//по умолчанию вызовет свою реализацию
	cat.Animal::Say();//принудительно вызвали реализацию родителя
	Animal* p = &abs;
	p = &cat;
	p->Say();






	return 0;
}