#define NAME_SIZE 32
#include <iostream>

/*
����ü : �����ִ� �������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ������ִ� ����̴�.
��������� ���� Ÿ���̴�.
���� : struct ����ü �� {}; �� ���·� �����ȴ�. (����ü�� : ���ϴ� �̸�)
�迭�� ����ü�� ������ : 
1. ������ �����̴�.
2. ���ӵ� �޸� ���� �Ҵ�ȴ�. ����ü ������� ���ӵ� �޸� ������
������ �ȴ�.
*/
struct _tagStudent {
	char	strName[NAME_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

int main() {
	_tagStudent tStudent;
	_tagStudent tStudentArr[100];

	// ����ü ����� ������ ���� .�� �̿��ؼ� �����ϰ� �ȴ�.
	tStudent.iKor = 100;

	// tStudent.strName = "aasdfjkl";
	// ���ڿ��� �迭�� �־��� ������ �ܼ� �������δ� �Ұ����ϴ�.
	// strcpy_s ��� �Լ��� �̿��ؼ� ���ڿ��� ������ �־�� �Ѵ�.
	// �� �Լ��� �����ʿ� �ִ� ���ڿ��� �������� �������ش�.

	strcpy_s(tStudent.strName,"�����ٶ� asdf");

	// strcat_s �Լ��� ���ڿ��� �ٿ��ִ� ����̴�.
	// �����ʿ� �ִ� ���ڿ��� ���ʿ� �ٿ��ش�. strName���� ������
	// �����ٶ� asdf�� ������ �ξ��� ������ �� �ڿ� ������ ���ڿ���
	// �ٿ��� ������ش�.
	strcat_s(tStudent.strName, " ���ڿ� ���̱�");

	// strcmp �Լ��� �� ���ڿ��� ���Ͽ� ���� ��� 0�� ��ȯ�ϰ�
	// �ٸ� ��� 0�� �ƴ� ���� ��ȯ�Ѵ�.
	strcpy_s(tStudent.strName, "ȫ�浿");

	std::cout << "���� �̸��� �Է��ϼ��� : ";
	char	strName[NAME_SIZE] = {};
	std::cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0) {
		std::cout << "�л��� ã�ҽ��ϴ�." << std::endl;
	}

	else
		std::cout << "ã�� �л��� �����ϴ�." << std::endl;



	std::cout << "�̸� ���� : " << strlen(tStudent.strName) << std::endl;

	// ���ڿ��� ���� �׻� 0(NULL)�� ������ �Ѵ�.
	// �׷��� ������ ���� �� �ִ� ���¿��� �Ʒ�ó�� �� �迭 ��ҿ�
	// ���� �־��ְ� �Ǹ� �� ���� ��µǰ� �־����� ���� �κ���
	// ������ ������ �״�� ��µȴ�. �ֳ��ϸ� ����� �� ���ڿ��� ����
	// �ν��� �� ���� �����̴�. 0(NULL)�� ���� �ϴµ� ������ ����
	// �� �ֱ� �����̴�.
	//tStudent.strName[0] = 'a';
	//tStudent.strName[1] = 'b';
	//tStudent.strName[2] = 0;

	std::cout << "�̸� : " << tStudent.strName << std::endl;
	std::cout << "�й� : " << tStudent.iNumber << std::endl;
	std::cout << "���� : " << tStudent.iKor << std::endl;
	std::cout << "���� : " << tStudent.iEng << std::endl;
	std::cout << "���� : " << tStudent.iMath << std::endl;
	std::cout << "���� : " << tStudent.iTotal << std::endl;
	std::cout << "��� : " << tStudent.fAvg << std::endl;
}