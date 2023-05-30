#include "ContactPlus.h"

void InitContact(struct ContactPlus* ps)
{
    ps -> data = (struct PeopleInfo*)malloc(3 * sizeof(struct PeopleInfo));

    if(ps -> data == NULL)
    {
        return;
    }

    ps -> size = 0;
    ps -> capacity = DEFAULT_SIZE;
}

int CheckCapacity(struct ContactPlus* ps)
{
        if(ps -> size == ps -> capacity)
        {
            //增容
            struct PeopleInfo* ptr = realloc(ps -> data,(ps -> capacity + 2) * sizeof(struct PeopleInfo));
            if(ptr != NULL)
            {
                ps -> data = ptr;
                ps -> capacity += 2;
                printf("扩容成功!\n");
                return 1;
            }else
            {
                printf("扩容失败!\n");
                return -1;
            }
        }else
            return 1;
}

void AddContact(struct ContactPlus* ps)
{
    int flag = CheckCapacity(ps);

    if(flag) {
        printf("请输入名字》》》\n");
        scanf("%s", ps->data[ps->size].name);
        printf("请输入电话》》》\n");
        scanf("%s", ps->data[ps->size].tel);
        printf("请输入性别》》》\n");
        scanf("%s", ps->data[ps->size].sex);
        printf("请输入地址》》》\n");
        scanf("%s", ps->data[ps->size].addr);
        printf("请输入年龄》》》\n");
        scanf("%d", &(ps->data[ps->size].age));

        ps->size++;
        printf("添加成功\n");
    }
}

void ShowContact(struct ContactPlus* ps)
{
    if(ps -> size == 0)
    {
        printf("通讯录为空\n");
    }else
    {
        int i = 0;

        printf("%-4s\t%-4s\t%-5s\t%-12s\t%-20s\n","名称","年龄","性别","电话","地址");

        for(i = 0;i < ps -> size;i++)
        {
            printf("%-4s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                   ps -> data[i].name,
                   ps -> data[i].age,
                   ps -> data[i].sex,
                   ps -> data[i].tel,
                   ps -> data[i].addr);
        }
    }
}

static int Find(struct ContactPlus* ps, char name[MAX_NAME])
{
    int position = 0;

    for(position = 0;position < ps -> size;position++)
    {
        if(0 == strcmp(ps -> data[position].name,name))
        {
            return position;
        }
    }

    if(position >= ps -> size)
    {
        printf("查无此人\n");
        return -1;
    }
}

void DeleteContact(struct ContactPlus* ps)
{

    if(ps -> size == 0)
    {
        printf("通讯录为空\n");
    }else
    {
        char name[MAX_NAME] = {0};
        printf("请输入被删除人的名字:");
        scanf("%s",name);

        int i = Find(ps,name);

        {
            for(int j = i;j < ps -> size - 1;j++)
            {
                ps -> data[j] = ps -> data[j + 1];
            }
            ps -> size--;
            printf("删除成功\n");
        }
    }
}

int Search(struct ContactPlus* ps)
{
    int i = 0;

    char name[MAX_NAME] = {0};
    printf("请输入想要查找的用户名字\n");
    scanf("%s",name);
    i = Find(ps,name);

    printf("%-4s\t%-4s\t%-5s\t%-12s\t%-20s\n","名称","年龄","性别","电话","地址");

        printf("%-4s\t%-4d\t%-5s\t%-12s\t%-20s\n",
               ps -> data[i].name,
               ps -> data[i].age,
               ps -> data[i].sex,
               ps -> data[i].tel,
               ps -> data[i].addr);
}

void Modify(struct ContactPlus* ps)
{
    char name[MAX_NAME] = {0};
    printf("请输入想要修改人的名字:\n");
    scanf("%s",name);

    int pos = Find(ps,name);

    if(pos != -1)
    {
        printf("请输入名字》》》\n");
        scanf("%s",ps -> data[pos].name);
        printf("请输入电话》》》\n");
        scanf("%s",ps -> data[pos].tel);
        printf("请输入性别》》》\n");
        scanf("%s",ps -> data[pos].sex);
        printf("请输入地址》》》\n");
        scanf("%s",ps -> data[pos].addr);
        printf("请输入年龄》》》\n");
        scanf("%d",&(ps -> data[pos].age));

        printf("修改成功\n");
    }
}

void DestroyContact(struct ContactPlus* ps)
{
    free(ps -> data);
    ps -> data = NULL;
}