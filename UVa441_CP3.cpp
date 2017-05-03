/*
 * In the German Lotto you have to select 6 numbers from the set {1,2,...,49}. A popular strategy to
play Lotto - although it doesn’t increase your chance of winning — is to select a subset S containing
k (k > 6) of these 49 numbers, and then play several games with choosing numbers only from S.
For example, for k = 8 and S = {1, 2, 3, 5, 8, 13, 21, 34} there are 28 possible games: [1,2,3,5,8,13],
[1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34].
Your job is to write a program that reads in the number k and the set S and then prints all possible
games choosing numbers only from S.
 *
 */

#include <cstdio>
using namespace std;

int main() {
	int k, S[12], count = 0;
	while (scanf("%d", &k), k) {
		if (count++)
			printf("\n");
		for (int i = 0; i < k; i++)
			scanf("%d", &S[i]);

		for (int a = 0; a < k - 5; a++)
			for (int b = a + 1; b < k - 4; b++)
				for (int c = b + 1; c < k - 3; c++)
					for (int d = c + 1; d < k - 2; d++)
						for (int e = d + 1; e < k - 1; e++)
							for (int f = e + 1; f < k; f++)
								printf("%d %d %d %d %d %d\n", S[a], S[b], S[c],
										S[d], S[e], S[f]);
	}

	return 0;
}
