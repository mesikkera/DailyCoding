#ifndef CAT_H
#define CAT_H

// 고양이 관련
namespace Cat
{
    // 고양이 한 마리 정보 
    class Info 
    {
    public:
        void Meow();
    protected:
        char name[20];
    };

    extern Info cats[20];       // 고양이 리스트
    extern int count;           // 전체 고양이들의 수

    void CreateAll();           // 모든 고양이 생성 함수
}

#endif