#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename RType, typename CType> 
class Mem_fun_ref_class: public unary_function<CType, RType>
{
    RType (CType::*pf)() const;
public:
    Mem_fun_ref_class(RType (CType::*_pf)() const):pf(_pf) {}
    RType operator()(const CType& o) const
    {
        return (o.*pf)();
    }
};

// 어댑터 함수: 멤버 함수를 주소를 저장하는 함수 객체를 반환
template<typename RType, typename CType> 
Mem_fun_ref_class<RType, CType> Mem_fun_ref(RType (CType::*pf) {}
