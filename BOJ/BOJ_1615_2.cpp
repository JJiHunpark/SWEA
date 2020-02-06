#include <iostream>
#include <vector>

using namespace std;

int N, M;	// node, edge
vector<int> edge;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int m = M;

	// edge�� ������ vector�� ����
	while (m--) {
		int e1, e2;
		cin >> e1 >> e2;

		edge.push_back(e2);
	}

	// insert sort
	int rst = 0;
	for (unsigned int i = 1; i < edge.size(); i++) {
		int key = edge[i], j = i - 1;
		while (j >= 0 && key < edge[j]) {
			edge[j + 1] = edge[j];
			j--; rst++;
		}
		edge[j + 1] = key;
	}

	cout << rst << '\n';

	return 0;
}

/*
- A1<A2, B1>B2 �Ǵ� A1>A2, B1<B2�� �����Ѵٸ� �� ������ ����

[����]
����Ž���� �ؾ��ϴµ� �ܼ��ϰ� Ǯ��� �ð��ʰ��� �߻��ϹǷ�,
����ȭ�� ����� �ʿ��� �� �ϴ�.

[�õ�]
1.���� Ž������ ����
- ������ �����͸� vector�� ����
- vector�� �����͸� ���������� Ž��
- �ð� �ʰ�.. O(N^2)

2. ���������� �� Ƚ���� Ȱ���Ͽ� ������� ���� �� �ִٴ� ���� �˾Ƴ�����,
- �ð� �ʰ�.. ���� ���ĵ� �־��� ��Ȳ�� O(N^2)

3. ���׸�Ʈ Ʈ��

[�����]
*/