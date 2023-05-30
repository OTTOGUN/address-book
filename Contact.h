#include<stdio.h>
#include<string.h>

#define MAX 100

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 12
#define MAX_ADDR 30

struct PeopleInfo
{
    char name[MAX_NAME];
    int age;
    char tel[MAX_TEL];
    char addr[MAX_ADDR];
    char sex[MAX_SEX];
};

//通讯录信息
struct Contact
{
    struct PeopleInfo data[MAX];
    int size;
};

void AddContact(struct Contact* ps);

void InitContact(struct Contact* ps);

void DeleteContact(struct Contact* ps);

void ShowContact(struct Contact* ps);

int Search(struct Contact* ps);

void Modify(struct Contact* ps);