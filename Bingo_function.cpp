#include <iostream>
#include <time.h>

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER {
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

// �Լ��� ����� ���� �κ����� ���� �� �ִ�.
void SetNumber(int* pArray);
void Shuffle(int* pArray);
AI_MODE SelectAIMode();
void OutputNumber(int* pArray, int iBingo);
bool ChangeNumber(int* pArray, int iInput);
int SelectAINumber(int *pArray, AI_MODE eMode);
int BingoCounting(int* pArray);
int BingoCountingH(int* pArray);
int BingoCountingV(int* pArray);
int BingoCountingLTD(int* pArray);
int BingoCountingRTD(int* pArray);

int main() {
	srand((unsigned int)time(0));
	int iNumber[25] = { };
	int iAINumber[25] = { };

	SetNumber(iNumber);
	SetNumber(iAINumber);

	// ���ڸ� �����ش�.
	Shuffle(iNumber);
	Shuffle(iAINumber);

	int iBingo = 0, iAIBingo = 0;

	// AI ���̵��� �����Ѵ�.
	AI_MODE eAIMode = SelectAIMode();

	while (true) {
		system("cls");

		std::cout << "============ Player ============" << std::endl;
		OutputNumber(iNumber, iBingo);

		// AI ���� ���� ����Ѵ�.
		std::cout << "============ AI ============" << std::endl;

		switch (eAIMode)
		{
		case AM_EASY:
			std::cout << "AIMode : Easy" << std::endl;
			break;
		case AM_HARD:
			std::cout << "AIMode : Hard" << std::endl;
			break;
		}

		OutputNumber(iAINumber, iAIBingo);

		if (iBingo >= 5) {
			std::cout << "Player �¸�" << std::endl;
			break;
		}
		else if (iAIBingo >= 5) {
			std::cout << "AI �¸�" << std::endl;
			break;
		}

		std::cout << "���ڸ� �Է��Ͻÿ�(0 : ����) : ";
		int iInput;
		std::cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput > 25)
			continue;

		// �ߺ� �Է��� üũ�ϱ� ���� �����̴�. �⺻������ �ߺ��Ǿ��ٶ��
		// �ϱ� ���� true�� ����־���.
		bool bAcc = ChangeNumber(iNumber, iInput);

		// bAcc ������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *��
		// �ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue ���ش�.

		if (bAcc)
			continue;

		// �ߺ��� �ƴ϶�� AI�� ���ڵ� ã�Ƽ� *�� �ٲ��ش�.
		ChangeNumber(iAINumber, iInput);

		// AI�� ���ڸ� �����Ѵ�. AI��忡 ���缭 ���õǵ��� �Լ��� �����Ǿ� �ִ�.
		iInput = SelectAINumber(iAINumber, eAIMode);
		

		// AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٲ��ش�.
		ChangeNumber(iNumber, iInput);

		ChangeNumber(iAINumber, iInput);

		// ���� �� ���� üũ�ϴ°��� �Ź� ���ڸ� �Է��� ������ ó������
		// ���� ī��Ʈ�� �� ���̴�. �׷��Ƿ� iBingo ������ 0���� �Ź�
		// �ʱ�ȭ�ϰ� ���Ӱ� �� ���� �����ֵ��� �Ѵ�.
		iBingo = BingoCounting(iNumber);
		iAIBingo = BingoCounting(iAINumber);
	}
}

void SetNumber(int* pArray) {
	for (int i = 0; i < 25; ++i) {
		pArray[i] = i + 1;
	}
}

void Shuffle(int* pArray) {
	int temp, idx1, idx2;
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		temp = pArray[idx1];
		pArray[idx1] = pArray[idx2];
		pArray[idx2] = temp;
	}
}

AI_MODE SelectAIMode() {
	int iAIMode;
	while (true) {
		system("cls");
		std::cout << "1. Easy" << std::endl;
		std::cout << "2. Hard" << std::endl;
		std::cout << "AI ��带 �����ϼ��� : ";
		std::cin >> iAIMode;

		if (iAIMode >= AM_EASY || iAIMode <= AM_HARD)
			break;
	}

	return (AI_MODE)iAIMode;
}

void OutputNumber(int* pArray, int iBingo) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (pArray[i * 5 + j] == INT_MAX)
				std::cout << "*\t";

			else
				std::cout << pArray[i * 5 + j] << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << "Bingo Line : " << iBingo << std::endl << std::endl;
}

