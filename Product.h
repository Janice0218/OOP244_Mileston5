
#ifndef SICT_PRODUCT_H_
#define SICT_PRODUCT_H_

#include "Streamable.h"
#include "general.h"
#include "MyFile.h"

namespace sict{
    class Product: public Streamable{
    private:
        char sku_[MAX_SKU_LEN+1];
        char * name_;
        double price_;
        bool taxed_;
        int quantity_;
        int qtyNeeded_;
    public:
        Product();
        Product(const char *sku, const char *name, bool taxed = true, double price = 0.0, int quantity = 0);
        Product& operator=(const Product& other);
//        ~Product();

        //TODO SETTER
        void sku(const char * sku);
        void name(const char * name);
        void price(double price);
        void taxed(bool taxed);
        void quantity(int quantity);
        void qtyNeeded(int qtyNeeded);

        //TODO GETTER
        const char * sku() const;
        char * name() const;
        double price() const;
        bool taxed() const;
        int quantity() const;
        int qtyNeeded() const;

        double cost()const;
        const bool isEmpty() const;

        bool operator == (const char * sku);
        int operator += (int add);
        int operator -= (const int min);
    };
    // end class Item
    // operator +=
    double operator+=(double& d, const Product& I);
    // operator << and operator >>

    std::istream& operator >> (std::istream&, Product&);
    std::ostream& operator << (std::ostream&, const Product&);
}

#endif
