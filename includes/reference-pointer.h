class Base
{
    public:
        virtual void print_n() = 0;
};
class Reference:public Base
{
    public:
    Reference(int n):n(n){}
    void print_n()override;
    private:
    int n;
};
class Pointer:public Base
{
    public:
    Pointer(int n):n(n){}
    void print_n()override;
    private:
    int n;
};
void test_point_reference();