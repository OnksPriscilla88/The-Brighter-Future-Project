#include "brighterfuture.h"

#define MAX_GAP 500
#define MIN_GAP 10

int main()
{
	//Declarations
	int lower_age, upper_age, gap;
	double progress;

	//Read in boundaries
	printf("Please enter the lower age boundary: \n");
	scanf("%d", &lower_age);
	printf("Please enter the upper age boundary: \n");
	scanf("%d", &upper_age);

	//Calculate progress by age group
	for (int i = lower_age; i <= upper_age; i += gap)
	{
		if (i + MAX_GAP <= upper_age)
			gap = MAX_GAP;
		else
			gap = MIN_GAP;

		progress = brighterFutureByGroup(i, i + gap);
		printf("Progress within the age group of %d to %d is %g.\n", i, i + gap, progress);
	}

	return 0;
}

double brighterFutureByGroup(int lower_bound, int upper_bound) 
{
	//Declarations
	int count = 0;
	double success = 0;
	double total = 0;

	//Get data from files
	FILE *fp;
	fp = fopen("brighterFutureData.csv", "r");

	int age;
	double success_rate;

	//Loop through the file and calculate the data
	while (fscanf(fp, "%d,%lf", &age, &success_rate) == 2)
	{
		if (age >= lower_bound && age <= upper_bound)
		{
			success += success_rate;
			count++;
		}
	}

	//Calculate the progress for the given age group
	total = success / count;

	fclose(fp);

	return total;
}