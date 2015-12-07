public class IfLeapYear {

	public static void main(String[] args) {
		for(int year = 2000; year <= 2015; year++) {
			boolean yearTF = false;
			if(((year % 4) == 0 && (year % 100) != 0) || (year % 400) == 0) {
				yearTF = true;
			} else {
				yearTF = false;
			}

			if(yearTF) {
				System.out.println(year + "는 윤년입니다.");
			} else {
				System.out.println(year + "는 윤년이 아닙니다.");
			}
		} // for
	}
}