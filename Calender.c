// Created by Chris Tien
#include <stdio.h> 

// 函數返回日期DD/MM/YYYY的星期索引
int dayNumber(int day, int month, int year) 
{ 
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                    5, 1, 4, 6, 2, 4 }; 
    year -= month < 3; 
    return (year + year / 4 
            - year / 100 
            + year / 400 
            + t[month - 1] + day) 
        % 7; 
} 

// 函數返回給定月份編號的月份名稱，一月為0，二月為1，以此類推
char* getMonthName(int monthNumber) 
{ 
    char* month; 

	switch (monthNumber) { 
	case 0: 
		month = "January"; 
		break; 
	case 1: 
		month = "February"; 
		break; 
	case 2: 
		month = "March"; 
		break; 
	case 3: 
		month = "April"; 
		break; 
	case 4: 
		month = "May"; 
		break; 
	case 5: 
		month = "June"; 
		break; 
	case 6: 
		month = "July"; 
		break; 
	case 7: 
		month = "August"; 
		break; 
	case 8: 
		month = "September"; 
		break; 
	case 9: 
		month = "October"; 
		break; 
	case 10: 
		month = "November"; 
		break; 
	case 11: 
		month = "December"; 
		break; 
	} 
	return month; 
} 

// 函數返回一個月的天數
int numberOfDays(int monthNumber, int year) 
{ 
	// January 
	if (monthNumber == 0) 
		return (31); 

	// February 
	if (monthNumber == 1) { 
		// 如果年份是閏年，則二月擁有29天
		if (year % 400 == 0 
			|| (year % 4 == 0 
				&& year % 100 != 0)) 
			return (29); 
		else
			return (28); 
	} 

	// March 
	if (monthNumber == 2) 
		return (31); 

	// April 
	if (monthNumber == 3) 
		return (30); 

	// May 
	if (monthNumber == 4) 
		return (31); 

	// June 
	if (monthNumber == 5) 
		return (30); 

	// July 
	if (monthNumber == 6) 
		return (31); 

	// August 
	if (monthNumber == 7) 
		return (31); 

	// September 
	if (monthNumber == 8) 
		return (30); 

	// October 
	if (monthNumber == 9) 
		return (31); 

	// November 
	if (monthNumber == 10) 
		return (30); 

	// December 
	if (monthNumber == 11) 
		return (31); 
} 


// 打印給定年份的日曆
void printCalendar(int year) 
{ 
	printf("	 Calendar - %d\n\n", year); 
    int days; 

    // 星期索引從0到6
    int current = dayNumber(1, 1, year); 

    // i用於迭代月份
    // j用於迭代月份的天數 - i
    for (int i = 0; i < 12; i++) { 
        days = numberOfDays(i, year); 

        // 打印當前月份名稱
        printf("\n ------------%s-------------\n", 
            getMonthName(i)); 

        // 打印列
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");  

        // 打印適當的空格
        int k; 
        for (k = 0; k < current; k++) 
            printf("     "); 

        for (int j = 1; j <= days; j++) { 
            printf("%5d", j); 

            if (++k > 6) { 
                k = 0; 
                printf("\n"); 
            } 
        } 

        if (k) 
            printf("\n"); 

        current = k; 
    } 

    return; 
} 

// 主函數
int main() 
{ 
    int year = 2024; 

    // 函數調用
    printCalendar(year); 
    return 0; 
} 
