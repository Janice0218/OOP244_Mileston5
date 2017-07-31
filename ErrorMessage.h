// Final Project Milestone 2
// Version 1.0
// Date 09 July 2017	
// Author Xiaochen Wang
//
//
// Revision History
// -----------------------------------------------------------
// Name Xiaochen Wang    Date   09 July 2017     Reason
#ifndef SICT_ERRORMESSAHE_H_
#define SICT_ERRORMESSAHE_H_

#include <iostream>

namespace sict {
    class ErrorMessage{
    private:
        char* message_;
    public:
        //constructor
        ErrorMessage();
        ErrorMessage(const char* errorMessage);
        ErrorMessage(const ErrorMessage& em) = delete;

        //destructor
        virtual ~ErrorMessage();

        //Public member functions and operator overloads (methods):
        ErrorMessage& operator=(const ErrorMessage& em) = delete; //A deleted assignment operator overload to prevent an ErrorMessage object to be assigned to another.
        ErrorMessage& operator=(const char* errorMessage); // Sets the message_ to the  errorMessage argument and returns the current object (*this)

        void clear(); // De-allocates the memory pointed by message_ and then sets message_ to nullptr.
        bool isClear()const; // Returns true if message_  is nullptr.
        void message(const char* value); // Sets the message_ of the ErrorMessage object to a new value
        const char* message()const; // Returns the address kept in message_.
        friend  std::ostream& operator<<(std::ostream&, const ErrorMessage&);

    };
    std::ostream& operator<<(std::ostream&, const ErrorMessage&);
}

#endif
