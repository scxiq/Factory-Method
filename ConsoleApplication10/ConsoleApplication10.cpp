#include <iostream>

// Абстрактний клас продукту
class Product {
public:
    virtual void display() = 0;
};

// Конкретний клас продукту
class ConcreteProduct : public Product {
public:
    void display() override {
        std::cout << "Concrete Product\n";
    }
};

// Абстрактний клас фабрики
class Creator {
public:
    virtual Product* createProduct() = 0;
};

// Конкретна фабрика, яка створює конкретний продукт
class ConcreteCreator : public Creator {
public:
    Product* createProduct() override {
        return new ConcreteProduct();
    }
};

int main() {
    // Використання фабричного методу
    Creator* creator = new ConcreteCreator();
    Product* product = creator->createProduct();
    product->display();

    delete product;
    delete creator;

    return 0;
}
