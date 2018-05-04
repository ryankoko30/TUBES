#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"
#include "sub_main.h"


int main()
{
    string jawab;
    cout<<"masuk sebagai"<<endl;
    cout<<"a.admin"<<endl;
    cout<<"b.pelanggan"<<endl;
    cin>>jawab>>endl;
    if ( jawab == "a"){
        goto admin();
    }
    else{
        goto pelanggan();
    }
}

