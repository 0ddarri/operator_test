#include <iostream>

// ������ �����ε�
// �����Ǵ� �����ڸ� �������� Ŭ�������� ����ϴ� ��

//�Ʒ� �ڵ�� ���� �߻�, ��ǻ�ʹ� ������ + �����ڰ� ������ �ǹ��ϴ��� �𸥴�
// ���� 1+1 �̷��� ���ߴµ� (1,1) + (1,3) ���� 2d���Ͱ����� ���ؼ� �𸣴°ǰ�
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

// �Ʒ� �ڵ�� ���� �߻� X ������ �����ε��� ���� + ���� �����ϵ��� ��
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

		Point operator + (Point& p) // + ������ �����ε� / �ش� �����ڸ� ����� ������ �ڷ���?�� Point�̹Ƿ� ��ȯ���� ���ڸ� Point�� ����
		{
			x += p.x; // ���� x�� �ڿ� ���� ���� p�� x ����
			y += p.y; // ���� y�� �ڿ� ���� ���� p�� y ����
			return Point(x, y); // �ش� ���� ���� ��ȯ
		}
	};

	void Correct()
	{
		Point p1 = { 1,1 };
		Point p2 = { 1,4 };

		Point p3 = p1 + p2; // ������ �����ε� �Ǿ ���ϱⰡ ��������, p3�� p1�� p2 ���� �� ��
		//��, x�� 2 y�� 5 ��
		p3.Print();
	}
}
#pragma endregion


//������ ���� ErrorCode ���� �ڵ���� �ּ�ó���ϰ� ����
int main()
{
	myop::Correct();
}