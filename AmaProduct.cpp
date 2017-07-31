// AmaProduct.cpp
#define _CRT_SECURE_NO_WARNINGS
// AmaPersishable.cpp
#include "AmaProduct.h"
#include "general.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
namespace sict{
    AmaProduct::AmaProduct(char n_tag){
        fileTag_=n_tag;
//        err_.clear();
    };

    const char* AmaProduct::unit()const{
        return unit_;
    };

    void AmaProduct::unit(const char* value){
        strcpy(unit_, value);
    };

    fstream & AmaProduct::store(fstream &file, bool addNewLine) const {
        char comma = ',';
        if (file.is_open()) {
            file << fileTag_ << comma
                 << this->sku() << comma
                 << this->name() << comma
                 << this->price() << comma
                 << this->taxed() << comma
                 << this->quantity() << comma
                 << this->unit() << comma
                 << this->qtyNeeded();
            if (addNewLine) {
                file << endl;
            } else {
                file << comma;
            }
        } else {
            cout << "file is not opened. " << endl;
        }
        //file.close();
        return file;
//        file << fileTag_ << "," << this->sku() << "," << this->name() << "," << this->price() << "," << this->quantity() << "," << this->unit() << this->qtyNeeded();
//        return file;
    };

    fstream& AmaProduct::load(fstream& file) {
        char skuTemp[MAX_SKU_LEN + 1];
        char nameTemp[30 + 1];
        double priceTemp;
        bool taxedTemp;
        int quantityTemp;
        int qtyNeededTemp;
        char unitTemp[11 + 1];
        char comma;


        if (file.is_open())
        {
            file.getline(skuTemp, MAX_SKU_LEN, ',');
            file.getline(nameTemp, 30, ',');
            file >> priceTemp;
            file >> comma;
            file >> taxedTemp;
            file >> comma;
            file >> quantityTemp;
            file >> comma;
            file.getline(unitTemp, 11, ',');
            file >> qtyNeededTemp;

            sku(skuTemp);
            name(nameTemp);
            // nameTemp[30] = '\0';
            if(taxedTemp) {
                price(priceTemp*(1+TAX));
            } else {
                price(priceTemp);
            }
            quantity(quantityTemp);
            unit(unitTemp);
            qtyNeeded(qtyNeededTemp);

        }     // file opened;
        else
        {
            cout << "file is not opened. " << endl;
        }
        return file;
    }

    ostream&AmaProduct::write(ostream& ostr, bool linear) const {
//        if (err_.isClear()){
//            if(linear){
//                ostr << left << setw(MAX_SKU_LEN) << Product::sku() << '|'
//                     << left << setw(20) << Product::name() << '|'
//                     << right << setw(7) << fixed << setprecision(2) << Product::price() << '|';
//                if (Product::taxed()) {
//                    ostr << " T";
//                } else {
//                    ostr << "  ";
//                }
//                ostr << setw(2) << Product::quantity() << '|'
//                     << setw(10)<<left<< AmaProduct::unit()<<'|'
//                     <<setw(4) << right <<AmaProduct::qtyNeeded()<<'|';
//            } else {
//                ostr << "Name:" << Product::name() << endl
//                     << "Sku: " << Product::sku() << endl
//                     << "Price: " << Product::price() << endl
//                     << "Price after tax: ";
//                if (Product::taxed()) {
//                    ostr << Product::cost();
//                } else {
//                    ostr << "N/A";
//                }
//                ostr << endl;
//                ostr << "Quantity On Hand: " << Product::quantity() << " "<< AmaProduct::unit()<<endl
//                     << "Quantity Needed: " << Product::qtyNeeded() << endl
//                     << "Expiry date: ";
//            }
//        }
        ostr.clear();
        if (err_.isClear()) {
            if (linear)
            {
                ostr << left << setw(MAX_SKU_LEN) << sku() << "|"
                   << left << setw(20) << name() << "|";
                        if(taxed()){
                            ostr << right << fixed << setw(7) << setprecision(2) << cost() << "|";
                        }else{
                            ostr << right << fixed << setw(7) << setprecision(2) << price() << "|";
                        }
                   ostr<< right << setw(4) << fixed << quantity() << "|"
                   << left << setw(10) << unit() << "|"
                   << right << setw(4) << fixed << qtyNeeded() << "|";

            } else { // Linear is true
                if (taxed()) {
                    ostr << "Sku: " << sku() << endl
                       << "Name: " << name() << endl
                       << "Price: " << fixed << setprecision(2) << price() << endl
                       << "Price after tax: " << cost() << endl
                       << "Quantity On Hand: " << fixed << quantity() << " " << unit() << endl
                       << "Quantity Needed: " << fixed << qtyNeeded();
                } else { // product is taxed
                    ostr << "Sku: " << sku() << endl
                       << "Name: " << name() << endl
                       << "Price: " << fixed << setprecision(2) << price() << endl
                       << "Price after tax: N/A" << endl
                       << "Quantity On Hand: " << fixed << quantity() << " " << unit() << endl
                       << "Quantity Needed: " << fixed << qtyNeeded() << endl
                       << "Expiry date: ";
                }     //   product is not taxed

            }     // Linear is false
        } else {
            ostr << err_.message();
        }
        return ostr;
    };

