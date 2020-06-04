#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int a[101], tmp[101];

void divide(int lt, int rt) {
	int mid;
	int p1, p2, p3;

	// ���� ��ȸ
	if (lt < rt) {
		mid = (lt + rt) / 2;

		/////////////////////////////
		// ���� ���� (Divide & Conquer)
		/////////////////////////////

		// ���� �ڽ� ��� ȣ��
		divide(lt, mid);

		// ������ �ڽ� ��� ȣ��
		divide(mid + 1, rt);

		/////////////////////////////
		// ���� (Combine)
		/////////////////////////////

		// �ڽ� ��� ȣ���� ��ģ �ڿ��� �θ� ����� ���� �۾�
		p1 = lt;
		p2 = mid + 1;
		p3 = lt;

		while (p1 <= mid && p2 <= rt) {
			if (a[p1] < a[p2]) tmp[p3++] = a[p1++];
			else tmp[p3++] = a[p2++];
		}

		// �������� �ʾƵ� �Ǿ��� ������ ���ҵ��� ���
		while (p1 <= mid) tmp[p3++] = a[p1++];
		while (p2 <= rt) tmp[p3++] = a[p2++];

		// tmp �� ����� ���ĵ� ���ҵ��� ������ ����
		for (int i = lt; i <= rt; i++)
			a[i] = tmp[i];
	}
}

int main() {
	int n, i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	divide(1, n);

	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);

	return 0;
}