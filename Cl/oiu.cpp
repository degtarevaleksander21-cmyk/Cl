#include <iostream>
#define max_length 30
typedef int solutionType[max_length];
typedef struct {
	solutionType solution;
	float energy;
}membertype;
#define initial_temp 30.0f
#define final_temp 0,5
#define alpha 0,98
#define steps_per_change 100
int getrand(int dia) {
	srand(time(NULL));
	int randNum = rand() % (dia)+1;
	return randNum;
}
static float getsrand() {
	float rnum = ((float)rand() / (float)(RAND_MAX)) * 1;
	return rnum;
}
void tweaksolution(membertype* member) {
	int temp, x, y;
	x = getrand(max_length);
	do {
		y = getrand(max_length);
	} while (x == y);
	temp = member->solution[x];
	member->solution[x] = member->solution[y];
	member->solution[y] = temp;
}
void initialisesolution(membertype* member) {
	int i;
	for (i = 0; i < max_length; i++)
		member->solution[i] = i;
	for (i = 0; i < max_length; i++)
		tweaksolution(member);
}
void compenergy(membertype* member) {
	int i, j, x, y, tempx, tempy;
	char board[max_length][max_length];
	int conflicts;
	const int dx[] = { -1, 1, -1, 1 };
	const int dy[] = { -1, 1, 1, -1 };
	memset((void*)board, 0, max_length * max_length);
	for (i = 0; i < max_length; i++) 
		board[i][member->solution[i]] = 'Q';
	conflicts = 0;
	for (i = 0; i < max_length; i++) {
		x = i; y = member->solution[i];
		for (j = 0; j < 4; j++) {
			tempx = x; tempy = y;
			while (1) {
				tempx += dx[j]; tempy += dy[j];
				if ((tempx < 0) || (tempx >= max_length) || 
					(tempy < 0) || (tempy >= max_length)) break;
				if (board[tempx][tempy] == 'Q') conflicts++;
			}
		}

	}
	member->energy = (float)conflicts;
}
void copysolution(membertype* dest, membertype* src) {
	int i;
	for (i = 0; i < max_length; i++)
		dest->solution[i] = src->solution[i];
	dest->energy = src->energy;
}
void emitsolution(membertype* member) {
	char board[max_length][max_length];
	int x, y;
	memset((void*)board, 0, max_length * max_length);
	for (x = 0; x < max_length; x++) 
		board[x][member->solution[x]] = 'Q';
	
	printf("board:\n");
	for (y = 0; y < max_length; y++) {
		for (x = 0; x < max_length; x++) {
			if (board[x][y] == 'Q') printf("Q");
			else printf(". ");
		}
		printf("\n");
	}
	printf("\n\n");
}

using namespace std;
int oiu() {
	int timer = 0, step, solution = 0, usenew, accepted;
	float temperature = initial_temp;
	membertype current, working, best;
	FILE* fp;
	fp = fopen("stats.txt", "W");
	srand(time(NULL));
	initialisesolution(&current);
	compenergy(&current);
	best.energy = 100.0f;
	copysolution(&working, &current);
	while (temperature > final_temp) {
		printf("Temperature : %f\n", temperature);
		accepted = 0;
		for (step = 0; step < steps_per_change; step++) {
			usenew = 0;
			tweaksolution(&working);
			compenergy(&working);
			if (working.energy <= current.energy) {
				usenew = 1;
			}
			else {
				float test = getsrand();
				float delta = working.energy - current.energy;
				float calc = exp(-delta / temperature);
				if (calc > test) {
					accepted++;
					usenew = 1;
				}
			}
			if (usenew) {
				usenew = 0;
				copysolution(&current, &working);
				if (current.energy < best.energy) {
					copysolution(&best, &current);
					solution = 1;
				}
			}
			else {
				copysolution(&working, &current);
			}

		}
		fprintf(fp, "%d %f %f %d/n",
			timer++, temperature, best.energy, accepted);
		printf("Best energy= %f\n", best.energy);
		temperature *= alpha;
	}
	fclose(fp);
	if (solution) {
		emitsolution(&best);
	}
	
	return 0;
}