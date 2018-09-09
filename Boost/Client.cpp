#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main()
{
    // 1단계: 클라이언트 프로그램이 연결할 서버 프로그램의 IP 주소와
    // 프로토콜 포트 번호를 이미 알고 있다고 가정한다.
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;

    // IP 주소를 분석하는 동안 발생할 수 있는 오류 정보를 저장하는데 쓰인다.
    boost::system::error_code ec;

    // 2단계; IP 프로토콜 버전과 관계없는 주소 형식을 사용한다.
    asio::ip::address ip_address = asio::ip::address::from_string(raw_ip_address, ec);

    if(ec.value() != 0) {
        // 알고 있던 IP 주소가 유효하지 않다. 실행을 중단한다.
        std::cout << "Failed to parse the IP address. Error code = " << ec.value() << ". Message: " << ec.message();
        return ec.value();
    }

    // 3단계
    asio::ip::tcp::endpoint ep(ip_address, port_num);

    // 4단계: 종료점의 준비가 끝났다.
    // 통신하려는 특정 서버를 나타내는 데 쓰일 수 있다.

    return 0;
}