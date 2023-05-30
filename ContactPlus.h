#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define MAX 100

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 12
#define MAX_ADDR 30
#define DEFAULT_SIZE 3

struct PeopleInfo
{
    char name[MAX_NAME];
    int age;
    char tel[MAX_TEL];
    char addr[MAX_ADDR];
    char sex[MAX_SEX];
};

//通讯录信息
struct ContactPlus
{
    struct PeopleInfo *data;
    int size;
    int capacity;
};

void AddContact(struct ContactPlus* ps);

void InitContact(struct ContactPlus* ps);

void DeleteContact(struct ContactPlus* ps);

void ShowContact(struct ContactPlus* ps);

int Search(struct ContactPlus* ps);

void Modify(struct ContactPlus* ps);

void DestroyContact(struct ContactPlus* ps);