    istream& AmaProduct::read(istream& istr) {
        char skuTemp[MAX_SKU_LEN + 1];
        char nameTemp[31];
        char unitTemp[11 + 1];
        char taxedTemp;
        double priceTemp;
        int quantityTemp;
        int qtyNeededTemp;

        //istr.clear();
        //istr.ignore();
        err_.clear();
        cout << "Sku: ";
        istr.getline(skuTemp, MAX_SKU_LEN, '\n');
        if (istr.fail()) { return istr; }
        sku(skuTemp);

        cout << "Name: ";
        istr.getline(nameTemp, 30, '\n');
        if (istr.fail()) { return istr; }
        name(nameTemp);

        cout << "Unit: ";
        istr.getline(unitTemp, 11, '\n');
        if (istr.fail()) { return istr; }
        unit(unitTemp);

        if (AmaProduct::err_.isClear()) {
            cout << "Taxed? (y/n): ";
            istr >> taxedTemp;

            if (istr.fail()) {
                AmaProduct::err_.message("Only (Y)es or (N)o are acceptable");
                istr.setstate(ios::failbit);
            } else {
                if (taxedTemp == 'Y' || taxedTemp == 'y'){
                    taxed(1);
                } else if (taxedTemp == 'N' || taxedTemp == 'n') {
                    taxed(0);
                } else {
                    AmaProduct::err_.message("Only (Y)es or (N)o are acceptable");
                    istr.setstate(ios::failbit);
                }
            }
        } else {
            AmaProduct::err_.message("Only (Y)es or (N)o are acceptable");
            istr.setstate(ios::failbit);
            return istr;
        }

        if (err_.isClear()) {
            cout << "Price: ";
            istr >> priceTemp;
            if (istr.fail()) {
                err_.message("Invalid Price Entry");
                istr.setstate(ios::failbit);
            } else {
                price(priceTemp);
            }
        } else {
            return istr;
        }

        if (err_.isClear()) {
            cout << "Quantity On hand: ";
            istr >> quantityTemp;
            if (istr.fail()) {
                err_.message("Invalid Quantity Entry");
                istr.setstate(ios::failbit);
            } else {
                quantity(quantityTemp);
            }
        } else {
            return istr;
        }

        if (err_.isClear()) {
            cout << "Quantity Needed: ";
            istr >> qtyNeededTemp;
            if (istr.fail()) {
                err_.message("Invalid Quantity Needed Entry");
                istr.setstate(ios::failbit);
            } else {
                qtyNeeded(qtyNeededTemp);
            }
            return istr;
        }
        return istr;
    }
};






