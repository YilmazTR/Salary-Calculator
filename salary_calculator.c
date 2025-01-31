#include <stdio.h>
#include <stdbool.h>

// Constants (adjust these as needed based on current Nova Scotia labor laws)
#define MINIMUM_WAGE 15.00 // Example: Replace with actual minimum wage
#define OVERTIME_RATE 1.5  // Usually 1.5 times the regular rate
#define STANDARD_WORK_WEEK 40 // Standard work week in hours

// Function to get valid hourly wage input
float getValidHourlyWage() {
    float hourlyWage;
    while (true) {
        printf("Enter your hourly wage (minimum $%.2f): $", MINIMUM_WAGE);
        if (scanf("%f", &hourlyWage) == 1 && hourlyWage >= MINIMUM_WAGE) {
            break;
        } else {
            printf("Invalid input. Please enter a number greater than or equal to the minimum wage.\n");
            // Clear the input buffer to prevent infinite loop
            while (getchar() != '\n'); 
        }
    }
    return hourlyWage;
}


// Function to get valid hours worked input
int getValidHoursWorked() {
    int hoursWorked;
    while (true) {
        printf("Enter the number of hours worked per week: ");
        if (scanf("%d", &hoursWorked) == 1 && hoursWorked > 0) {
            break;
        } else {
            printf("Invalid input. Please enter a positive integer number of hours.\n");
            while (getchar() != '\n'); // Clear buffer
        }
    }
    return hoursWorked;
}


// Function to calculate salary (now takes hoursWorked as an argument)
void calculateSalary(float hourlyWage, int hoursWorked) {
    float regularPay, overtimePay;

    if (hoursWorked <= STANDARD_WORK_WEEK) {
        regularPay = hourlyWage * hoursWorked;
        overtimePay = 0;
    } else {
        regularPay = hourlyWage * STANDARD_WORK_WEEK;
        overtimePay = hourlyWage * OVERTIME_RATE * (hoursWorked - STANDARD_WORK_WEEK);
    }

    float weeklySalary = regularPay + overtimePay;
    float monthlySalary = weeklySalary * 4; // Approximation (consider varying month lengths)
    float annualSalary = weeklySalary * 52;

    printf("\nSalary Breakdown:\n");
    printf("------------------------------------\n");
    printf("Hourly Wage: $%.2f\n", hourlyWage);
    printf("Hours Worked per Week: %d\n", hoursWorked);
    printf("Weekly Salary: $%.2f\n", weeklySalary);
    printf("Monthly Salary (approx.): $%.2f\n", monthlySalary);
    printf("Annual Salary: $%.2f\n", annualSalary);
    printf("------------------------------------\n");
}

int main() {
    float hourlyWage = getValidHourlyWage();
    int hoursWorked = getValidHoursWorked(); // Get hours worked

    calculateSalary(hourlyWage, hoursWorked); // Pass hoursWorked to the function

    return 0;
}
