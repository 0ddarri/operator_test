#include <iostream>

// 연산자 오버로딩
// 제공되는 연산자를 재정의해 클래스에서 사용하는 것

//아래 코드는 에러 발생, 컴퓨터는 저기의 + 연산자가 무엇을 의미하는지 모른다
// 원래 1+1 이런거 더했는데 (1,1) + (1,3) 마냥 2d벡터같은걸 더해서 모르는건가
#pragma region ErrorCode
namespace myop_Error
{
	class Point
	{
		int x;
		int y;

	public:
		Point (int a, int b)
		{
			x = a;
			y = b;
		}

		void Print()
		{
			std::cout << "x : " << x << " y : " << y;
		}
	};

	void Error()
	{
		Point p1 = { 1,1 };
		Point p2 = { 1,4 };

		Point p3 = p1 + p2;
		p3.Print();
	}
}
#pragma endregion

// 아래 코드는 에러 발생 X 연산자 오버로딩을 통해 + 연산 가능하도록 함
#pragma region CorrectCode
namespace myop
{
	class Point
	{
	private:
		int x;
		int y;
	public:
		Point (int a, int b)
		{
			x = a;
			y = b;
		}

		void Print()
		{
			std::cout << "x : " << x << " y : " << y;
		}

		Point operator + (Point& p) // + 연산자 오버로딩 / 해당 연산자를 사용할 변수의 자료형?이 Point이므로 반환형과 인자를 Point로 지정
		{
			x += p.x; // 기존 x에 뒤에 오는 인자 p의 x 더함
			y += p.y; // 기존 y에 뒤에 오는 인자 p의 y 더함
			return Point(x, y); // 해당 더한 값을 반환
		}
	};

	void Correct()
	{
		Point p1 = { 1,1 };
		Point p2 = { 1,4 };

		Point p3 = p1 + p2; // 연산자 오버로딩 되어서 더하기가 가능해짐, p3에 p1과 p2 더한 값 들어감
		//즉, x에 2 y에 5 들어감
		p3.Print();
	}
}
#pragma endregion


//실행할 때는 ErrorCode 내부 코드들을 주석처리하고 실행
int main()
{
	myop::Correct();
}