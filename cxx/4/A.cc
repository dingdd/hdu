
class A
{
    char *cp;
    double &dr;
public:
    A(char c, double &r)
    : dr(r)
    {
        cp = new char (c);
    }
    char get() const
    {
        return *cp;
    }
    ~A()
    {
        delete cp;
    }
		A(A&a):cp(NULL),dr(a.dr){
			cp=new char(*a.cp);
		}
};

A foo(double& d)
{
    A a('c', d);
    return a;
}

int main()
{
    double d=3.14;
    foo(d).get();
}
