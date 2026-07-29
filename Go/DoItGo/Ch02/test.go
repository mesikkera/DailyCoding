package main

import "fmt"

func main() {
	// 1. fmt.Print 사용 예시
	// Print는 자동으로 줄바꿈이나 띄어쓰기를 해주지 않습니다.
	fmt.Print("Hello")
	fmt.Print("Go")

	// 여기까지의 출력 결과: HelloGo (띄어쓰기 없이 붙어서 출력되고, 줄바꿈도 되지 않은 상태)

	// 보기 편하게 줄바꿈 기호(\n)를 직접 한 번 넣어주겠습니다.
	fmt.Print("\n---\n")

	// 2. fmt.Println 사용 예시
	// 쉼표로 구분한 값들 사이에 자동으로 공백이 들어가고, 마지막에 줄이 바뀝니다.
	fmt.Println("Hello", "Go", "World")
	// 출력 결과: Hello Go World

	// 앞선 Println이 줄바꿈을 해두었으므로, 이 문장은 자동으로 다음 줄에 출력됩니다.
	fmt.Println("반갑습니다!")
}
