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
// Name  Xiaochen Wang      Date   7 July 2017     Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_DATE_H__
#define SICT_DATE_H__

namespace sict{
    // define date Error values
    #define NO_ERROR 0
    #define CIN_FAILED 1
    #define YEAR_ERROR 2
    #define MON_ERROR 3
    #define DAY_ERROR 4

   class Date {
   private:
       // member variables
       int year_; //Year; a four digit integer between MIN_YEAR and MAX_YEAR, as defined in POS.h
       int mon_; //Month of the year, between 1 to 12
       int day_; //Day of the month, note that in a leap year February has 29 days, (see mday() member function)
       int readErrorCode_;  // Error code which identifies the validity of the date and, if erroneous, the part that is erroneous. Define the possible error values defined in the Date header-file as follows:
       // member methods
       int value()const;
       void errCode(int errorCode);

   public:
       // constructors
       Date();
       Date(int year, int mon, int day);
       //Date(int year, int mon, int day, int hour, int min = 0);

       // operator ovrloads
       bool operator==(const Date&)const;
       bool operator!=(const Date&)const;
       bool operator<(const Date&)const;
       bool operator>(const Date&)const;
       bool operator<=(const Date&)const;
       bool operator>=(const Date&)const;

       // methods
       int errCode()const;
       //Returns the m_readErrorCode value.
       bool bad()const;

       // istream  and ostream read and write methods
       std::istream& read(std::istream&);
       std::ostream& write(std::ostream&)const;
 
      int mdays()const;
   };
    // operator<< and >> overload prototypes for cout and cin
    std::istream& operator>>(std::istream& , Date& );
    std::ostream& operator<<(std::ostream&, const Date&);
}
#endif