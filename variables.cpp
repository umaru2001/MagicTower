#include "variables.h"

people::people(int h, int a, int d, int g, int e,string n, string i) :hp(h), at(a), df(d), gold(g), exp(e)
{

}

people::people(): hp(0), at(0), df(0), gold(0), exp(0)
{

}

people::~people()
{

}

monster::monster(int h, int a, int d, int g, int e, int id, string n, string i) :people(h, a, d, g, e,n, i), id(id)
{

}

monster::monster():people(0, 0, 0, 0, 0, "", ""), id(0)
{

}

monster::~monster()
{

}

character::character(int h, int a, int d, int g, int e, int x, int y,
    int floor, int face, int l, int yk, int bk, int rk, int dms,string n, string i) :
    people(h, a, d, g, e, n, i), pos_x(x), pos_y(y),floor(floor), face(face),lv(l)
    ,ykey(yk),bkey(bk),rkey(rk),dms_door(dms)
{

}

character::~character()
{

}

GLOBAL_VARS::GLOBAL_VARS(int end, int op) :end_no(end), OperationStatus(op)
{

}

GLOBAL_VARS::GLOBAL_VARS()
{

}

GLOBAL_VARS::~GLOBAL_VARS()
{

}
