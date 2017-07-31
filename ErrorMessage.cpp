// Final Project Milestone 2
// Version 1.0
// Date 09 July 2017	
// Author Xiaochen Wang
//
// Revision History
// -----------------------------------------------------------
// Name Xiaochen Wang    Date   09 July 2017     Reason
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "ErrorMessage.h"
#include "Product.h"

using namespace std;

namespace sict{
    ErrorMessage::ErrorMessage() {
        message_ = nullptr;
    }

    ErrorMessage::ErrorMessage(const char *errorMessage) {
        message_ = nullptr;
        // cout<<"2222222";
        ErrorMessage::message(errorMessage);
    }

    ErrorMessage::~ErrorMessage() {
        delete[] message_;
        message_=nullptr;

    }

    ErrorMessage& ErrorMessage::operator=(const char *errorMessage) {
        //cout<<"333333333";
        ErrorMessage::clear();
        ErrorMessage::message(errorMessage);
        return *this;
    }



    void ErrorMessage::clear() {
        // cout<<"44444444444";

        delete[] message_;
        message_ = nullptr;

    }

    bool ErrorMessage::isClear() const {
        //cout<<"5555555555555";
        return (message_ == nullptr);
    }

    void ErrorMessage::message(const char* value) {
        //  cout<<"666666666666";

        delete[] message_;
        message_=nullptr;
        message_ = new char[strlen(value) + 1];
        strcpy(message_, value);
        // cout<<message_<<endl;
    }

    const char* ErrorMessage::message() const {
        //Product::clear();
        return message_;
    }


    std::ostream& operator<<(std::ostream& os, const ErrorMessage& e){
        if(!e.isClear()){
            //cout<<e.message_
            os<< e.message_;

        }

        return os;
    }

}
