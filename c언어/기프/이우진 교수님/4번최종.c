#include<stdio.h>

void main()
{
	char name[3][100];
	int score[3][3];
	char grade[3][3];
	int i, j, k, n;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grade[i][j] = 'A';

	for (i = 0; i < 3; i++)
		scanf("%s %d %d %d", &name[i][0], &score[i][0], &score[i][1], &score[i][2]);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k<3; k++)
				if (score[j][i]>score[k][i])
					grade[k][i]++;
		}
	}

	for (i = 0; i < 3; i++)
	{
		printf("%s: %d(%c) %d(%c) %d(%c)\n", name[i], score[i][0], grade[i][0], score[i][1], grade[i][1], score[i][2], grade[i][2]);
	}	
}