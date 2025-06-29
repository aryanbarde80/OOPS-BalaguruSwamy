#include<iostream>
using namespace std;

class ABC; // Forward declaration

//-----------------------------------//

class XYZ
{
    int x;
    public:
    void setvalue(int i){x=i;} // ✅ Fixed: added missing semicolon
    friend void max(XYZ,ABC);
};

//----------------------------------//

class ABC
{
    int a;
    public:
    void setvalue(int i){a=i;} // ✅ Fixed: added missing semicolon
    friend void max(XYZ,ABC);
};

//-----------------------------------//
void max(XYZ m,ABC n) // Definition of friend
{
    if(m.x >= n.a){
        cout<<m.x;
    }
    else{
        cout<<n.a;
    }

}

//----------------------------------//
int main(){
    ABC abc;
    abc.setvalue(10);
    XYZ xyz;
    xyz.setvalue(20);
    max(xyz,abc);

    return 0;
}
