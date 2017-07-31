// AmaPerishable.h
#ifndef ICT_AMAPERISHABLE_H__
#define ICT_AMAPERISHABLE_H__

#include"AmaProduct.h"

#include"Product.h"
#include"general.h"
#include"Date.h"

using namespace std;
namespace sict {

    class AmaPerishable : public AmaProduct{
        Date expiry_;

    public:
        AmaPerishable();
        ~AmaPerishable();
//        const Date & expiry() const;
        void expiry (const Date& value);
        fstream& store(fstream& file, bool = true)const;
        fstream& load(fstream& file);
        ostream& write(ostream& ostr, bool linear)const;
        istream& read(istream& istr);
    };
};
#endif