bool ChangeNumber(int* pArray, int iInput) {
	// ��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ�
		// �ִ����� ã�Ƴ���.
	for (int i = 0; i < 25; ++i) {
		// ���� ���ڰ� ���� ���
		if (iInput == pArray[i]) {
			// ���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ�
			// bAcc ������ false�� ������ش�.

			// ���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
			pArray[i] = INT_MAX;

			// �� �̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ�
			// for���� ����������.
			return false;
		}
	}

	// ������� ���� �Ǹ� return false�� ���� �ȵ� ���̹Ƿ� ���� ���ڰ�
	// ���ٴ� ���̴�. ��, �ߺ��� ���ڸ� �Է��߱� ������ true�� �����Ѵ�.
	return true;
}

int SelectAINumber(int* pArray, AI_MODE eMode) {
	// ���þȵ� ��� �迭�� ������ش�.
	int iNoneSelect[25] = { };
	// ���þȵ� ���� ������ �����Ѵ�.
	int iNoneSelectCount = 0;

	// AI�� ������ �Ѵ�. AI�� �����ϴ� ���� AI��忡 ���� �޶�����.
	switch (eMode) {
		/*
		AI Easy ���� ���� AI�� ���ڸ���� *�� �ٲ��� ���� ���� ����� ����
		�� ����� �ϳ��� �����ϰ� �Ѵ�.(�����ϰ�)
		*/
	case AM_EASY:
		// ���� �ȵ� ���� ����� ������ش�.
		// ���� �ȵ� ���� ������ ����� ���� �� ī���� ���ش�.
		iNoneSelectCount = 0;
		for (int i = 0; i < 25; ++i) {
			if (pArray[i] != INT_MAX) {
				// *�� �ƴ� ������ ��� iNoneSelectCount�� �ε����� Ȱ��
				// �Ѵ�. ���� �ȵ� ��Ͽ� �߰��� ������ ������ 1�� ����
				// ���Ѽ� �� ���þȵ� ������ �����ش�.
				// �׷��� 0���� ī��Ʈ�� �����̹Ƿ� 0���� �ְ� ++�ؼ� 1��
				// �߰��Ǿ��ٶ�� ���ش�.
				iNoneSelect[iNoneSelectCount] = pArray[i];
				++iNoneSelectCount;
			}
		}

		// for���� ���������� �Ǹ� ���� �ȵ� ����� ���������
		// ���� �ȵ� ����� ������ ��������� �ȴ�.
		// ���� �ȵ� ����� ������ ������ �ϳ��� ���ڸ� ������ ����
		// �ε����� �����ϰ� �����ش�.
		return iNoneSelect[rand() % iNoneSelectCount];

	case AM_HARD:
		// �ϵ���� ���� ������ ������ �ϼ� ���ɼ��� ���� ���� ����
		// ã�Ƽ� �� �ٿ� �ִ� ������ �ϳ��� *�� ������ش�.
		int iLine = 0;
		int iStarCount = 0;
		int iSaveCount = 0;

		// ���� ���� ���� �� ���� *�� ���� ���� ã�Ƴ���.
		for (int i = 0; i < 5; ++i) {
			iStarCount = 0;
			for (int j = 0; j < 5; ++j)
			{
				if (pArray[i * 5 + j] == INT_MAX)
					++iStarCount;
			}

			// ���� 5�� �̸��̾�� ���� ���� �ƴϰ� ������
			// ���� ���� ���� ���κ��� Ŀ�� ���� ���� ���� �����̹Ƿ�
			// ������ ��ü���ְ� ����� �� ���� ��ü�Ѵ�.
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				// ����� ���� ������ ���� ���� ���� ������ üũ�ϴ�
				// ���̴�. ���� ������ 0 ~ 4�� �ǹ̸� �ο��ߴ�.
				iLine = i;
				iSaveCount = iStarCount;
			}
		}

		// ���� ������ ���� ���� ���� ������ �̹� ���ߴ�.
		// �� ���� ���� ���ε��� ���Ͽ� ���� ���� ���� ������ ���Ѵ�.
		for (int i = 0; i < 5; ++i) {
			iStarCount = 0;
			for (int j = 0; j < 5; ++j) {
				if (pArray[j * 5 + i] == INT_MAX)
					++iStarCount;
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				// ���ζ����� 5 ~ 9�� �ǹ̸� �ο��ߴ�.
				iLine = i + 5;
				iSaveCount = iStarCount;
			}
		}

		// ���� -> ������ �밢�� üũ
		iStarCount = 0;
		for (int i = 0; i < 25; i += 6) {
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}

		if (iStarCount < 5 && iSaveCount < iStarCount) {
			iLine = LN_LT;
			iSaveCount = iStarCount;
		}

		// ������ -> ���� �밢�� üũ
		iStarCount = 0;
		for (int i = 4; i <= 20; i += 4) {
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}

		if (iStarCount < 5 && iSaveCount < iStarCount) {
			iLine = LN_RT;
			iSaveCount = iStarCount;
		}

		// ��� ������ ���������� iLine�� ���ɼ��� ���� ���� �� ��ȣ��
		// ����Ǿ���.
		// �� �ٿ� �ִ� *�� �ƴ� ������ �ϳ��� �����ϰ� �Ѵ�.
		// �������� ���
		if (iLine <= LN_H5) {
			// �������� ��� iLine�� 0 ~ 4 ������ ���̴�.
			for (int i = 0; i < 5; ++i) {
				// ���� �ٿ��� *�� �ƴ� ���ڸ� ã�Ƴ���.
				if (pArray[iLine * 5 + 1] != INT_MAX)
				{
					return pArray[iLine * 5 + i];
				}
			}
		}

		else if (iLine <= LN_V5) {
			// �������� ��� iLine�� 5 ~ 9 ������ ���̴�.
			for (int i = 0; i < 5; ++i) {
				if (pArray[i * 5 + (iLine - 5)] != INT_MAX) {
					return pArray[i * 5 + (iLine - 5)];
				}
			}
		}

		else if (iLine == LN_LT) {
			for (int i = 0; i < 25; i += 6) {
				if (pArray[i] != INT_MAX) {
					return pArray[i];
				}
			}
		}

		else if (iLine == LN_RT) {
			for (int i = 4; i <= 20; i += 4) {
				if (pArray[i] != INT_MAX) {
					return pArray[i];
				}
			}
		}
		break;
	}

	return -1;
}

