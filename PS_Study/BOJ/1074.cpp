#include <cstdio>
#include <cmath>

using namespace std;

int N, r, c;

int S(int sz, int r, int c)
{
	int i, j;

	if (sz == 1)
		return 0;
	else
	{
		sz /= 2;	// �迭�� 4���

		// size * size �迭 ���� (r, c)�� 
		// (0,0) (0,1) (1,0) (1,1) �� ��� ��ġ���� Ž��
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 2; j++)
			{
				// size * size �迭 ���� (r, c) ��ġ�� �߰��ߴٸ�,
				// �ش� ��ǥ ���� size/2 * size/2 �迭�� Ž��
				if (r < (sz * (i + 1)) && c < (sz * (j + 1)))
					return (i * 2 + j) * sz * sz + S(sz, r - (sz * i), c - (sz * j));
			}
		}
	}

}

int main(void)
{
	scanf("%d %d %d", &N, &r, &c);

	printf("%d\n", S(pow(2, N), r, c));

	return 0;
}