
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Product.h"

using namespace std;

namespace sict{
    Product::Product() {

        sku_[0] = '\0';
        name_ = nullptr;
        price_ = 0;
        taxed_ = false;
        quantity_ = 0;
        qtyNeeded_ = 0;
    }

    Product::Product (const char* sku, const char* name, bool taxed, double price, int qtyNeeded) {
        strncpy(sku_,sku,MAX_SKU_LEN+1);
        name_ = new char[strlen(name) +1];
        strcpy(name_, name);
        quantity_ = 0;
        qtyNeeded_ = qtyNeeded;
        price_ = price;
        taxed_ = taxed;
    }



    Product& Product::operator=(const Product &other) {
        if(this != &other) {
            strncpy(sku_,other.sku_,MAX_SKU_LEN+1);
            quantity_ = other.quantity_;
            qtyNeeded_ = other.qtyNeeded_;
            price_ = other.price_;
            taxed_ = other.taxed_;

            if(name_ != nullptr) {
                delete[] name_;
            }

            name_ = new char[strlen(other.name_) + 1];
            strcpy(name_, other.name_);

        } else {
            sku_[0] = '\0';
            name_ = nullptr;
            price_ = 0;
            taxed_ = false;
            quantity_ = 0;
            qtyNeeded_ = 0;
        }
        return *this;
    }

//    Product::~Product() {
//        delete[] name_;
//        name_ = nullptr;
//    }

    void Product::sku(const char sku[]) {
        strncpy(sku_, sku, MAX_SKU_LEN);
    }

    void Product::name(const char *name) {
        delete[] name_;
        name_ = new char[strlen(name) + 1];
        strcpy(name_, name);
    }

    void Product::price(double price) {
        price_ = price;
    }

    void Product::taxed(bool taxed) {
        taxed_ = taxed;
    }

    void Product::quantity(int quantity) {
        quantity_ = quantity;
    }

    void Product::qtyNeeded(int qtyNeeded) {
        qtyNeeded_ = qtyNeeded;
    }

    //TODO Getter
    const char* Product::sku() const {
        return sku_;
    }

    char* Product::name() const {
        return name_;
    }

    double Product::price() const {
        return price_;
    }

    bool Product::taxed() const {
        return taxed_;
    }

    int Product::quantity() const {
        return quantity_;
    }

    int Product::qtyNeeded() const {
        return qtyNeeded_;
    }

    double Product::cost() const {
	double price = price_;
        if(Product::taxed()){
            price = price*(1+TAX);
        }
	return price;
    }

    const bool Product::isEmpty() const {
        if(sku_[0] == '\0' && name_ == nullptr && price_ == 0 && qtyNeeded_ == 0 && quantity_ == 0 && taxed_ == false) {
            return true;
        }
        return false;
    }

    bool Product::operator==(const char* sku) {
        bool TF = false;
        if(strcmp(sku_,sku) == 0){
            TF = true;
        }
        return TF;
    }

    int Product::operator+=(int add) {
        quantity_ += add;
        return quantity_;
    }

    int Product::operator-=(const int min) {
        return quantity_ -= min;
    }

    double operator+=(double& left, const Product& item) {
        left = (item.cost() * item.quantity());
	return left;
    }

    std::istream& operator >> (std::istream& is, Product& I) {
        I.read(is);
        return is;
    }
    std::ostream& operator<<(std::ostream&os, const Product& I)
    {
        I.write(os,true);
        return os;
    }

}
