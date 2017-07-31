// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name   Xiaochen Wang          Date     7 July 2017     Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include "Date.h"
#include "general.h"
using namespace std;

namespace sict{
    Date::Date() {
       year_ = 0;
       mon_ = 0;
       day_ = 0;
       readErrorCode_ = NO_ERROR;
    }

    Date::Date(int year, int mon, int day) {
       year_ = year;
       mon_ = mon;
       day_ = day;
       readErrorCode_ = NO_ERROR;
    }

   int Date::value()const {
      return year_ * 372 + mon_ * 31 + day_;
   }

    int Date::errCode() const {
       return readErrorCode_;
    }

   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
      mon--;
      return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
   }

    bool Date::operator==(const Date & data) const {
       return (this->value() == data.value());
    }

    bool Date::operator!=(const Date & data) const {
       return (this->value() != data.value());
    }

    bool Date::operator<(const Date & data) const {
       return (this->value() < data.value());
    }

    bool Date::operator>(const Date& data)const {
       return (this->value() > data.value());
    }

    bool Date::operator<=(const Date& data)const {
       return (this->value() <= data.value());
    }

    bool Date::operator>=(const Date& data)const {
       return (this->value() >= data.value());
    }

   void Date::errCode(int errCode) {
      readErrorCode_ = errCode;
   }

    bool Date::bad() const {
        return (readErrorCode_!=0);
    }

    std::istream& Date::read(std::istream & ist) {
         char dataA;
        errCode(NO_ERROR);

         ist >> year_ >> dataA >> mon_ >> dataA >> day_ ;
        if (ist.fail()){
            errCode(CIN_FAILED);
        }else if (MIN_YEAR > year_ || year_ > MAX_YEAR){
           errCode(YEAR_ERROR);
        }else if (1 > mon_ || mon_ > 12){
           errCode(MON_ERROR);
        }else if (day_ > mdays()) {
           errCode(DAY_ERROR);
        }
        ist.clear();

        if(Date::bad()){
            ist.setstate(ios::failbit);
        }
       return ist;
    }

    std::ostream& Date::write(std::ostream& ost) const
    {
       ost << year_ << "/";
       if (mon_ < 10)
       {
          ost << "0" << mon_ << "/";
           if (day_ < 10) {
               ost << "0" << day_;
           } else {
               ost << day_;
           }
       }else {
           ost << mon_ << "/";
           if (day_ < 10) {
               ost << "0" << day_;
           } else {
               ost << day_;
           }
       }
       return ost;
    }

    // operator << and >> overload prototypes for cout and cin
    std::istream& operator >> (std::istream& ist, Date& D)
    {
       //D.read(is);
       return D.read(ist);
    }


    std::ostream& operator << (std::ostream& ost, const Date& D)
    {
       //D.write(ostr);
       return D.write(ost);
    }



}
