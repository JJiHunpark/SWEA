#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int T, B, C;	// testcase, ���� ��, û�� �ð�
int calendar[4][15] = { 
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },	// 2013
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },	// 2014
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },	// 2015
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }	// 2016(����)
};

struct rsv {
	long long time;
	int use;
	rsv(long long time, int use) : time(time), use(use) {}
};

long long makeMinute(int Y, int M, int D, int h, int m) {
	long long year = (Y - 2013) * 365;
	long long day = D + year;
	for (int i = 1; i < M; i++) {
		day += calendar[Y - 2013][i];
	}
	long long minute = (day * 24 * 60) + (h * 60) + m;
	return minute;
}

bool comp(const rsv& r1, const rsv& r2) {
	if (r1.time != r2.time)
		return r1.time < r2.time;
	else
		return r1.use < r2.use;
}

int main()
{
	scanf_s("%d", &T);
	while (T--) {
		scanf_s("%d %d", &B, &C);
		vector<rsv> room;
		while (B--) {
			char code;
			int Y, M, D, h, m;
			scanf_s("%*s", &code);
			scanf_s("%d-%d-%d", &Y, &M, &D);
			scanf_s("%d:%d", &h, &m);
			rsv in(makeMinute(Y, M, D, h, m), 1);
			scanf_s("%d-%d-%d", &Y, &M, &D);
			scanf_s("%d:%d", &h, &m);
			rsv out(C + makeMinute(Y, M, D, h, m), 0);	// ��� �� û�ҽð� ����
			room.push_back(in);
			room.push_back(out);
		}
		sort(room.begin(), room.end(), comp);
		long long rst = 0, used = 0;
		for(int i=0; i < room.size(); i++){
			if (room[i].use) {
				used++;
				rst = max(rst, used);
			}
			else used--;
		}
		printf("%lld\n", rst);
	}
	return 0;
}

/*
- ���� �ڵ�� �ִ� 20����, ��¥�� 2013����� 2016�� ������ ���ุ
- �Է� : �׽�ũ ���̽� \n ���� �ڵ�, �Խ� �ð�, ��� �ð�
- ��� : �ʿ��� ���� �ּ� ����(���⿡ ����), 2016�⵵�� ����.

[����]
��¥�� ����ϱ� ���� �ϳ��� ���Ͻ����ִ°� ���� �� �ϴ�.
�켱 û�� �ð��� ������ �Ǿ������Ƿ� ��¥�� ������ ��ȯ.
������ �ð������� ����Ǵ� ���� �ƴϹǷ� �ð��� �����ϴ� ���� �ʿ�.
�ð��� �����ϴµ� ��-����� �з��ؾ��ϹǷ� ����ü�� ���.
����ü�� vector�� �װ� ����.
���ĵ� vector�� ���������� �����ϸ鼭 �Խ��� ��� ����, ����� ��� ����.

[�õ�]
1. �켱 ��¥�� ������ ��ȯ�ϰ�,
������ ��ȯ�� ��� ��¥(����� ��� û�� �ð� �߰�)�� ���� ��-��� ���θ� ����ü�� ����� ���Ϳ� ����.

2. ���Ϳ� ����� �ð��� ����,
���� �� �ð��� ���� ���� �Խ��� ���� ������ �����ϰ�, �ٸ� ���� ���� ���� ������ ����

3. ���ĵ� ���͸� ���������� ����. ��-��� ���θ� Ȯ���ϸ鼭 �Խ����� ��� used�� ���������ְ�,
������� ��� used�� ����. used�� �ᱹ 0�� ����� ���̹Ƿ�, ���� ������ max used�� ����

[�����]
��¥�� time.h ���̺귯���� ����ؼ� ������ ��ȯ�Ϸ��� �ߴµ�
scanf���� ���������ڿ� ���������� �־��ָ� �Է��� ��¥ ���Ŀ��� ���ڸ� ���� �� �ִٴ� ���� ���۸��ϴ� ��������.

sort�Լ��� �� ��° ���ڿ� �Լ��� ���� �� �ִµ�, �� �Լ��� �Ǵ��� "a�� b���� �տ� �� ����"�� ���� ������ ��迭 �Ѵ�.
�̰��� �Խ� �ð��� ��� �ð��� ���� ��츦 ������ ��, �а� ��-��ǿ� ���� �������־�� �ϴµ�, �� ��쿡 �����ߴ�.
*/