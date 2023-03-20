/*
Входные файлы
Файл Студенты.txt
Номер_счета Фамилия Имя Отчество Группа
1 Куделя Никита Ильич 22ИС-21
2 Захаров Богдан Сергеевич 25ИС-21
3 Лепихов Михаил Владимирович 22ИС-21

Файл Выплаты.txt
Номер_счета Дата Сумма
1 28.01.2023 700
2 28.01.2023 700
3 28.01.2023 800
2 28.02.2023 700
1 28.01.2023 700

--------------

Выходной
Файл Сводный.txt
Ведомость на получение стипендии от 17 марта 2023 года
Номер п.п. Номер_счета ФИО Группа Сумма
1. 1 Куделя Н.И. 22ИС-21 1400
2. 3 Лепихов М.В. 22ИС-21 800
3. 2 Захаров Б.С. 25ИС-21 1400

Всего 3600 Три тысячи шестьсот рублей 00 коп.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int num;
    char surname[20];
    char name[20];
    char patronymic[20];
    char group[10];
};

struct payment {
    int num;
    char date[20];
    int sum;
};

int main() {
    FILE *fstudents = fopen("student.txt", "r");
    FILE *fpayments = fopen("payments.txt", "r");
    FILE *foutput = fopen("output.txt", "w");

    if (fstudents == NULL) {
        printf("Ошибка открытия файла Студенты.txt");
        return 1;
    }
    if (fpayments == NULL) {
        printf("Ошибка открытия файла Выплаты.txt");
        return 1;
    }
    if (foutput == NULL) {
        printf("Ошибка создания файла Сводный.txt");
        return 1;
    }

    struct student students[100];
    int num_students = 0;

    while (!feof(fstudents)) {
        fscanf(fstudents, "%d %s %s %s %s", &students[num_students].num, 
            students[num_students].surname, students[num_students].name, 
            students[num_students].patronymic, students[num_students].group);
        num_students++;
    }

    struct payment payments[100];
    int num_payments = 0;

    while (!feof(fpayments)) {
        fscanf(fpayments, "%d %s %d", &payments[num_payments].num, 
            payments[num_payments].date, &payments[num_payments].sum);
        num_payments++;
    }

    char date[20];
    int sum;
    printf("Введите дату в формате ДД.ММ.ГГГГ: ");
    scanf("%s", date);
    printf("Введите сумму: ");
    scanf("%d", &sum);

    fprintf(foutput, "Ведомость на получение стипендии от %s\n", date);
    fprintf(foutput, "Номер п.п. Номер_счета ФИО Группа Сумма\n");

    for (int i = 0; i < num_payments; i++) {
        if (strcmp(payments[i].date, date) == 0 && payments[i].sum == sum) {
            for (int j = 0; j < num_students; j++) {
                if (students[j].num == payments[i].num) {
                    fprintf(foutput, "%-8d %-12d %-20s %-7s %d\n", i+1, 
                        students[j].num, strcat(strcat(strcat(students[j].surname, " "),
                        students[j].name), students[j].patronymic), students[j].group,
                        payments[i].sum);
                    break;
                }
            }
        }
    }

    fclose(fstudents);
    fclose(fpayments);
    fclose(foutput);

    return 0;
}