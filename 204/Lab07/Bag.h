/********************************************************************************
 * Filename: bag.h
 * Name & Student No.: Yanhong Ben, 4845675
 * Lab No: 7
 * File Description: header file of bag
 * Date Last Modified: 17/09/2015
 *********************************************************************************/

#ifndef Bag_h
#define Bag_h

namespace MYLIB
{
    const int MAX = 50;
    
    template<class T>class Bag;
    
    template <class T>
    std::ostream& operator<< (std::ostream&, const Bag<T> &);

    template <class T>
    class Bag
    {
        friend std::ostream& operator<< <T>(std::ostream &,const Bag<T> &);
        private:
            T *data;
            int curr_num;
            int size;
        public:
            Bag();
            ~Bag();
            Bag(const Bag &);
            void add(T);
            void remove(T);
            Bag<T> operator+(const Bag<T> &);
    };
}

#endif
