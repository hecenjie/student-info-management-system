#include "tools.h"

void WritePass()
{

    FILE *fp;
    int i;
    Password *p = password;


    if((fp = fopen("password.dat", "w+")) == NULL)
    {
        printf("打开文件失败，请按任意键退出！");
        getch();
        exit(1);
    }

    for(i = 0; i < countpass; i++, p++)
    {
        fprintf(fp, "%s %s\n", p->account, p->password);
    }

    fclose(fp);
}


void ReadPass()
{

    FILE *fp;
    int i;
    countpass = 0;
    Password *p = password;
    if((fp = fopen("password.dat", "r")) == NULL)
    {
        printf("打开文件失败，请按任意键退出！");
        getch();
        exit(1);
    }

    for(i = 0; i < 30; i++, p++)
    {

        fscanf(fp, "%s %s", p->account, p->password);
        if(p->account[0] != '\0' && p->password[0] != '\0')
            countpass++;
        else
            break;
    }
    p = password;
    printf("%d" ,countpass);
    /*for(i = 0; i < countpass; i++,p++)
    {

        printf("%s\t%s\n", p->account, p->password);
    }*/
    //getch();
    p = password;
    fclose(fp);

}
