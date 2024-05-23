//==========================================================
//	構造体サンプル 分布グラフ
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf()
#include <stdlib.h> // srand(),rand()
#include <time.h>   // time()

typedef struct {
	int y;  // 西暦年
	int m;  // 月(1〜12)
	int d;  // 日(1〜31)
} Date;

// 関数プロトタイプ
Date DateOf(int year, int month, int day);
Date AfterDate(Date date, int days);
Date BeforeDate(Date date, int days);
int getDaysInYear(Date date);
Date getDateInYear(int year, int days);
char *getStringOf(Date date, char buff[]);
bool isLeapYear(int year);
int getRandRange(int min, int max);
int getMonthDays(int year, int month);
//void check(Date date, int val);

int MonthDays[][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31},
};

int main()
{
	const int BUFF_SIZE = 64;
	srand(time(NULL));

	int retry;
	char buff1[BUFF_SIZE];
	char buff2[BUFF_SIZE];
	char buff3[BUFF_SIZE];
	do {
		int year = getRandRange(1900, 2024);
		int month = getRandRange(1, 12);
		int day=getRandRange(1, getMonthDays(year,month));
		Date date = DateOf(year, month, day);

		int val = getRandRange(1, 100);
		Date after = AfterDate(date, val);
		Date before = BeforeDate(date, val);

		char* s1 = getStringOf(date, buff1);
		char* s2 = getStringOf(after, buff2);
		char* s3 = getStringOf(before, buff3);
		printf("%s の %d日後は %s\n", s1, val, s2);
		printf("%s の %d日前は %s\n", s1, val, s3);

		//check(date, val);

		printf("\nもう一度?(1:はい/0:いいえ)");
		scanf("%d", &retry);
	} while (retry == 1);
}

int getRandRange(int min, int max)
{
	int wid = max - min + 1;
	return min + rand() % wid;
}

Date DateOf(int year, int month, int day)
{
	Date date;
	date.y = year;
	date.m = month;
	date.d = day;
	return date;
}
Date BeforeDate(Date date, int subDays)
{
	int days = getDaysInYear(date) - subDays;
	return getDateInYear(date.y, days);
}
Date AfterDate(Date date, int addDays)
{
	int days = getDaysInYear(date) + addDays;
	return getDateInYear(date.y, days);
}

char* getStringOf(Date date,char buff[] )
{
	sprintf(buff, "%d年%2d月%2d日", date.y, date.m, date.d);
	return buff;
}

// Dateから経過日数を取得する
int getDaysInYear(Date date)
{
	int idx = isLeapYear(date.y);
	int days = date.d;
	for (int month = 1; month < date.m; month++) {
		days += MonthDays[idx][month - 1];
	}
	return days;
}
// 年と経過日数(<=0も可)からDateを取得する
Date getDateInYear(int year, int days)
{
	while (days <= 0) {
		year--;
		days += isLeapYear(year) ? 364 : 365;
	}

	int idx = isLeapYear(year) ? 1 : 0;
	int month = 1;
	while (days > MonthDays[idx][month - 1]) {
		days -= MonthDays[idx][month - 1];
		month++;
		if (month > 12){
			year++;
			idx = isLeapYear(year);
			month = 1;
		}
	}
	return DateOf(year, month, days);
}
// 年月からその月の日数を得る
int getMonthDays(int year, int month)
{
	int idx = isLeapYear(year) ? 1 : 0;
	return MonthDays[idx][month - 1];
}
// うるう年か?
bool isLeapYear(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

/*
#include <memory.h>
void check(Date date, int val)
{
	struct tm when = { 0 };
	when.tm_year = date.y - 1900;
	when.tm_mon = date.m - 1;
	when.tm_mday = date.d;

	time_t when_seconds = mktime(&when);

	time_t val_seconds = val * 24 * 60 * 60;
	time_t after_seconds = when_seconds + val_seconds;
	time_t before_seconds = when_seconds - val_seconds;

	struct tm after=when;
	struct tm before=when;
	errno_t err1,err2;
	do {
		err1 = localtime_s(&after, &after_seconds);
	} while (err1 != 0);
	do {
		err2 = localtime_s(&before, &before_seconds);
	} while (err2 != 0);

	const int BUFF_SIZE = 100;
	char buff1[BUFF_SIZE];
	char buff2[BUFF_SIZE];
	char buff3[BUFF_SIZE];
	strftime(buff1, BUFF_SIZE, "%Y/%m/%d", &when);
	strftime(buff2, BUFF_SIZE, "%Y/%m/%d", &after);
	strftime(buff3, BUFF_SIZE, "%Y/%m/%d", &before);

	printf("%s + %d => %s\n", buff1, val, buff2);
	printf("%s - %d => %s\n", buff1, val, buff3);
}
*/