int BingoCounting(int* pArray) {
	int iBingo = 0;

	// ������ üũ
	iBingo += BingoCountingH(pArray);
	// ������ üũ
	iBingo += BingoCountingV(pArray);
	// ���� ��� �밢�� üũ
	iBingo += BingoCountingLTD(pArray);
	// ������ ��� �밢�� üũ
	iBingo += BingoCountingRTD(pArray);

	return iBingo;
}

int BingoCountingH(int* pArray) {
	// ���� �� ���� �����ش�.
	int iStar1 = 0, iBingo = 0;

	for (int i = 0; i < 5; ++i) {
		// �� ���� üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
		iStar1 = 0;

		for (int j = 0; j < 5; ++j) {
			// ���� �� ������ �����ش�.
			if (pArray[i * 5 + j] == INT_MAX)
				++iStar1;
		}

		// j for���� ���������� ���� ���� ���� ���� �� ������ �����
		// iStar1 ������ ���� �ȴ�. iStar1�� ���� 5�� �� ����
		// ��� * �̶�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
		if (iStar1 == 5)
			++iBingo;
	}

	return iBingo;
}

int BingoCountingV(int* pArray) {
	// ���� �� ���� �����ش�.
	int iStar1 = 0, iBingo = 0;

	for (int i = 0; i < 5; ++i) {
		// �� ���� üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
		iStar1 = 0;

		for (int j = 0; j < 5; ++j) {
			// ���� �� ������ �����ش�.
			if (pArray[j * 5 + i] == INT_MAX)
				++iStar1;
		}

		// j for���� ���������� ���� ���� ���� ���� �� ������ �����
		// iStar1 ������ ���� �ȴ�. iStar1�� ���� 5�� �� ����
		// ��� * �̶�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.
		if (iStar1 == 5)
			++iBingo;
	}

	return iBingo;
}

int BingoCountingLTD(int* pArray) {
	// ���� ��� -> ������ �ϴ� �밢�� üũ
	int iStar1 = 0, iBingo = 0;

	for (int i = 0; i < 25; i += 6) {
		if (pArray[i] == INT_MAX)
			++iStar1;
	}
	if (iStar1 == 5)
		++iBingo;

	return iBingo;
}

int BingoCountingRTD(int* pArray) {
	// ������ ��� -> ���� �ϴ� �밢�� üũ
	int iStar1 = 0, iBingo = 0;

	for (int i = 4; i < 21; i += 4) {
		if (pArray[i] == INT_MAX)
			++iStar1;
	}
	if (iStar1 == 5)
		++iBingo;

	return iBingo;
}