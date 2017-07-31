#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include <iomanip>
#include "Date.h"
#include "AmaProduct.h"
#include "AmaPerishable.h"

using namespace std;
namespace sict {

//    char AmaPerishable::signatures() const {
//        return 'P';
//    }
    AmaPerishable::AmaPerishable():AmaProduct('P'){
        err_.clear();
    };

    AmaPerishable::~AmaPerishable() {
        err_.clear();
    }

    fstream & AmaPerishable::store(fstream & fs, bool addNewLine) const {
        AmaProduct::store(fs, false);
        fs << expiry_ << endl;
        //fs.close();
        return fs;
    }

    fstream& AmaPerishable::load(fstream& file) {
        char waste;
        int year,mm,dd;
        if (file.is_open()) {
         // file.getline(waste,',');
         //   cout<<"!!!!!!"<<waste;
        AmaProduct::load(file);
            file>>waste;
            file>>year;
            //file.ignore();
            file>>waste;
            file>>mm;
            file>>waste;
           // file.ignore();
            file>>dd;
            Date temp(year,mm,dd);
        AmaPerishable::expiry(temp);

         //   cout<<"@@@@@@@@@@@@end product"<<endl;
       //  file.getline(waste,'\0');
      //  file.ignore();

        file.close();
        }
        return file;
    }

    ostream & AmaPerishable::write(ostream& ostr, bool linear) const {
        //Calls the write of the parent passing ostr and linear as arguments.
        //Then if err_ is clear and product is not empty
        //cout<<"--------1-------"<<endl;
//        AmaProduct::write(ostr,linear);
//
//        if(err_.isClear() && AmaProduct::sku() !='\0'){
//            if(linear == true) {
//                expiry_.write(ostr);
//
//            }
//        }else{
//            cout << endl;
//            expiry_.write(ostr);
//        }
//        return ostr;

        if(!err_.isClear()) {
            ostr<<err_.message();
        } else if(err_.isClear()) {
            AmaProduct::write(ostr, linear);
            ostr<<AmaPerishable::expiry_;
           // err_.message();
        }
        return ostr;
    }

    istream & AmaPerishable::read(istream & istr) {
        istr.clear();
        AmaProduct::read(istr);

        if (err_.isClear()) {
            cout << "Expiry date (YYYY/MM/DD): ";
            expiry_.read(istr);
        }

        if (expiry_.errCode() == CIN_FAILED){
            err_.clear();
            err_.message("Invalid Date Entry");
        }
        if (expiry_.errCode() == YEAR_ERROR){
            err_.message("Invalid Year in Date Entry");
        }
        if (expiry_.errCode() == MON_ERROR){
            err_.clear();
            err_.message("Invalid Month in Date Entry");
        }
        if (expiry_.errCode() == DAY_ERROR){
            err_.clear();
            err_.message("Invalid Day in Date Entry");
        } 
        if (expiry_.errCode()){
            istr.setstate(ios::failbit);
        }
        if (expiry_.errCode()!= CIN_FAILED && expiry_.errCode() != YEAR_ERROR && expiry_.errCode() != MON_ERROR && expiry_.errCode() != DAY_ERROR) {
            err_.clear();  //clear if there is no errorcode.
        }

        return istr;
    }

//     const Date& AmaPerishable::expiry()const{
//         return expiry_;
//     }
//
     void AmaPerishable::expiry(const Date &value){
         expiry_= value;
     }

}
