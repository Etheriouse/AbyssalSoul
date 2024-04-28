#ifndef Vector_h
#define Vector_h

class vector {

    public:
        vector();
        vector(int x, int y);
        vector(vector* v);
        void productLambda(int l);
        void productLambda(double l);
        void productVector(vector v);
        void additionLambda(double l);
        void additionLambda(int l);
        void additionVector(vector v);
        double x;
        double y;


};

#endif