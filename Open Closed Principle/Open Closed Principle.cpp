#include <iostream>
#include <vector>
#include <string>

class Product {
public:
    virtual double getPrice() const = 0;
};

class Book : public Product {
private:
    std::string title;
    double price;

public:
    Book(std::string t, double p) : title(t), price(p) {}

    double getPrice() const override {
        return price;
    }
};

class Electronics : public Product {
private:
    std::string model;
    double price;

public:
    Electronics(std::string m, double p) : model(m), price(p) {}

    double getPrice() const override {
        return price;
    }
};

class OrderProcessor {
public:
    virtual void processOrder(const Product& product) const = 0;
};

class ReceiptPrinter : public OrderProcessor {
public:
    void processOrder(const Product& product) const override {
        std::cout << "Printing receipt for product: " << typeid(product).name() << " with price $" << product.getPrice() << std::endl;
    }
};

class EmailSender : public OrderProcessor {
public:
    void processOrder(const Product& product) const override {
        std::cout << "Sending email for product: " << typeid(product).name() << " with price $" << product.getPrice() << std::endl;
    }
};

int main() {

    Book book("The Example Book", 20.0);
    Electronics electronics("Smartphone", 500.0);

    ReceiptPrinter receiptPrinter;
    EmailSender emailSender;

    receiptPrinter.processOrder(book);

    std::cout << "\n";

    emailSender.processOrder(electronics);

    return 0;
}