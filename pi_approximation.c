/*****************************************************************************************************************/
/*												 	 'Pi' Approximation	     								     */
/*****************************************************************************************************************/

/*
 * Author:          Aly Khan Nuruddin
 * Date:            May 20, 2021
 *
 * Purpose:         This program implements the Monte Carlo Simulation Model as an estimation for the value of
 *					'Pi', to three decimal places.
 */

/*****************************************************************************************************************/

/* Note:			The approximation for 'Pi' becomes less accurate when enough points are not considered for the
 *					Monte Carlo Simulation Model. This is because when we have less number of points, uncertainty
 *					increases, which decreases the accuracy of our estimate. On thee contrary, when we have more
 *					number of points, uncertainty decreases, and the confidence in our approximation increases.
 */

/*****************************************************************************************************************/

#include <stdio.h>									// Include the standard input and output library in C.
#include <stdlib.h>									// Include the standard library in C.
#include <math.h>									// Include the standard math library in C.

int main(void)										// Define the function "main".
{
	int count_one = 1;								// Initialize "count_one" as a variable that keeps track of the number of points within the circle.
	int ratio_multiplier = 4;						// Initialize "ratio_multiplier" as a variable that multiplies with "area_ratio" to provide the apporximation for PI.
	int num_repititions = 1000;						// Initialize "num_repititions" as a variable that equals the total number of points within the square.

	float radius = 0.5;								// Initialize "radius" as a variable that equals half the length of the square.

	float distance;									// Define "distance" as a variable that stores the length from a point to the center of the circle.

	float area_ratio;								// Define "area_ratio" as a variable that stores the ratio of the area of the circle and the area of the square.
	float PI_approximation;							// Define "PI_approximation" as a variable that stores the estimated value of PI.

	float x_coordinate;								// Define "x_coordinate" as the randomly generated coordinate on the x-axis of the plot.
	float y_coordinate;								// Define "y_coordinate" as the randomly generated coordinate on the y-axis of the plot.

	printf("We assume that each side of the square, 'L', is 1 meter in length.");							// Let the user know that the length of the square is taken to be '1'.
	printf("\nThus, the coordinates for the center of the circle are (%lf, %lf).\n", radius, radius);		// Let the user know that the center point of the circle is (0.5, 0.5).

	for (int count_zero = 1; count_zero < num_repititions; count_zero++)									// Initialize "count_zero" as a variable that keeps track of the number of points in the square. Define the condition where the number of points is less than the total number of points in the square. Increment the number of points by 1.
	{
		x_coordinate = (float)rand() / (float)RAND_MAX;														// Randomly generate a value for the x-coordinate of the point.
		y_coordinate = (float)rand() / (float)RAND_MAX;														// Randomly generate a value for the y-coordinate of the point.

		printf("\nThe coordinates of the randomly generated point are (%f, %f).", x_coordinate, y_coordinate);	// Print the coordinates of the randomly generated point.

		distance = sqrt(((radius * x_coordinate) * (radius * x_coordinate)) + ((radius * y_coordinate) * (radius * x_coordinate))); // Calculate the distance from the point to the center of the circle.

		printf("\nThe distance from the center of the circle is %lf.\n", distance);							// Print the distance from the point to the center of the circle.

		if (distance < radius)																				// Define the condition where the distance is less than the radius.
		{
			count_one++;																					// Increment the number of points within the circle by 1.
			printf("\nThe randomly generated point is located within the circle.\n");						// Let the user know that the point is located within the circle.
		}

		else																								// Define the condition where the distance is greater than the radius.
		{
			printf("\nThe randomly generated point is not located within the circle.\n");					// Let the user know that the point is not located within the circle.
		}
	}

	area_ratio = (float)count_one / num_repititions;														// Compute the ratio of the areas of the circle and square.

	printf("\nThe ratio of the area of the circle and the area of the square is %d / %d .\n", count_one, num_repititions); // Print the ratio of the areas of the circle and square.

	PI_approximation = ratio_multiplier * area_ratio;														// Compute the approximation for the value of PI.

	printf("\nThe approximation for the value of PI is %f.\n\n", PI_approximation);							// Print the approximation for the value of PI.

	system("PAUSE");																						// Suspend the execution of the function "main".
	return 0;																								// Terminate the execution of the function "main".
}
