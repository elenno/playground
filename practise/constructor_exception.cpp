//this is an example of throwing exception in constructor,
//and showing how to call the destructor to delete the memory allocated in constructor to prevent memory leak,
//using "placement delete"
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace  std;

class ConWithException
{
public:
    ConWithException() : _pBuf(NULL)
    {
        _pBuf = new int[100];
        cout << "before throw exception in constructor" << endl;
        throw std::runtime_error("Exception in Constructor!");
    }

    ~ConWithException()
    {
        cout << "Destructor!" << endl;
        if( _pBuf != NULL )
        {
            cout <<  "Delete buffer..." << endl;
            delete[] _pBuf;
            _pBuf = NULL;
        }
        else
        {
                cout << "NULL pBuf" << endl;
        }
        cout << "Destructor end!" << endl;
    }
	
    void * operator new(size_t size){
        cout << "placement new" << endl;
        return ::operator new(size);
    }

    void operator delete(void* mem){
        cout << "placement delete" << endl;
        ((ConWithException*)mem)->~ConWithException();
        ::operator delete(mem);
    }

private:
    int* _pBuf;
};

int main(int argc, char** argv)
{
    ConWithException* cwe = NULL;
    try
    {
        cwe = new ConWithException;
    }
    catch( std::runtime_error& e )
    {
        cout<<"exception:"<< e.what() << endl;
    }

    if (cwe == NULL)
    {
        cout << " already NULL, no need to delete" << endl;
    }
    return 0;
}