#include "Contact.h"

void menu()
{
    printf("*********************************\n");
    printf("**************1. Add*************\n");
    printf("**************2. Delete**********\n");
    printf("**************3. Mod*************\n");
    printf("**************4. Search**********\n");
    printf("**************5. Show************\n");
    printf("**************0. Exit************\n");
    printf("*********************************\n");
}

int main()
{
    int input = 0;
    //����ͨѶ¼
    struct Contact con;;

    //��ʼ��ͨѶ¼
    InitContact(&con);
    do{
        menu();
        printf("��ѡ�������Ŀ\n");
        scanf("%d",&input);
        switch(input)
        {
            case 0:
                break;
            case 1:
                AddContact(&con);
                break;
            case 2:
                DeleteContact(&con);
                break;
            case 3:
                Modify(&con);
                break;
            case 4:
                Search(&con);
                break;
            case 5:
                ShowContact(&con);
                break;
        }
    }while(input);
}