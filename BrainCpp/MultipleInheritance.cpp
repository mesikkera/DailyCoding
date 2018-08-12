#include <string>
using namespace std;

// 학부생 클래스
class UnderGradStudent
{
public:
    string name;                // 이름
    string department;          // 학부
};

// 기숙사행 클래스
class DormStudent 
{
public:
    string building;            // 기숙사 명
    int roomNumber;             // 방번호
};

// 기숙사생이면서 학부생인 경우
class UnderGrad_DormStudent : public UnderGradStudent, public DormStudent
{
public:

};

int main()
{
    // 기숙사생이면서 학부생인 사람의 정보 생성
    UnderGrad_DormStudent std;
    std.name = "손흥민",
    std.department = "Info & Computer Engineering",
    std.building = "Hotel",
    std.roomNumber = 1592;

    return 0;
}